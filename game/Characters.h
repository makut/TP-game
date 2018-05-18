# pragma once
# include <memory>
# include "Unit.h"
# include "AbstractRace.h"

class OrcWarrior : public Orc, public Warrior, public std::enable_shared_from_this<OrcWarrior>
{
public:
    OrcWarrior(const std::shared_ptr<const Orc>&, const std::shared_ptr<const Warrior>&);
    OrcWarrior(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~OrcWarrior() = default;
    virtual std::shared_ptr<Unit> clone() const;
    virtual std::string getName() const override;
};

class OrcArcher : public Orc, public Archer, public std::enable_shared_from_this<OrcArcher>
{
public:
    OrcArcher(const std::shared_ptr<const Orc>&, const std::shared_ptr<const Archer>&);
    OrcArcher(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~OrcArcher() = default;
    virtual std::shared_ptr<Unit> clone() const;
    virtual std::string getName() const override;
};

class OrcDoctor : public Orc, public Doctor, public std::enable_shared_from_this<OrcDoctor>
{
public:
    OrcDoctor(const std::shared_ptr<const Orc>&, const std::shared_ptr<const Doctor>&);
    OrcDoctor(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~OrcDoctor() = default;
    virtual std::shared_ptr<Unit> clone() const;
    virtual std::string getName() const override;
};

class HumanWarrior : public Human, public Warrior, public std::enable_shared_from_this<HumanWarrior>
{
public:
    HumanWarrior(const std::shared_ptr<const Human>&, const std::shared_ptr<const Warrior>&);
    HumanWarrior(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~HumanWarrior() = default;
    virtual std::shared_ptr<Unit> clone() const;
    virtual std::string getName() const override;
};

class HumanArcher : public Human, public Archer, public std::enable_shared_from_this<HumanArcher>
{
public:
    HumanArcher(const std::shared_ptr<const Human>&, const std::shared_ptr<const Archer>&);
    HumanArcher(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~HumanArcher() = default;
    virtual std::shared_ptr<Unit> clone() const;
    virtual std::string getName() const override;
};

class HumanDoctor : public Human, public Doctor, public std::enable_shared_from_this<HumanDoctor>
{
public:
    HumanDoctor(const std::shared_ptr<const Human>&, const std::shared_ptr<const Doctor>&);
    HumanDoctor(const std::shared_ptr<AbstractUnit>&, const std::shared_ptr<Unit>&);
    ~HumanDoctor() = default;
    virtual std::shared_ptr<Unit> clone() const;
    virtual std::string getName() const override;
};