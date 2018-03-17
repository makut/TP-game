# pragma once
# include "Game.h"
# include "Unit.h"
# include "AbstractRace.h"

class OrcWarrior : public Orc, public Warrior
{
public:
    explicit OrcWarrior(std::shared_ptr<Orc>);
    ~OrcWarrior() = default;
private:
};

class OrcArcher : public Orc, public Archer
{
public:
    explicit OrcArcher(std::shared_ptr<Orc>);
    ~OrcArcher() = default;
private:
};

class OrcDoctor : public Orc, public Doctor
{
public:
    explicit OrcDoctor(std::shared_ptr<Orc>);
    ~OrcDoctor() = default;
private:
};

class HumanWarrior : public Human, public Warrior
{
public:
    explicit HumanWarrior(std::shared_ptr<Human>);
    ~HumanWarrior() = default;
private:
};

class HumanArcher : public Human, public Archer
{
public:
    explicit HumanArcher(std::shared_ptr<Human>);
    ~HumanArcher() = default;
private:
};

class HumanDoctor : public Human, public Doctor
{
public:
    explicit HumanDoctor(std::shared_ptr<Human>);
    ~HumanDoctor() = default;
private:
};