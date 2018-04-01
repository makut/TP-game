# pragma once
# include <memory>
# include "Objects.h"

class WarriorBuilder;
class ArcherBuilder;
class DoctorBuilder;

class Unit
{
protected:
    Unit(Health, const Armor&);
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
    virtual ~Warrior() = default;
    virtual std::shared_ptr<Unit> clone() const;

    friend WarriorBuilder;
private:
    Warrior(Health, const Armor&, const Sword&);

    Sword sword_;
};

class Archer : public Unit
{
public:
    explicit Archer(const std::shared_ptr<const Archer>&);
    virtual ~Archer() = default;
    virtual std::shared_ptr<Unit> clone() const;

    friend ArcherBuilder;
private:
    Archer(Health, const Armor&, const Bow&);

    Bow bow_;
};

class Doctor : public Unit
{
public:
    explicit Doctor(const std::shared_ptr<const Doctor>&);
    virtual ~Doctor() = default;
    virtual std::shared_ptr<Unit> clone() const;

    friend DoctorBuilder;
private:
    Doctor(Health, const Armor&, const Healing&);

    Healing heal_;
};