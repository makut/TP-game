# include <iostream>
# include "game/Factory.h"

TEST(RankBuider, Warrior)
{
    WarriorBuilder wb;
    wb.setHealth(200);
    wb.setArmor(Armor(100));
    wb.setSword(Sword(1000000000));
    wb.reset();
    wb.setArmor(Armor(100));
    std::shared_ptr<Unit> res = wb.getResult();
}

TEST(RankBuider, Archer)
{
    ArcherBuilder ab;
    ab.setHealth(100);
    ab.setArmor(Armor(1));
    ab.setBow(Bow(1, 1));
    std::shared_ptr<Unit> res = ab.getResult();
}

TEST(RankBuider, Doctor)
{
    DoctorBuilder db;
    db.setHealing(Healing(10, 5));
    std::shared_ptr<Unit> res = db.getResult();
}

TEST(RaceBuilder, Orc)
{
    OrcBuilder ob;
    ob.setSize(Orc::Size::BIG);
    ob.setColor(Orc::Color::WHITE);
    ob.setWool(Orc::Wool::LONG);
    ob.reset();
    ob.setSize(Orc::Size::MEDIUM);
    ob.setColor(Orc::Color::WHITE);
    ob.setWool(Orc::Wool::SHORT);
    std::shared_ptr<AbstractUnit> res = ob.getResult();
}

TEST(RaceBuilder, Human)
{
    HumanBuilder hb;
    hb.setSize(Human::Size::BIG);
    hb.setHair(Human::Hair::BROWN);
    hb.reset();
    hb.setSize(Human::Size::BIG);
    hb.setSkin(Human::Skin::BLACK);
    hb.setHair(Human::Hair::WHITE);
    std::shared_ptr<AbstractUnit> res = hb.getResult();
}

TEST(Construction, OrcWarrior)
{
    WarriorBuilder wb;
    OrcBuilder ob;
    std::shared_ptr<AbstractFactory> of(new OrcFactory(ob.getResult()));
    std::shared_ptr<Unit> result = of->getWarrior(wb.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Construction, OrcArcher)
{
    ArcherBuilder ab;
    OrcBuilder ob;
    std::shared_ptr<AbstractFactory> of(new OrcFactory(ob.getResult()));
    std::shared_ptr<Unit> result = of->getArcher(ab.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Construction, OrcDoctor)
{
    DoctorBuilder db;
    OrcBuilder ob;
    std::shared_ptr<AbstractFactory> of(new OrcFactory(ob.getResult()));
    std::shared_ptr<Unit> result = of->getDoctor(db.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Construction, HumanWarrior)
{
    WarriorBuilder wb;
    HumanBuilder hb;
    std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
    std::shared_ptr<Unit> result = hf->getWarrior(wb.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Construction, HumanArcher)
{
    ArcherBuilder ab;
    HumanBuilder hb;
    std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
    std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}

TEST(Construction, HumanDoctor)
{
    DoctorBuilder db;
    HumanBuilder hb;
    std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
    std::shared_ptr<Unit> result = hf->getDoctor(db.getResult());
    std::shared_ptr<Unit> result_copy = result->clone();
}