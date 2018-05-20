# pragma once
# include "game/Factory.h"
# include "game/Command.h"
# include "game/CompositeVisitor.h"

TEST(Composite, ArmyRemember)
{
    std::shared_ptr<Army> testing(new Army);
    for (size_t i = 0; i < 2; i++)
    {
        std::shared_ptr<Battalion> bat(new Battalion);
        for (size_t j = 0; j < 2; j++)
        {
            std::shared_ptr<Company> comp(new Company);
            for (size_t k = 0; k < 2; k++)
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
    std::shared_ptr<IArmyPrinter> ap(new ArmyPrinter);
    // std::shared_ptr<IArmyPrinter> ar(new ArmyRemember);
    testing->show(ap);
    // testing->show(ar);
}

TEST(Behavior, BattleExecution)
{
    std::shared_ptr<Army> first(new Army);
    for (size_t i = 0; i < 2; i++)
    {
        std::shared_ptr<Battalion> bat(new Battalion);
        for (size_t j = 0; j < 2; j++)
        {
            std::shared_ptr<Company> comp(new Company);
            for (size_t k = 0; k < 2; k++)
            {
                ArcherBuilder ab;
                HumanBuilder hb;
                std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
                std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
                comp->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
            }
            bat->addUnit(comp);
        }
        first->addUnit(bat);
    }
    std::shared_ptr<Army> second(new Army);
    for (size_t i = 0; i < 2; i++)
    {
        std::shared_ptr<Battalion> bat(new Battalion);
        for (size_t j = 0; j < 2; j++)
        {
            std::shared_ptr<Company> comp(new Company);
            for (size_t k = 0; k < 1; k++)
            {
                ArcherBuilder ab;
                OrcBuilder hb;
                std::shared_ptr<AbstractFactory> hf(new OrcFactory(hb.getResult()));
                std::shared_ptr<Unit> result = hf->getArcher(ab.getResult());
                comp->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
            }
            bat->addUnit(comp);
        }
        second->addUnit(bat);
    }
    std::shared_ptr<IArmyPrinter> hum_ap(new ArmyPrinter());
    std::shared_ptr<IArmyPrinter> orc_ap(new ArmyPrinter());
    ExecuteBattleCommand(first, second, 3, 1).execute();
}
