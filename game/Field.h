# pragma once
# include <memory>
# include <vector>
typedef size_t Coordinate;

class Position
{
public:
    Position(Coordinate, Coordinate);
    ~Position() = default;
    Coordinate getX() const;
    Coordinate getY() const;
private:
    Coordinate x_, y_;
};
