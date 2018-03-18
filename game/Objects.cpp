# include "Objects.h"

Health Armor::beat(Health damage)
{
    if (damage <= bal_)
    {
        bal_ -= damage;
        return 0;
    }
    damage -= bal_;
    bal_ = 0;
    return damage;
}

const Health Armor::DEFAULT_BALANCE = 50;
Armor::Armor(Health balance) : bal_(balance) {}


Weapon::Weapon(Health damage, Coordinate distance) : dam_(damage), dist_(distance) {}

Health Weapon::getHealth() const
{
    return dam_;
}

Coordinate Weapon::getDistance() const
{
    return dist_;
}


const Health Sword::DEFAULT_DAMAGE = 10;
const Coordinate Sword::DISTANCE = 1;
const Health Bow::DEFAULT_DAMAGE = 5;
const Coordinate Bow::DEFAULT_DISTANCE = 5;

Sword::Sword(Health damage) : Weapon(damage, DEFAULT_DAMAGE) {}
Bow::Bow(Health damage, Coordinate distance) : Weapon(damage, distance) {}


const Health Healing::DEFAULT_HEAL = 5;
const Coordinate Healing::DEFAULT_DISTANCE = 5;

Healing::Healing(Coordinate distance, Health heal) : dist_(distance), heal_(heal) {}

Health Healing::getHeal() const
{
    return heal_;
}

Coordinate Healing::getDistance() const
{
    return dist_;
}