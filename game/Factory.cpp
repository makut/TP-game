# include "Factory.h"

AbstractFactory::AbstractFactory(const std::shared_ptr<AbstractUnit> &data) : data_(data){}

OrcFactory::OrcFactory(const std::shared_ptr<Orc> &data) : AbstractFactory(data){}

HumanFactory::HumanFactory(const std::shared_ptr<Human> &data) : AbstractFactory(data){}

std::shared_ptr<Unit> OrcFactory::createWarrior()
{
    return std::shared_ptr<Unit>(new )
}

std::shared_ptr<Unit> OrcFactory::createArcher()
{

}

std::shared_ptr<Unit> OrcFactory::createDoctor()
{

}

std::shared_ptr<Unit> HumanFactory::createWarrior()
{

}

std::shared_ptr<Unit> HumanFactory::createArcher()
{

}

std:shared_ptr<Unit> HumanFactory::createDoctor()
{
    
}