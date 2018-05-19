# pragma once
# include <iostream>
# include <map>
# include "Army.h"

class ExecuteBattleCommand;

class ArmyPrinter : public IArmyPrinter
{
public:
    explicit ArmyPrinter(std::ostream &out = std::cout);
    virtual void printSoldier(Soldier *unit) override;
    virtual void printCompany(Company *comp) override;
    virtual void printBattalion(Battalion *bat) override;
    virtual void printArmy(Army *army) override;
    virtual void useIndent(int ind) override;
    virtual void reset() override;

    friend ExecuteBattleCommand;
private:
    std::ostream &out_;
    int curr_;
    std::map<int, Army*> ind_army_;
    std::map<int, Battalion*> ind_bat_;
    std::map<int, Company*> ind_comp_;
    std::map<int, Soldier*> ind_sold_;
};