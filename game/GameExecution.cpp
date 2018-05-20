# include "GameExecution.h"

std::shared_ptr<Army> createHumanArmy()
{
    std::shared_ptr<Army> human(new Army);
    for (size_t i = 0; i < 2; i++)
    {
        std::shared_ptr<Battalion> bat(new Battalion);
        for (size_t j = 0; j < 2; j++)
        {
            std::shared_ptr<Company> comp(new Company);
            for (size_t k = 0; k < 2; k++)
            {
                HumanBuilder hb;
                std::shared_ptr<AbstractFactory> hf(new HumanFactory(hb.getResult()));
                int choice = rand() % 3;
                std::shared_ptr<Unit> result;
                if (choice == 0)
                    result = hf->getArcher(ArcherBuilder().getResult());
                else if (choice == 1)
                    result = hf->getWarrior(WarriorBuilder().getResult());
                else
                    result = hf->getDoctor(DoctorBuilder().getResult());
                comp->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
            }
            bat->addUnit(comp);
        }
        human->addUnit(bat);
    }
    std::shared_ptr<IArmyPrinter> ap(new ArmyPrinter);
    std::cout << "Human Army\n------------------------\n";
    human->show(ap);
    std::cout << "------------------------\n\n";
    return human;
}

std::shared_ptr<Army> createOrcArmy()
{
    std::shared_ptr<Army> orc(new Army);
    for (size_t i = 0; i < 2; i++)
    {
        std::shared_ptr<Battalion> bat(new Battalion);
        for (size_t j = 0; j < 2; j++)
        {
            std::shared_ptr<Company> comp(new Company);
            for (size_t k = 0; k < 2; k++)
            {
                OrcBuilder hb;
                std::shared_ptr<AbstractFactory> of(new OrcFactory(hb.getResult()));
                int choice = rand() % 3;
                std::shared_ptr<Unit> result;
                if (choice == 0)
                    result = of->getArcher(ArcherBuilder().getResult());
                else if (choice == 1)
                    result = of->getWarrior(WarriorBuilder().getResult());
                else
                    result = of->getDoctor(DoctorBuilder().getResult());
                comp->addUnit(std::shared_ptr<Soldier>(new Soldier(result)));
            }
            bat->addUnit(comp);
        }
        orc->addUnit(bat);
    }
    std::shared_ptr<IArmyPrinter> ap(new ArmyPrinter);
    std::cout << "Orc Army\n------------------------\n";
    orc->show(ap);
    std::cout << "------------------------\n";
    return orc;
}

void executeCommand(const std::shared_ptr<Army> &human, const std::shared_ptr<Army> &orc)
{
    std::cout << "Possible commands:\n1 - Print structure of army\n2 - Execute battle\n";
    std::string input;
    std::getline(std::cin, input);
    if (input.size() == 1 && (input[0] == '1' || input[0] == '2'))
    {
        int com = std::stoi(input);
        if (com == 1)
        {
            int army;
            while (true)
            {
                std::cout << "Type army you are interested in:\n1 - Human Army\n2 - Orc Army\n";
                std::string input;
                std::getline(std::cin, input);
                if (input.size() == 1 && (input[0] == '1' || input[0] == '2'))
                {
                    army = std::stoi(input) - 1;
                    break;
                }
                else
                    std::cout << "Input army number is incorrect\n";
            }
            std::shared_ptr<IArmyPrinter> ap(new ArmyPrinter);
            PrintCommand(human, orc, army, ap).execute();
        }
        else
        {
            int human_ind;
            while (true)
            {
                std::cout << "Type Human subarmy index (1-" << human->getSubArmiesNum() << ")\n";
                std::string input;
                std::getline(std::cin, input);
                if (!input.empty() && 
                    std::all_of(input.begin(), input.end(), [](unsigned char c){return std::isdigit(c);}))
                {
                    human_ind = std::stoi(input);
                    if (human_ind >= 1 && human_ind <= human->getSubArmiesNum())
                        break;
                }
                std::cout << "Input Human army subarmy number is incorrect\n";
            }
            int orc_ind;
            while (true)
            {
                std::cout << "Type Orc subarmy index (1-" << orc->getSubArmiesNum() << ")\n";
                std::string input;
                std::getline(std::cin, input);
                if (!input.empty() &&
                    std::all_of(input.begin(), input.end(), [](unsigned char c){return std::isdigit(c);}))
                {
                    orc_ind = std::stoi(input);
                    if (orc_ind >= 1 && orc_ind <= orc->getSubArmiesNum())
                        break;
                }
                std::cout << "Input Orc army subarmy number is incorrect\n";
            }
            ExecuteBattleCommand(human, orc, human_ind, orc_ind).execute();
        }
    }
    else
        std::cout << "Your input operation number is incorrect\n";
}

void executeGame()
{
    srand(time(NULL));
    std::shared_ptr<Army> human = createHumanArmy();
    std::shared_ptr<Army> orc = createOrcArmy();
    while (human->getMoney() > 0 && orc->getMoney() > 0)
    {
        executeCommand(human, orc);
    }
    if (human->getMoney() <= 0)
        std::cout << "ORC ARMY WON\n";
    else
        std::cout << "HUMAN ARMY WON\n";
}