# pragma once
# include "Game.h"

class AbstractUnit
{
public:
    virtual ~AbstractUnit() = 0;
    enum class Size {BIG, MEDIUM, SMALL};
protected:
    AbstractUnit(Size);
    explicit AbstractUnit(const std::shared_ptr<const AbstractUnit>&);
private:
    Size size_;
};

class Orc : public AbstractUnit
{
public:
    Orc();
    explicit Orc(const std::shared_ptr<const Orc>&);
    ~Orc() = default;
    enum class Color {GREEN, GRAY, RED, WHITE};
    enum class Wool {LONG, MEDIUM, SHORT};
private:
    Orc(Size, Color, Wool);
    Color color_;
    Wool wool_;
};

class Human : public AbstractUnit
{
public:
    Human();
    explicit Human(const std::shared_ptr<const Human>&);
    ~Human() = default;
    enum class Skin {BLACK, WHITE, BROWN};
    enum class Hair {WHITE, BLACK, BROWN};
private:
    Human(Size, Skin, Hair);
    Skin skin_;
    Hair hair_;
};