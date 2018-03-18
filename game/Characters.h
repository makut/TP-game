# pragma once
# include "Game.h"
# include "Unit.h"
# include "AbstractRace.h"

class OrcWarrior : public Orc, public Warrior
{
public:
    OrcWarrior(const std::shared_ptr<const Orc>&, const std::shared_ptr<const Warrior>&);
    OrcWarrior(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~OrcWarrior() = default;
    virtual std::shared_ptr<Unit> clone() const;
};

class OrcArcher : public Orc, public Archer
{
public:
    OrcArcher(const std::shared_ptr<const Orc>&, const std::shared_ptr<const Archer>&);
    OrcArcher(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~OrcArcher() = default;
    virtual std::shared_ptr<Unit> clone() const;
};

class OrcDoctor : public Orc, public Doctor
{
public:
    OrcDoctor(const std::shared_ptr<const Orc>&, const std::shared_ptr<const Doctor>&);
    OrcDoctor(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~OrcDoctor() = default;
    virtual std::shared_ptr<Unit> clone() const;
};

class HumanWarrior : public Human, public Warrior
{
public:
    HumanWarrior(const std::shared_ptr<const Human>&, const std::shared_ptr<const Warrior>&);
    HumanWarrior(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~HumanWarrior() = default;
    virtual std::shared_ptr<Unit> clone() const;
};

class HumanArcher : public Human, public Archer
{
public:
    HumanArcher(const std::shared_ptr<const Human>&, const std::shared_ptr<const Archer>&);
    HumanArcher(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~HumanArcher() = default;
    virtual std::shared_ptr<Unit> clone() const;
};

class HumanDoctor : public Human, public Doctor
{
public:
    HumanDoctor(const std::shared_ptr<const Human>&, const std::shared_ptr<const Doctor>&);
    HumanDoctor(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~HumanDoctor() = default;
    virtual std::shared_ptr<Unit> clone() const;
};