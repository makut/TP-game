# pragma once
# include "Game.h"
# include "Field.h"

typedef size_t Health;

class Armor
{
public:
    explicit Armor(Health = DEFAULT_BALANCE);
    Health beat(Health);

    static const Health DEFAULT_BALANCE;
private:
    Health bal_;
};

class Weapon
{
protected:
    Weapon(Health, Coordinate);
    Health getHealth() const;
    Coordinate getDistance() const;
private:
    Health dam_;
    Coordinate dist_;
};

class Sword : public Weapon
{
public:
    explicit Sword(Health damage = DEFAULT_DAMAGE);

    static const Health DEFAULT_DAMAGE;
    static const Coordinate DISTANCE;
};

class Bow : public Weapon
{
public:
    explicit Bow(Health damage = DEFAULT_DAMAGE, Coordinate distance = DEFAULT_DISTANCE);

    static const Health DEFAULT_DAMAGE;
    static const Coordinate DEFAULT_DISTANCE;
};

class Healing
{
public:
    explicit Healing(Coordinate distance = DEFAULT_DISTANCE, Health heal = DEFAULT_HEAL);
    Health getHeal() const;
    Coordinate getDistance() const;

    static const Health DEFAULT_HEAL;
    static const Coordinate DEFAULT_DISTANCE;
private:
    Coordinate dist_;
    Health heal_;
};