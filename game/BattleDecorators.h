# pragma once
# include "Army.h"

template<typename W>
class Decorator
{
public:
    Decorator(const W &w) : w_(w) {}
    virtual void winner1(const std::shared_ptr<ArmyUnit<W::level1> >&) = 0;
    virtual void winner2(const std::shared_ptr<ArmyUnit<W::level2> >&) = 0;
    virtual void loser1(const std::shared_ptr<ArmyUnit<W::level1> >&) = 0;
    virtual void loser2(const std::shared_ptr<ArmyUnit<W::level2> >&) = 0;

    Winner executeBattle()
    {
        Winner ans = w_.executeBattle();
        if (ans == DRAW)
            return ans;
        if (ans == FIRST)
        {
            winner1(w_.getFirst());
            loser2(w_.getSecond());
        }
        else
        {
            loser1(w_.getFirst());
            winner2(w_.getSecond());
        }
        return ans;
    }

    std::shared_ptr<ArmyUnit<W::level1> > getFirst() const
    {
        return w_.getFirst();
    }

    std::shared_ptr<ArmyUnit<W::level2> > getSecond() const
    {
        return w_.getSecond();
    }

    static const int level1 = W::level1;
    static const int level2 = W::level2;
protected:
    W w_;
};

template<typename W>
class BasicDecorator : public Decorator<W>
{
public:
    BasicDecorator(const W &w) : Decorator<W>(w) {}

    virtual void winner1(const std::shared_ptr<ArmyUnit<W::level1> > &au) override
    {
        au->addMoney(10);
    }

    virtual void winner2(const std::shared_ptr<ArmyUnit<W::level2> > &au) override
    {
        au->addMoney(10);
    }

    virtual void loser1(const std::shared_ptr<ArmyUnit<W::level1> > &au) override
    {
        au->addMoney(-10);
    }

    virtual void loser2(const std::shared_ptr<ArmyUnit<W::level2> > &au) override
    {
        au->addMoney(-10);
    }
};