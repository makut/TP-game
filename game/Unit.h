# pragma once
# include "Game.h"
# include "Objects.h"

class Unit
{
public:
    explicit Unit(const std::shared_ptr<const Unit>&);
    virtual ~Unit() = 0;
    virtual std::shared_ptr<Unit> clone() const = 0;
    static const Health MAX_HEALTH;
private:
    Health health_;
    Armor armor_;
};

class Warrior : public Unit
{
public:
    explicit Warrior(const std::shared_ptr<const Warrior>&);
    virtual ~Warrior() = 0;
    virtual std::shared_ptr<Unit> clone() const = 0;
private:
    Sword sword_;
};

class Archer : public Unit
{
public:
    explicit Archer(const std::shared_ptr<const Archer>&);
    virtual ~Archer() = 0;
    virtual std::shared_ptr<Unit> clone() const = 0;
private:
    Bow bow_;
};

class Doctor : public Unit
{
public:
    explicit Doctor(const std::shared_ptr<const Doctor>&);
    virtual ~Doctor() = 0;
    virtual std::shared_ptr<Unit> clone() const = 0;
private:
    Healing heal_;
};