# include "Characters.h"

OrcWarrior::OrcWarrior(const std::shared_ptr<Orc> &other) : Orc(other), Warrior(/* TODO */) {}

OrcArcher::OrcArcher(const std::shared_ptr<Orc> &other) : Orc(other), Archer() {}

OrcDoctor::OrcDoctor(const std::shared_ptr<Orc> &other) : Orc(other), Doctor() {}

HumanWarrior::HumanWarrior(const std::shared_ptr<Human> &other) : Human(other), Warrior() {}

HumanArcher::HumanArcher(const std::shared_ptr<Human> &other) : Human(other), Archer() {}

HumanDoctor::HumanDoctor(const std::shared_ptr<Human> &other) : Human(other), Doctor() {}