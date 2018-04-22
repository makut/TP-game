# pragma once
# include "Unit.h"
# include <memory>
# include <iostream>
# include <vector>

template<int LEVEL>
class ArmyUnit
{
public:
    ArmyUnit() : power_(0), money_(0) {}
    ArmyUnit(const ArmyUnit &other) : consist_(other.consist_)
    {
        power_ = 0;
        money_ = 0;
        for (size_t i = 0; i < consist_.size(); i++)
        {
            power_ += consist_[i].getPower();
            money_ += consist_[i].getMoney();
        }
    }
    ArmyUnit(ArmyUnit&& other) : consist_(std::move(other.consist_))
    {
        power_ = 0;
        money_ = 0;
        for (size_t i = 0; i < consist_.size(); i++)
        {
            power_ += consist_[i].getPower();
            money_ += consist_[i].getMoney();
        }
    }
    ~ArmyUnit() = default;

    void addUnit(const std::shared_ptr<ArmyUnit<LEVEL - 1> > &other)
    {
        consist_.push_back(other);
        power_ += other->getPower();
        money_ += other->getMoney();
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
        money_ = std::max<long long>(0, money_ + add * consist_.size());
        for (size_t i = 0; i < consist_.size(); i++)
        {
            consist_[i]->addMoney(add);
        }
    }
private:
    std::vector<std::shared_ptr<ArmyUnit<LEVEL - 1> > > consist_;
    long long power_, money_;
};

template<>
class ArmyUnit<0>
{
public:
    explicit ArmyUnit(const std::shared_ptr<Unit> &unit):
        unit_(unit), money_(DEFAULT_MONEY) {}

    long long getPower() const
    {
        return unit_->getPower();
    }

    std::shared_ptr<ArmyUnit<0> > clone() const
    {
        return std::shared_ptr<ArmyUnit<0> >(new ArmyUnit<0>(unit_->clone()));
    }

    void addMoney(long long add)
    {
        money_ = std::max<long long>(0, money_ + add);
    }

    long long getMoney() const
    {
        return money_;
    }

    static const long long DEFAULT_MONEY = 1000;
private:
    std::shared_ptr<Unit> unit_;
    long long money_;
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

    Battle(const std::shared_ptr<ArmyUnit<LEVEL1> > &first,
           const std::shared_ptr<ArmyUnit<LEVEL2> > &second):
        first_(first), second_(second) {}

    Winner executeBattle() const
    {
        if (first_->getPower() == second_->getPower())
            return DRAW;
        return (first_->getPower() > second_->getPower() ? FIRST : SECOND);
    }

    std::shared_ptr<ArmyUnit<LEVEL1> > getFirst() const
    {
        return first_;
    }

    std::shared_ptr<ArmyUnit<LEVEL2> > getSecond() const
    {
        return second_;
    }
    static const int level1 = LEVEL1;
    static const int level2 = LEVEL2;
private:
    std::shared_ptr<ArmyUnit<LEVEL1> > first_;
    std::shared_ptr<ArmyUnit<LEVEL2> > second_;
};
