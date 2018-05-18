# include "Unit.h"

const Health Unit::MAX_HEALTH = 100;
Unit::Unit(const std::shared_ptr<const Unit> &other):
    health_(other->health_), armor_(other->armor_) {}

Warrior::Warrior(const std::shared_ptr<const Warrior> &other):
    Unit(other), sword_(other->sword_) {}

Archer::Archer(const std::shared_ptr<const Archer> &other):
    Unit(other), bow_(other->bow_) {}

Doctor::Doctor(const std::shared_ptr<const Doctor> &other):
    Unit(other), heal_(other->heal_) {}

Unit::Unit(Health health, const Armor &armor):
    health_(health), armor_(armor) {}

Warrior::Warrior(Health health, const Armor &armor, const Sword &sword):
    Unit(health, armor), sword_(sword) {}

Archer::Archer(Health health, const Armor &armor, const Bow &bow):
    Unit(health, armor), bow_(bow) {}

Doctor::Doctor(Health health, const Armor &armor, const Healing &heal):
    Unit(health, armor), heal_(heal) {}

std::shared_ptr<Unit> Warrior::clone() const
{
    return std::shared_ptr<Unit>(NULL);
}

std::shared_ptr<Unit> Archer::clone() const
{
    return std::shared_ptr<Unit>(NULL);
}

std::shared_ptr<Unit> Doctor::clone() const
{
    return std::shared_ptr<Unit>(NULL);
}

long long Warrior::getPower() const
{
    return sword_.getPower() + armor_.getPower();
}

long long Archer::getPower() const
{
    return bow_.getPower() + armor_.getPower();
}

long long Doctor::getPower() const
{
    return heal_.getPower() + armor_.getPower();
}

std::string Warrior::getName() const
{
    return "Warrior";
}

std::string Archer::getName() const
{
    return "Archer";
}

std::string Doctor::getName() const
{
    return "Doctor";
}

Unit::~Unit(){}