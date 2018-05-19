# include "CompositeVisitor.h"

ArmyPrinter::ArmyPrinter(std::ostream &out) : out_(out), curr_(1) {}

void ArmyPrinter::printSoldier(Soldier *unit)
{
    ind_sold_[curr_++] = unit;
    out_ << "Index: " << curr_ - 1 << ", Money: " << unit->getMoney() << ", " << unit->getName() << "\n";
}

void ArmyPrinter::printCompany(Company *comp)
{
    ind_comp_[curr_++] = comp;
    out_ << "Index: " << curr_ - 1 << ", Money: " << comp->getMoney() << ", Company\n";
}

void ArmyPrinter::printBattalion(Battalion *bat)
{
    ind_bat_[curr_++] = bat;
    out_ << "Index: " << curr_ - 1 << ", Money: " << bat->getMoney() << ", Battalion\n";
}

void ArmyPrinter::printArmy(Army *army)
{
    ind_army_[curr_++] = army;
    out_ << "Index: " << curr_ - 1 << ", Money: " << army->getMoney() << ", Army\n";
}

void ArmyPrinter::useIndent(int ind)
{
    out_ << std::string(ind, ' ');
}

void ArmyPrinter::reset()
{
    curr_ = 1;
    ind_army_.clear();
    ind_bat_.clear();
    ind_comp_.clear();
    ind_sold_.clear();
}