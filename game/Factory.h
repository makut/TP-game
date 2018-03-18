# pragma once
# include <memory>
# include "AbstractRace.h"
# include "Unit.h"
# include "Characters.h"
# include "AbstractRaceBuilder.h"
# include "RankBuilder.h"

class AbstractFactory
{
protected:
    AbstractFactory(const std::shared_ptr<AbstractUnit>&);
    virtual ~AbstractFactory() = 0;
    std::shared_ptr<AbstractUnit> data_;
public:
    virtual std::shared_ptr<Unit> getWarrior(const std::shared_ptr<Unit>&) = 0;
    virtual std::shared_ptr<Unit> getArcher(const std::shared_ptr<Unit>&) = 0;
    virtual std::shared_ptr<Unit> getDoctor(const std::shared_ptr<Unit>&) = 0;
};

class OrcFactory : public AbstractFactory
{
public:
    explicit OrcFactory(const std::shared_ptr<Orc>&);
    explicit OrcFactory(const std::shared_ptr<AbstractUnit>&);
    ~OrcFactory() = default;

    virtual std::shared_ptr<Unit> getWarrior(const std::shared_ptr<Unit>&) override;
    virtual std::shared_ptr<Unit> getArcher(const std::shared_ptr<Unit>&) override;
    virtual std::shared_ptr<Unit> getDoctor(const std::shared_ptr<Unit>&) override;
};

class HumanFactory : public AbstractFactory
{
public:
    explicit HumanFactory(const std::shared_ptr<Human>&);
    explicit HumanFactory(const std::shared_ptr<AbstractUnit>&);
    ~HumanFactory() = default;

    virtual std::shared_ptr<Unit> getWarrior(const std::shared_ptr<Unit>&) override;
    virtual std::shared_ptr<Unit> getArcher(const std::shared_ptr<Unit>&) override;
    virtual std::shared_ptr<Unit> getDoctor(const std::shared_ptr<Unit>&) override;
};