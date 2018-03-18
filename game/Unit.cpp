# include "Unit.h"

const Health Unit::MAX_HEALTH = 100;
Unit::Unit(const std::shared_ptr<const Unit> &other):
    health_(other->health_), armor_(other->armor_) {}

Warrior::Warrior(const std::shared_ptr<const Warrior> &other):
    Unit(other), sword_(other->sword_) {}

Archer::Archer(const std::shared_ptr<const Archer> &other):
    Unit(other), bow_(other->bow_) {}

Doctor::Doctor(const std::shared_ptr<const Doctor> &other):
    Unit(other), heal_(other->heal_) {}

Unit::~Unit(){}
Warrior::~Warrior(){}
Archer::~Archer(){}
Doctor::~Doctor(){}