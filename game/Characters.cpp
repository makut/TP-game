# include "Characters.h"

OrcWarrior::OrcWarrior(const std::shared_ptr<const Orc> &other_orc, const std::shared_ptr<const Warrior> &other_war): 
    Orc(other_orc), Warrior(other_war) {}

OrcWarrior::OrcWarrior(const std::shared_ptr<AbstractUnit> &other_orc, const std::shared_ptr<Unit> &other_war):
    OrcWarrior(std::dynamic_pointer_cast<const Orc>(other_orc), std::dynamic_pointer_cast<const Warrior>(other_war)) {}

OrcArcher::OrcArcher(const std::shared_ptr<const Orc> &other_orc, const std::shared_ptr<const Archer> &other_arch): 
    Orc(other_orc), Archer(other_arch) {}

OrcArcher::OrcArcher(const std::shared_ptr<AbstractUnit> &other_orc, const std::shared_ptr<Unit> &other_arch):
    OrcArcher(std::dynamic_pointer_cast<const Orc>(other_orc), std::dynamic_pointer_cast<const Archer>(other_arch)) {}

OrcDoctor::OrcDoctor(const std::shared_ptr<const Orc> &other_orc, const std::shared_ptr<const Doctor> &other_doc): 
    Orc(other_orc), Doctor(other_doc) {}

OrcDoctor::OrcDoctor(const std::shared_ptr<AbstractUnit> &other_orc, const std::shared_ptr<Unit> &other_doc):
    OrcDoctor(std::dynamic_pointer_cast<const Orc>(other_orc), std::dynamic_pointer_cast<const Doctor>(other_doc)) {}

HumanWarrior::HumanWarrior(const std::shared_ptr<const Human> &other_hum, const std::shared_ptr<const Warrior> &other_war): 
    Human(other_hum), Warrior(other_war) {}

HumanWarrior::HumanWarrior(const std::shared_ptr<AbstractUnit> &other_hum, const std::shared_ptr<Unit> &other_war):
    HumanWarrior(std::dynamic_pointer_cast<const Human>(other_hum), std::dynamic_pointer_cast<const Warrior>(other_war)) {}

HumanArcher::HumanArcher(const std::shared_ptr<const Human> &other_hum, const std::shared_ptr<const Archer> &other_arch): 
    Human(other_hum), Archer(other_arch) {}

HumanArcher::HumanArcher(const std::shared_ptr<AbstractUnit> &other_hum, const std::shared_ptr<Unit> &other_arch):
    HumanArcher(std::dynamic_pointer_cast<const Human>(other_hum), std::dynamic_pointer_cast<const Archer>(other_arch)) {}

HumanDoctor::HumanDoctor(const std::shared_ptr<const Human> &other_hum, const std::shared_ptr<const Doctor> &other_doc): 
    Human(other_hum), Doctor(other_doc) {}

HumanDoctor::HumanDoctor(const std::shared_ptr<AbstractUnit> &other_hum, const std::shared_ptr<Unit> &other_doc):
    HumanDoctor(std::dynamic_pointer_cast<const Human>(other_hum), std::dynamic_pointer_cast<const Doctor>(other_doc)) {}

std::shared_ptr<Unit> OrcWarrior::clone() const
{
    std::shared_ptr<const OrcWarrior> shared_this = shared_from_this();
    std::shared_ptr<const Orc> orc_prototype(std::dynamic_pointer_cast<const Orc>(shared_this));
    std::shared_ptr<const Warrior> war_prototype(std::dynamic_pointer_cast<const Warrior>(shared_this));
    return std::shared_ptr<Unit>(new OrcWarrior(orc_prototype, war_prototype));
}

std::shared_ptr<Unit> OrcArcher::clone() const
{
    std::shared_ptr<const OrcArcher> shared_this = shared_from_this();
    std::shared_ptr<const Orc> orc_prototype(std::dynamic_pointer_cast<const Orc>(shared_this));
    std::shared_ptr<const Archer> arch_prototype(std::dynamic_pointer_cast<const Archer>(shared_this));
    return std::shared_ptr<Unit>(new OrcArcher(orc_prototype, arch_prototype));
}

std::shared_ptr<Unit> OrcDoctor::clone() const
{
    std::shared_ptr<const OrcDoctor> shared_this = shared_from_this();
    std::shared_ptr<const Orc> orc_prototype(std::dynamic_pointer_cast<const Orc>(shared_this));
    std::shared_ptr<const Doctor> doc_prototype(std::dynamic_pointer_cast<const Doctor>(shared_this));
    return std::shared_ptr<Unit>(new OrcDoctor(orc_prototype, doc_prototype));
}

std::shared_ptr<Unit> HumanWarrior::clone() const
{
    std::shared_ptr<const HumanWarrior> shared_this = shared_from_this();
    std::shared_ptr<const Human> hum_prototype(std::dynamic_pointer_cast<const Human>(shared_this));
    std::shared_ptr<const Warrior> war_prototype(std::dynamic_pointer_cast<const Warrior>(shared_this));
    return std::shared_ptr<Unit>(new HumanWarrior(hum_prototype, war_prototype));
}

std::shared_ptr<Unit> HumanArcher::clone() const
{
    std::shared_ptr<const HumanArcher> shared_this = shared_from_this();
    std::shared_ptr<const Human> hum_prototype(std::dynamic_pointer_cast<const Human>(shared_this));
    std::shared_ptr<const Archer> arch_prototype(std::dynamic_pointer_cast<const Archer>(shared_this));
    return std::shared_ptr<Unit>(new HumanArcher(hum_prototype, arch_prototype));
}

std::shared_ptr<Unit> HumanDoctor::clone() const
{
    std::shared_ptr<const HumanDoctor> shared_this = shared_from_this();
    std::shared_ptr<const Human> hum_prototype(std::dynamic_pointer_cast<const Human>(shared_this));
    std::shared_ptr<const Doctor> doc_prototype(std::dynamic_pointer_cast<const Doctor>(shared_this));
    return std::shared_ptr<Unit>(new HumanDoctor(hum_prototype, doc_prototype));
}