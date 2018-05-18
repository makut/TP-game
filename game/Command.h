# pragma once
# include "Army.h"
# include "BattleDecorators.h"

class Command
{
public:
    Command(const Army &hum, const Army &orc, bool curr);
    virtual ~Command() = default;

    virtual void execute() = 0;
protected:
    Army human_, orc_;
    bool curr_;
};

class PrintCommand : public Command
{
public:
    PrintCommand(const Army &hum, const Army &orc, bool curr, const std::shared_ptr<IArmyPrinter> &ap);
    virtual void execute() override;
private:
    std::shared_ptr<IArmyPrinter> ap_;
};

class ChangeMoneyCommand : public Command
{
public:
    ChangeMoneyCommand(const Army &hum, const Army &orc, bool curr, int change);
    virtual void execute() override;
private:
    int change_;
};

class ExecuteBattleCommand : public Command
{
public:
    ExecuteBattleCommand(const Army &hum, const Army &orc, const std::shared_ptr<IArmyPrinter> &ap);
    virtual void execute() override;
private:
    std::shared_ptr<IArmyPrinter> ap_;
};