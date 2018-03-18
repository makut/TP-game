# pragma once
# include "Unit.h"

class AbstractRankBuilder
{
protected:
    AbstractRankBuilder();
    Health health_;
    Armor armor_;
public:
    virtual ~AbstractRankBuilder() = 0;

    virtual void reset() = 0;
    void setHealth(Health);
    void setArmor(const Armor&);
    virtual std::shared_ptr<Unit> getResult() const = 0;
};

class WarriorBuilder : public AbstractRankBuilder
{
public:
    WarriorBuilder();
    ~WarriorBuilder() = default;

    virtual void reset() override;
    void setSword(const Sword&);
    virtual std::shared_ptr<Unit> getResult() const override;
private:
    Sword sword_;
};

class ArcherBuilder : public AbstractRankBuilder
{
public:
    ArcherBuilder();
    ~ArcherBuilder() = default;

    virtual void reset() override;
    void setBow(const Bow&);
    virtual std::shared_ptr<Unit> getResult() const override;
private:
    Bow bow_;
};

class DoctorBuilder : public AbstractRankBuilder
{
public:
    DoctorBuilder();
    ~DoctorBuilder() = default;

    virtual void reset() override;
    void setHealing(const Healing&);
    virtual std::shared_ptr<Unit> getResult() const override;
private:
    Healing heal_;
};