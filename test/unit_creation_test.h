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
    OrcFactory of(ob.getResult());
    std::shared_ptr<Unit> result = of.getWarrior(wb.getResult());
}

TEST(Building, OrcArcher)
{
    ArcherBuilder ab;
    OrcBuilder ob;
    OrcFactory of(ob.getResult());
    std::shared_ptr<Unit> result = of.getArcher(ab.getResult());
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
    OrcFactory of(ob.getResult());
    std::shared_ptr<Unit> result = of.getDoctor(db.getResult());
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
    HumanFactory hf(hb.getResult());
    std::shared_ptr<Unit> result = hf.getWarrior(wb.getResult());
}

TEST(Building, HumanArcher)
{
    ArcherBuilder ab;
    HumanBuilder hb;
    HumanFactory hf(hb.getResult());
    std::shared_ptr<Unit> result = hf.getArcher(ab.getResult());
}

TEST(Building, HumanDoctor)
{
    DoctorBuilder db;
    HumanBuilder hb;
    hb.setSize(Human::Size::BIG);
    hb.setSkin(Human::Skin::BLACK);
    hb.setHair(Human::Hair::WHITE);
    HumanFactory hf(hb.getResult());
    std::shared_ptr<Unit> result = hf.getDoctor(db.getResult());
}