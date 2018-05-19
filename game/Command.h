# pragma once
# include "Army.h"
# include "BattleDecorators.h"
# include "CompositeVisitor.h"

class Command
{
public:
    Command(const std::shared_ptr<Army> &hum,
            const std::shared_ptr<Army> &orc, bool curr);
    virtual ~Command() = default;

    virtual void execute() = 0;
protected:
    std::shared_ptr<Army> human_, orc_;
    bool curr_;
};

class PrintCommand : public Command
{
public:
    PrintCommand(const std::shared_ptr<Army> &hum,
                 const std::shared_ptr<Army> &orc,
                 bool curr, const std::shared_ptr<IArmyPrinter> &ap);
    virtual void execute() override;
private:
    std::shared_ptr<IArmyPrinter> ap_;
};

class ChangeMoneyCommand : public Command
{
public:
    ChangeMoneyCommand(const std::shared_ptr<Army> &hum,
                       const std::shared_ptr<Army> &orc,
                       bool curr, int change);
    virtual void execute() override;
private:
    int change_;
};

class ExecuteBattleCommand : public Command
{
public:
    ExecuteBattleCommand(const std::shared_ptr<Army> &hum,
                         const std::shared_ptr<Army> &orc,
                         int curr_hum, int curr_orc);
    virtual void execute() override;
private:
    int curr_hum_, curr_orc_;

    static Army* getArmy(int ind, const std::shared_ptr<ArmyPrinter> &ap);
    static Battalion* getBat(int ind, const std::shared_ptr<ArmyPrinter> &ap);
    static Company* getComp(int ind, const std::shared_ptr<ArmyPrinter> &ap);
    static Soldier* getSold(int ind, const std::shared_ptr<ArmyPrinter> &ap);

    template<typename Set, typename ValType>
    static bool checkIn(const Set &s, const ValType &val);
};