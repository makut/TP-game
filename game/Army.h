# pragma once
# include "Unit.h"
# include <memory>
# include <iostream>
# include <vector>

template<int LEVEL>
class ArmyUnit;

class IArmyPrinter
{
public:
    virtual void printSoldier(ArmyUnit<0>*) = 0;
    virtual void printCompany(ArmyUnit<1>*) = 0;
    virtual void printBattalion(ArmyUnit<2>*) = 0;
    virtual void printArmy(ArmyUnit<3>*) = 0;
    virtual void useIndent(int ind) = 0;
    virtual void reset() = 0;

    virtual ~IArmyPrinter() = default;
};

template<int LEVEL>
class ArmyUnit : public std::enable_shared_from_this<ArmyUnit<LEVEL> >
{
public:
    template<int LEVEL1>
    friend class ArmyUnit;

    ArmyUnit() : power_(0), money_(0), pr_() {}
    ArmyUnit(const ArmyUnit &other):
        consist_(other.consist_), pr_(other.pr_)
    {
        power_ = 0;
        money_ = 0;
        for (size_t i = 0; i < consist_.size(); i++)
        {
            power_ += consist_[i]->getPower();
            money_ += consist_[i]->getMoney();
        }
    }
    ArmyUnit(ArmyUnit&& other) : consist_(std::move(other.consist_)), pr_(std::move(other.pr_))
    {
        power_ = 0;
        money_ = 0;
        for (size_t i = 0; i < consist_.size(); i++)
        {
            power_ += consist_[i]->getPower();
            money_ += consist_[i]->getMoney();
        }
    }
    ~ArmyUnit() = default;

    void setPrev(const std::weak_ptr<ArmyUnit<LEVEL + 1> > &pr)
    {
        pr_ = pr;
    }

    void addUnit(const std::shared_ptr<ArmyUnit<LEVEL - 1> > &other)
    {
        consist_.push_back(other);
        other->setPrev(this->shared_from_this());
        power_ += other->getPower();
        money_ += other->getMoney();
    }

    size_t getSubArmiesNum() const
    {
        size_t ans = 1;
        for (auto ch : consist_)
            ans += ch->getSubArmiesNum();
        return ans;
    }

    size_t getSize() const
    {
        return consist_.size();
    }

    long long getPower() const
    {
        return power_;
    }

    long long getMoney() const
    {
        return money_;
    }

    void addMoney(long long add)
    {
        long long old_value = money_;
        increaseChildren_(add);
        if (pr_.lock() != nullptr)
            pr_.lock()->increaseMoney_(money_ - old_value);
    }

    void output(const std::shared_ptr<IArmyPrinter> &army_printer);

    template<int INDENT = 0>
    void show(const std::shared_ptr<IArmyPrinter> &army_printer)
    {
        army_printer->useIndent(INDENT);
        output(army_printer);
        for (std::shared_ptr<ArmyUnit<LEVEL - 1> > ch : consist_)
            ch->template show<INDENT + 2>(army_printer);
    }
private:
    std::vector<std::shared_ptr<ArmyUnit<LEVEL - 1> > > consist_;
    std::weak_ptr<ArmyUnit<LEVEL + 1> > pr_;
    long long power_, money_;

    void increaseChildren_(long long add)
    {
        long long new_val = 0;
        for (size_t i = 0; i < consist_.size(); i++)
        {
            consist_[i]->increaseChildren_(add);
            new_val += consist_[i]->getMoney();
        }
        money_ = new_val;
    }

    void increaseMoney_(long long add)
    {
        money_ = std::max<long long>(0, money_ + add);
        if (pr_.lock() != nullptr)
            pr_.lock()->increaseMoney_(add);
    }
};

template<>
class ArmyUnit<10>
{
public:
    void increaseChildren_(long long add) {}
    void increaseMoney_(long long add) {}
};

template<>
class ArmyUnit<0> : public std::enable_shared_from_this<ArmyUnit<0> >
{
public:
    template<int LEVEL>
    friend class ArmyUnit;

    explicit ArmyUnit(const std::shared_ptr<Unit> &unit, const std::shared_ptr<ArmyUnit<1> > pr = nullptr):
        unit_(unit), pr_(pr), money_(DEFAULT_MONEY) {}

    ~ArmyUnit() = default;

    long long getPower() const
    {
        return unit_->getPower();
    }

    std::shared_ptr<ArmyUnit<0> > clone() const
    {
        return std::shared_ptr<ArmyUnit<0> >(new ArmyUnit<0>(unit_->clone()));
    }

    void setPrev(const std::weak_ptr<ArmyUnit<1> > &pr)
    {
        pr_ = pr;
    }

    void addMoney(long long add)
    {
        long long old_value = money_;
        increaseChildren_(add);
        if (pr_.lock() != nullptr)
            pr_.lock()->increaseMoney_(money_ - old_value);
    }

    long long getMoney() const
    {
        return money_;
    }

    std::string getName() const
    {
        return unit_->getName();
    }

    size_t getSubArmiesNum() const
    {
        return 1;
    }

    void output(const std::shared_ptr<IArmyPrinter> &army_printer)
    {
        army_printer->printSoldier(this);
    }

    template<int INDENT = 0>
    void show(const std::shared_ptr<IArmyPrinter> &army_printer)
    {
        army_printer->useIndent(INDENT);
        output(army_printer);
    }

    static const long long DEFAULT_MONEY = 1000;
private:
    std::shared_ptr<Unit> unit_;
    std::weak_ptr<ArmyUnit<1> > pr_;
    long long money_;

    void increaseChildren_(long long add)
    {
        money_ = std::max<long long>(0, money_ + add);
    }
};

using Soldier = ArmyUnit<0>;
using Company = ArmyUnit<1>;
using Battalion = ArmyUnit<2>;
using Army = ArmyUnit<3>;

enum Winner
{
    FIRST, SECOND, DRAW
};

template<int LEVEL1, int LEVEL2>
class Battle
{
public:
    Battle(const Battle&) = default;

    Battle(ArmyUnit<LEVEL1> *first,
           ArmyUnit<LEVEL2> *second):
        first_(first), second_(second) {}

    Winner executeBattle() const
    {
        if (first_->getPower() == second_->getPower())
            return DRAW;
        return (first_->getPower() > second_->getPower() ? FIRST : SECOND);
    }

    ArmyUnit<LEVEL1>* getFirst() const
    {
        return first_;
    }

    ArmyUnit<LEVEL2>* getSecond() const
    {
        return second_;
    }
    constexpr static const int level1 = LEVEL1;
    constexpr static const int level2 = LEVEL2;
private:
    ArmyUnit<LEVEL1> *first_;
    ArmyUnit<LEVEL2> *second_;
};

class NullBuffer : public std::streambuf
{
public:
    int overflow(int c)
    {
        return c;
    }
};