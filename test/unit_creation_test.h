# include <iostream>
# include "game/Factory.h"

TEST(Building, OrcWarrior)
{
    WarriorBuilder wb;
    OrcBuilder ob;
    wb.setHealth(200);
    wb.setArmor(Armor(100));
    wb.setSword(Sword(1000000000));
    ob.setSize(Orc::Size::BIG);
    ob.setColor(Orc::Color::WHITE);
    ob.setWool(Orc::Wool::LONG);
    std::shared_ptr<AbstractFactory> of(new OrcFactory(ob.getResult()));
    std::shared_ptr<Unit> result = of->getWarrior(wb.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Building, OrcArcher)
{
    ArcherBuilder ab;
    OrcBuilder ob;
    std::shared_ptr<AbstractFactory> of(new OrcFactory(ob.getResult()));
    std::shared_ptr<Unit> result = of->getArcher(ab.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Building, OrcDoctor)
{
    DoctorBuilder db;
    OrcBuilder ob;
    db.setHealth(1);
    db.setArmor(Armor(0));
    db.setHealing(Healing(10, 5));
    ob.setSize(Orc::Size::MEDIUM);
    ob.setColor(Orc::Color::WHITE);
    ob.setWool(Orc::Wool::SHORT);
    std::shared_ptr<AbstractFactory> of(new OrcFactory(ob.getResult()));
    std::shared_ptr<Unit> result = of->getDoctor(db.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Building, HumanWarrior)
{
    WarriorBuilder wb;
    HumanBuilder hb;
    wb.setHealth(200);
    wb.setArmor(Armor(100));
    wb.setSword(Sword(1));
    hb.setSize(Human::Size::BIG);
    hb.setHair(Human::Hair::BROWN);
    std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
    std::shared_ptr<Unit> result = hf->getWarrior(wb.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Building, HumanArcher)
{
    ArcherBuilder ab;
    HumanBuilder hb;
    std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
    std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Building, HumanDoctor)
{
    DoctorBuilder db;
    HumanBuilder hb;
    hb.setSize(Human::Size::BIG);
    hb.setSkin(Human::Skin::BLACK);
    hb.setHair(Human::Hair::WHITE);
    std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
    std::shared_ptr<Unit> result = hf->getDoctor(db.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}