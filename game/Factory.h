# pragma once
# include <memory>
# include "AbstractRace.h"
# include "Unit.h"
# include "Characters.h"

class AbstractFactory
{
protected:
    AbstractFactory(const std::shared_ptr<AbstractUnit>&);
    ~AbstractFactory() = default;
public:
    virtual std::shared_ptr<Unit> getWarrior() = 0;
    virtual std::shared_ptr<Unit> getArcher() = 0;
    virtual std::shared_ptr<Unit> getDoctor() = 0;
private:
    std::shared_ptr<AbstractUnit> data_;
};

class OrcFactory : public AbstractFactory
{
public:
    OrcFactory(const std::shared_ptr<Orc>&);
    ~OrcFactory() = default;

    virtual std::shared_ptr<Unit> getWarrior() override;
    virtual std::shared_ptr<Unit> getArcher() override;
    virtual std::shared_ptr<Unit> getDoctor() override;
};

class HumanFactory : public AbstractFactory
{
public:
    HumanFactory(const std::shared_ptr<Human>&);
    ~HumanFactory() = default;

    virtual std::shared_ptr<Unit> getWarrior() override;
    virtual std::shared_ptr<Unit> getArcher() override;
    virtual std::shared_ptr<Unit> getDoctor() override;
};