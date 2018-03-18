# include "AbstractRace.h"

AbstractUnit::AbstractUnit(const std::shared_ptr<const AbstractUnit> &other):
    size_(other->size_) {}
AbstractUnit::AbstractUnit(Size size) : size_(size) {}
AbstractUnit::~AbstractUnit(){}

Orc::Orc() : AbstractUnit(Size::MEDIUM), color_(Color::GREEN), wool_(Wool::MEDIUM) {}
Orc::Orc(const std::shared_ptr<const Orc> &other):
    AbstractUnit(other), color_(other->color_), wool_(other->wool_) {}
Orc::Orc(Size size, Color color, Wool wool) : AbstractUnit(size), color_(color), wool_(wool) {}

Human::Human() : AbstractUnit(Size::MEDIUM), skin_(Skin::WHITE), hair_(Hair::BLACK) {}
Human::Human(const std::shared_ptr<const Human> &other): 
    AbstractUnit(other), skin_(other->skin_), hair_(other->hair_) {}
Human::Human(Size size, Skin skin, Hair hair) : AbstractUnit(size), skin_(skin), hair_(hair) {}