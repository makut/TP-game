# pragma once
# include "Game.h"

class Unit
{
public:
    virtual std::shared_ptr<Unit> clone() const = 0;
private:

};

class Warrior : public Unit
{
public:
    virtual std::shared_ptr<Unit> clone() const = 0;
};

class Archer : public Unit
{
public:
    virtual std::shared_ptr<Unit> clone() const = 0;
};

class Doctor : public Unit
{
public:
    virtual std::shared_ptr<Unit> clone() const = 0;
};