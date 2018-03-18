# include "Factory.h"

AbstractFactory::AbstractFactory(const std::shared_ptr<AbstractUnit> &data) : data_(data) {}

OrcFactory::OrcFactory(const std::shared_ptr<Orc> &data) : AbstractFactory(data) {}

OrcFactory::OrcFactory(const std::shared_ptr<AbstractUnit> &data): 
    OrcFactory(std::dynamic_pointer_cast<Orc>(data)) {}

HumanFactory::HumanFactory(const std::shared_ptr<Human> &data) : AbstractFactory(data) {}

HumanFactory::HumanFactory(const std::shared_ptr<AbstractUnit> &data):
    HumanFactory(std::dynamic_pointer_cast<Human>(data)) {}

AbstractFactory::~AbstractFactory(){}

std::shared_ptr<Unit> OrcFactory::getWarrior(const std::shared_ptr<Unit> &war)
{
    return std::shared_ptr<Unit>(new OrcWarrior(data_, std::dynamic_pointer_cast<Warrior>(war)));
}

std::shared_ptr<Unit> OrcFactory::getArcher(const std::shared_ptr<Unit> &arch)
{
    return std::shared_ptr<Unit>(new OrcArcher(data_, std::dynamic_pointer_cast<Archer>(arch)));
}

std::shared_ptr<Unit> OrcFactory::getDoctor(const std::shared_ptr<Unit> &doc)
{
    return std::shared_ptr<Unit>(new OrcDoctor(data_, std::dynamic_pointer_cast<Doctor>(doc)));
}

std::shared_ptr<Unit> HumanFactory::getWarrior(const std::shared_ptr<Unit> &war)
{
    return std::shared_ptr<Unit>(new HumanWarrior(data_, std::dynamic_pointer_cast<Warrior>(war)));
}

std::shared_ptr<Unit> HumanFactory::getArcher(const std::shared_ptr<Unit> &arch)
{
    return std::shared_ptr<Unit>(new HumanArcher(data_, std::dynamic_pointer_cast<Archer>(arch)));
}

std::shared_ptr<Unit> HumanFactory::getDoctor(const std::shared_ptr<Unit> &doc)
{
    return std::shared_ptr<Unit>(new HumanDoctor(data_, std::dynamic_pointer_cast<Doctor>(doc)));
}