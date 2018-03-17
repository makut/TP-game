# pragma once
# include "Game.h"
# include <vector>
typedef size_t Coordinate_t;
typedef std::vector<std::vector<Coordinate_t> > Table_t;

class Position
{
public:
    Position(Coordinate_t, Coordinate_t);
    ~Position() = default;
private:
    Coordinate_t x_, y_;
};

class Field
{
public:
private:
    Table_t table_;
};
