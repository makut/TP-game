# include "CompositeVisitor.h"

void ArmyPrinter::printSoldier(const Soldier &unit)
{
    std::cout << "Money: " << unit.getMoney() << ", " << unit.getName() << "\n";
}

void ArmyPrinter::printCompany(const Company &comp)
{
    std::cout << "Money: " << comp.getMoney() << ", Company\n";
}

void ArmyPrinter::printBattalion(const Battalion &bat)
{
    std::cout << "Money: " << bat.getMoney() << ", Battalion\n";
}

void ArmyPrinter::printArmy(const Army &army)
{
    std::cout << "Money: " << army.getMoney() << ", Money\n";
}