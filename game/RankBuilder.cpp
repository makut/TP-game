# include "RankBuilder.h"

AbstractRankBuilder::AbstractRankBuilder():
    health_(Unit::MAX_HEALTH), armor_(Armor::DEFAULT_BALANCE) {}

AbstractRankBuilder::~AbstractRankBuilder(){}

void AbstractRankBuilder::setHealth(Health health)
{
    health_ = health;
}

void AbstractRankBuilder::setArmor(const Armor &armor)
{
    armor_ = armor;
}

WarriorBuilder::WarriorBuilder():
    AbstractRankBuilder(), sword_() {}

ArcherBuilder::ArcherBuilder():
    AbstractRankBuilder(), bow_() {}

DoctorBuilder::DoctorBuilder():
    AbstractRankBuilder(), heal_() {}

void WarriorBuilder::reset()
{
    *this = WarriorBuilder();
}

void ArcherBuilder::reset()
{
    *this = ArcherBuilder();
}

void DoctorBuilder::reset()
{
    *this = DoctorBuilder();
}

void WarriorBuilder::setSword(const Sword &sword)
{
    sword_ = sword;
}

void ArcherBuilder::setBow(const Bow &bow)
{
    bow_ = bow;
}

void DoctorBuilder::setHealing(const Healing &heal)
{
    heal_ = heal;
}

std::shared_ptr<Unit> WarriorBuilder::getResult() const
{
    return std::shared_ptr<Warrior>(new Warrior(health_, armor_, sword_));
}

std::shared_ptr<Unit> ArcherBuilder::getResult() const
{
    return std::shared_ptr<Archer>(new Archer(health_, armor_, bow_));
}

std::shared_ptr<Unit> DoctorBuilder::getResult() const
{
    return std::shared_ptr<Doctor>(new Doctor(health_, armor_, heal_));
}