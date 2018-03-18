# include "Characters.h"

OrcWarrior::OrcWarrior(const std::shared_ptr<const Orc> &other_orc, const std::shared_ptr<const Warrior> &other_war)
    : Orc(other_orc), Warrior(other_war) {}

OrcArcher::OrcArcher(const std::shared_ptr<const Orc> &other_orc, const std::shared_ptr<const Archer> &other_arch)
    : Orc(other_orc), Archer(other_arch) {}

OrcDoctor::OrcDoctor(const std::shared_ptr<const Orc> &other_orc, const std::shared_ptr<const Doctor> &other_doc)
    : Orc(other_orc), Doctor(other_doc) {}

HumanWarrior::HumanWarrior(const std::shared_ptr<const Human> &other_hum, const std::shared_ptr<const Warrior> &other_war)
    : Human(other_hum), Warrior(other_war) {}

HumanArcher::HumanArcher(const std::shared_ptr<const Human> &other_hum, const std::shared_ptr<const Archer> &other_arch)
    : Human(other_hum), Archer(other_arch) {}

HumanDoctor::HumanDoctor(const std::shared_ptr<const Human> &other_hum, const std::shared_ptr<const Doctor> &other_doc)
    : Human(other_hum), Doctor(other_doc) {}

std::shared_ptr<Unit> OrcWarrior::clone() const
{
    return std::shared_ptr<Unit>(new OrcWarrior(std::shared_ptr<const Orc>(this), std::shared_ptr<const Warrior>(this)));
}

std::shared_ptr<Unit> OrcArcher::clone() const
{
    return std::shared_ptr<Unit>(new OrcArcher(std::shared_ptr<const Orc>(this), std::shared_ptr<const Archer>(this)));
}

std::shared_ptr<Unit> OrcDoctor::clone() const
{
    return std::shared_ptr<Unit>(new OrcDoctor(std::shared_ptr<const Orc>(this), std::shared_ptr<const Doctor>(this)));
}

std::shared_ptr<Unit> HumanWarrior::clone() const
{
    return std::shared_ptr<Unit>(new HumanWarrior(std::shared_ptr<const Human>(this), std::shared_ptr<const Warrior>(this)));
}

std::shared_ptr<Unit> HumanArcher::clone() const
{
    return std::shared_ptr<Unit>(new HumanArcher(std::shared_ptr<const Human>(this), std::shared_ptr<const Archer>(this)));
}

std::shared_ptr<Unit> HumanDoctor::clone() const
{
    return std::shared_ptr<Unit>(new HumanDoctor(std::shared_ptr<const Human>(this), std::shared_ptr<const Doctor>(this)));
}