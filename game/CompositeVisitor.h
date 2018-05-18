# pragma once
# include <iostream>
# include "Army.h"

class ArmyPrinter : public IArmyPrinter
{
public:
    virtual void printSoldier(const Soldier &unit) override;
    virtual void printCompany(const Company &comp) override;
    virtual void printBattalion(const Battalion &bat) override;
    virtual void printArmy(const Army &army) override;
};
