# pragma once
# include <iostream>
# include "Army.h"

template<typename W>
class Decorator
{
public:
    using decorated_type = W;

    explicit Decorator(const decorated_type &w) : w_(w) {}

    virtual void winner1(ArmyUnit<decorated_type::level1>*) = 0;
    virtual void winner2(ArmyUnit<decorated_type::level2>*) = 0;
    virtual void loser1(ArmyUnit<decorated_type::level1>*) = 0;
    virtual void loser2(ArmyUnit<decorated_type::level2>*) = 0;

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

    ArmyUnit<decorated_type::level1>* getFirst() const
    {
        return w_.getFirst();
    }

    ArmyUnit<decorated_type::level2>* getSecond() const
    {
        return w_.getSecond();
    }

    constexpr static const int level1 = decorated_type::level1;
    constexpr static const int level2 = decorated_type::level2;
protected:
    W w_;
};

template<typename W> Decorator(const Decorator<W>&) -> Decorator<Decorator<W> >;

template<typename W>
class BasicDecorator : public Decorator<W>
{
public:
    using decorated_type = W;

    explicit BasicDecorator(const decorated_type &w) : Decorator<decorated_type>(w) {}

    virtual void winner1(ArmyUnit<decorated_type::level1> *au) override
    {
        au->addMoney(10);
    }

    virtual void winner2(ArmyUnit<decorated_type::level2> *au) override
    {
        au->addMoney(10);
    }

    virtual void loser1(ArmyUnit<decorated_type::level1> *au) override
    {
        au->addMoney(-10);
    }

    virtual void loser2(ArmyUnit<decorated_type::level2> *au) override
    {
        au->addMoney(-10);
    }
};

template<typename W> BasicDecorator(const BasicDecorator<W>&) -> BasicDecorator<BasicDecorator<W> >;