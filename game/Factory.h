# pragma once
# include <memory>
# include "AbstractRace.h"
# include "Unit.h"
# include "Characters.h"

class AbstractFactory
{
protected:
    AbstractFactory(const std::shared_ptr<AbstractUnit>&);
    virtual ~AbstractFactory() = 0;
    std::shared_ptr<AbstractUnit> data_;
public:
    virtual std::shared_ptr<Unit> getWarrior(const std::shared_ptr<Warrior>&) = 0;
    virtual std::shared_ptr<Unit> getArcher(const std::shared_ptr<Archer>&) = 0;
    virtual std::shared_ptr<Unit> getDoctor(const std::shared_ptr<Doctor>&) = 0;
};

class OrcFactory : public AbstractFactory
{
public:
    explicit OrcFactory(const std::shared_ptr<Orc>&);
    ~OrcFactory() = default;

    virtual std::shared_ptr<Unit> getWarrior(const std::shared_ptr<Warrior>&) override;
    virtual std::shared_ptr<Unit> getArcher(const std::shared_ptr<Archer>&) override;
    virtual std::shared_ptr<Unit> getDoctor(const std::shared_ptr<Doctor>&) override;
};

class HumanFactory : public AbstractFactory
{
public:
    explicit HumanFactory(const std::shared_ptr<Human>&);
    ~HumanFactory() = default;

    virtual std::shared_ptr<Unit> getWarrior(const std::shared_ptr<Warrior>&) override;
    virtual std::shared_ptr<Unit> getArcher(const std::shared_ptr<Archer>&) override;
    virtual std::shared_ptr<Unit> getDoctor(const std::shared_ptr<Doctor>&) override;
};