# include "Army.h"

template<>
void Company::output(const std::shared_ptr<IArmyPrinter> &army_printer) 
{
    army_printer->printCompany(this);
}

template<>
void Battalion::output(const std::shared_ptr<IArmyPrinter> &army_printer)
{
    army_printer->printBattalion(this);
}

template<>
void Army::output(const std::shared_ptr<IArmyPrinter> &army_printer)
{
    army_printer->printArmy(this);
}