# include "Factory.h"

AbstractFactory::AbstractFactory(const std::shared_ptr<AbstractUnit> &data) : data_(data){}

OrcFactory::OrcFactory(const std::shared_ptr<Orc> &data) : AbstractFactory(data){}

HumanFactory::HumanFactory(const std::shared_ptr<Human> &data) : AbstractFactory(data){}

AbstractFactory::~AbstractFactory(){}

std::shared_ptr<Unit> OrcFactory::getWarrior(const std::shared_ptr<Warrior> &war)
{
    return std::shared_ptr<Unit>(new OrcWarrior(std::dynamic_pointer_cast<Orc>(data_), war));
}

std::shared_ptr<Unit> OrcFactory::getArcher(const std::shared_ptr<Archer> &arch)
{
    return std::shared_ptr<Unit>(new OrcArcher(std::dynamic_pointer_cast<Orc>(data_), arch));
}

std::shared_ptr<Unit> OrcFactory::getDoctor(const std::shared_ptr<Doctor> &doc)
{
    return std::shared_ptr<Unit>(new OrcDoctor(std::dynamic_pointer_cast<Orc>(data_), doc));
}

std::shared_ptr<Unit> HumanFactory::getWarrior(const std::shared_ptr<Warrior> &war)
{
    return std::shared_ptr<Unit>(new HumanWarrior(std::dynamic_pointer_cast<Human>(data_), war));
}

std::shared_ptr<Unit> HumanFactory::getArcher(const std::shared_ptr<Archer> &arch)
{
    return std::shared_ptr<Unit>(new HumanArcher(std::dynamic_pointer_cast<Human>(data_), arch));
}

std::shared_ptr<Unit> HumanFactory::getDoctor(const std::shared_ptr<Doctor> &doc)
{
    return std::shared_ptr<Unit>(new HumanDoctor(std::dynamic_pointer_cast<Human>(data_), doc));
}