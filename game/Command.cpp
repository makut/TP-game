# include "Command.h"

Command::Command(const std::shared_ptr<Army> &hum,
                 const std::shared_ptr<Army> &orc, bool curr):
    human_(hum), orc_(orc), curr_(curr) {}

PrintCommand::PrintCommand(const std::shared_ptr<Army> &hum,
                           const std::shared_ptr<Army> &orc,
                           bool curr, const std::shared_ptr<IArmyPrinter> &ap):
    Command(hum, orc, curr), ap_(ap) {}

void PrintCommand::execute()
{
    ap_->reset();
    if (curr_)
        orc_->show(ap_);
    else
        human_->show(ap_);
    ap_->reset();
}

ChangeMoneyCommand::ChangeMoneyCommand(const std::shared_ptr<Army> &hum,
                                       const std::shared_ptr<Army> &orc,
                                       bool curr, int change):
    Command(hum, orc, curr), change_(change) {}

void ChangeMoneyCommand::execute()
{
    if (curr_)
        orc_->addMoney(change_);
    else
        human_->addMoney(change_);
}

ExecuteBattleCommand::ExecuteBattleCommand(const std::shared_ptr<Army> &hum,
                                           const std::shared_ptr<Army> &orc,
                                           int curr_hum, int curr_orc):
    Command(hum, orc, false), curr_hum_(curr_hum), curr_orc_(curr_orc) {}

template<typename Set, typename ValType>
bool ExecuteBattleCommand::checkIn(const Set &s, const ValType &val)
{
    return s.find(val) != s.end();
};

Army* ExecuteBattleCommand::getArmy(int ind, const std::shared_ptr<ArmyPrinter> &ap)
{
    return ap->ind_army_.at(ind);
}

Battalion* ExecuteBattleCommand::getBat(int ind, const std::shared_ptr<ArmyPrinter> &ap)
{
    return ap->ind_bat_.at(ind);
}

Company* ExecuteBattleCommand::getComp(int ind, const std::shared_ptr<ArmyPrinter> &ap)
{
    return ap->ind_comp_.at(ind);
}

Soldier* ExecuteBattleCommand::getSold(int ind, const std::shared_ptr<ArmyPrinter> &ap)
{
    return ap->ind_sold_.at(ind);
}

void ExecuteBattleCommand::execute()
{
    NullBuffer null_buffer;
    std::ostream null_stream(&null_buffer);
    std::shared_ptr<ArmyPrinter> ap_hum(new ArmyPrinter(null_stream));
    std::shared_ptr<ArmyPrinter> ap_orc(new ArmyPrinter(null_stream));
    human_->show(ap_hum);
    orc_->show(ap_orc);
    if (checkIn(ap_hum->ind_army_, curr_hum_))
    {
        if (checkIn(ap_orc->ind_army_, curr_orc_))
            BasicDecorator(Battle(getArmy(curr_hum_, ap_hum), getArmy(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_bat_, curr_orc_))
            BasicDecorator(Battle(getArmy(curr_hum_, ap_hum), getBat(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_comp_, curr_orc_))
            BasicDecorator(Battle(getArmy(curr_hum_, ap_hum), getComp(curr_orc_, ap_orc))).executeBattle();
        else
            BasicDecorator(Battle(getArmy(curr_hum_, ap_hum), getSold(curr_orc_, ap_orc))).executeBattle();
    }
    else if (checkIn(ap_hum->ind_bat_, curr_hum_))
    {
        if (checkIn(ap_orc->ind_army_, curr_orc_))
            BasicDecorator(Battle(getBat(curr_hum_, ap_hum), getArmy(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_bat_, curr_orc_))
            BasicDecorator(Battle(getBat(curr_hum_, ap_hum), getBat(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_comp_, curr_orc_))
            BasicDecorator(Battle(getBat(curr_hum_, ap_hum), getComp(curr_orc_, ap_orc))).executeBattle();
        else
            BasicDecorator(Battle(getBat(curr_hum_, ap_hum), getSold(curr_orc_, ap_orc))).executeBattle();
    }
    else if (checkIn(ap_hum->ind_comp_, curr_hum_))
    {
        if (checkIn(ap_orc->ind_army_, curr_orc_))
            BasicDecorator(Battle(getComp(curr_hum_, ap_hum), getArmy(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_bat_, curr_orc_))
            BasicDecorator(Battle(getComp(curr_hum_, ap_hum), getBat(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_comp_, curr_orc_))
            BasicDecorator(Battle(getComp(curr_hum_, ap_hum), getComp(curr_orc_, ap_orc))).executeBattle();
        else
            BasicDecorator(Battle(getComp(curr_hum_, ap_hum), getSold(curr_orc_, ap_orc))).executeBattle();
    }
    else if (checkIn(ap_hum->ind_sold_, curr_hum_))
    {
        if (checkIn(ap_orc->ind_army_, curr_orc_))
            BasicDecorator(Battle(getSold(curr_hum_, ap_hum), getArmy(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_bat_, curr_orc_))
            BasicDecorator(Battle(getSold(curr_hum_, ap_hum), getBat(curr_orc_, ap_orc))).executeBattle();
        else if (checkIn(ap_orc->ind_comp_, curr_orc_))
            BasicDecorator(Battle(getSold(curr_hum_, ap_hum), getComp(curr_orc_, ap_orc))).executeBattle();
        else
            BasicDecorator(Battle(getSold(curr_hum_, ap_hum), getSold(curr_orc_, ap_orc))).executeBattle();
    }
    ap_hum.reset();
    // ap_orc.reset();
    std::cout << "Human:\n";
    human_->show(ap_hum);
    std::cout << "\n===================\nOrc:\n";
    orc_->show(ap_orc);
}