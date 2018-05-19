# include <iostream>
# include "game/Factory.h"
# include "game/BattleDecorators.h"
# include "game/Army.h"
# include "game/CompositeVisitor.h"

TEST(Structure, Company)
{
    std::shared_ptr<Company> testing(new Company);
    for (size_t i = 0; i < 10; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        testing->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
    }
    EXPECT_EQ(testing->getPower(), 750);
}

TEST(Structure, Battalion)
{
    std::shared_ptr<Battalion> testing(new Battalion);
    for (size_t i = 0; i < 10; i++)
    {
        std::shared_ptr<Company> comp(new Company);
        for (size_t j = 0; j < 10; j++)
        {
            ArcherBuilder ab;
            HumanBuilder hb;
            std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
            std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
            comp->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
        }
        testing->addUnit(comp);
    }
    EXPECT_EQ(testing->getPower(), 7500);
}

TEST(Structure, Army)
{
    std::shared_ptr<Army> testing(new Army);
    for (size_t i = 0; i < 10; i++)
    {
        std::shared_ptr<Battalion> bat(new Battalion);
        for (size_t j = 0; j < 10; j++)
        {
            std::shared_ptr<Company> comp(new Company);
            for (size_t k = 0; k < 10; k++)
            {
                ArcherBuilder ab;
                HumanBuilder hb;
                std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
                std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
                comp->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
            }
            bat->addUnit(comp);
        }
        testing->addUnit(bat);
    }
    EXPECT_EQ(testing->getPower(), 75000);
}

TEST(Structure, BattleWinner)
{
    std::shared_ptr<Company> first(new Company);
    for (size_t i = 0; i < 10; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        first->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
    }
    std::shared_ptr<Company> second(new Company);
    for (size_t i = 0; i < 9; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        second->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));   
    }
    Battle b(first.get(), second.get());
    EXPECT_EQ(b.executeBattle(), FIRST);
}

TEST(Structure, BattleDecorator)
{
    std::shared_ptr<Company> first(new Company);
    for (size_t i = 0; i < 10; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        first->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
    }
    std::shared_ptr<Company> second(new Company);
    for (size_t i = 0; i < 9; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        second->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));   
    }
    Battle b(first.get(), second.get());
    BasicDecorator bd(b);
    Winner res = bd.executeBattle();
    EXPECT_EQ(first->getMoney(), 10100);
    EXPECT_EQ(second->getMoney(), 8910);
    EXPECT_EQ(res, FIRST);
}

TEST(Structure, MultipleDecorator)
{
    std::shared_ptr<Company> first(new Company);
    for (size_t i = 0; i < 10; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        first->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
    }
    std::shared_ptr<Company> second(new Company);
    for (size_t i = 0; i < 9; i++)
    {
        ArcherBuilder ab;
        HumanBuilder hb;
        std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
        std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
        second->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));   
    }
    Battle b(first.get(), second.get());
    auto bd = BasicDecorator(BasicDecorator(BasicDecorator(b)));
    std::shared_ptr<IArmyPrinter> ap(new ArmyPrinter);
    Winner res = bd.executeBattle();
    EXPECT_EQ(first->getMoney(), 10300);
    EXPECT_EQ(second->getMoney(), 8730);
    EXPECT_EQ(res, FIRST);
}