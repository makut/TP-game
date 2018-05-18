# include "Command.h"

Command::Command(const Army &hum, const Army &orc, bool curr):
    human_(hum), orc_(orc), curr_(curr) {}

PrintCommand::PrintCommand(const Army &hum, const Army &orc, bool curr, const std::shared_ptr<IArmyPrinter> &ap):
    Command(hum, orc, curr), ap_(ap) {}

void PrintCommand::execute()
{
    if (curr_)
        orc_.show(ap_);
    else
        human_.show(ap_);
}

ChangeMoneyCommand::ChangeMoneyCommand(const Army &hum, const Army &orc, bool curr, int change):
    Command(hum, orc, curr), change_(change) {}

void ChangeMoneyCommand::execute()
{
    if (curr_)
        orc_.addMoney(change_);
    else
        human_.addMoney(change_);
}

ExecuteBattleCommand::ExecuteBattleCommand(const Army &hum, const Army &orc,
                                           const std::shared_ptr<IArmyPrinter> &ap):
    Command(hum, orc, false), ap_(ap) {}

void ExecuteBattleCommand::execute()
{
    BasicDecorator(Battle(std::make_shared<Army>(human_), std::make_shared<Army>(orc_))).executeBattle();
    std::cout << "Human:\n";
    human_.show(ap_);
    std::cout << "\n===================\nOrc:\n";
    orc_.show(ap_);
}