# include "AbstractRaceBuilder.h"

const AbstractUnit::Size AbstractUnitBuilder::DEFAULT_SIZE = AbstractUnit::Size::MEDIUM;
const Orc::Color OrcBuilder::DEFAULT_COLOR = Orc::Color::GREEN;
const Orc::Wool OrcBuilder::DEFAULT_WOOL = Orc::Wool::MEDIUM;
const Human::Skin HumanBuilder::DEFAULT_SKIN = Human::Skin::WHITE;
const Human::Hair HumanBuilder::DEFAULT_HAIR = Human::Hair::BLACK;

AbstractUnitBuilder::AbstractUnitBuilder() : size_(DEFAULT_SIZE) {}
AbstractUnitBuilder::~AbstractUnitBuilder(){}

void AbstractUnitBuilder::setSize(AbstractUnit::Size size)
{
    size_ = size;
}

OrcBuilder::OrcBuilder(): 
    AbstractUnitBuilder(), color_(DEFAULT_COLOR), wool_(DEFAULT_WOOL) {}

HumanBuilder::HumanBuilder():
    AbstractUnitBuilder(), skin_(DEFAULT_SKIN), hair_(DEFAULT_HAIR) {}

void OrcBuilder::reset()
{
    size_ = DEFAULT_SIZE;
    color_ = DEFAULT_COLOR;
    wool_ = DEFAULT_WOOL;
}

void HumanBuilder::reset()
{
    size_ = DEFAULT_SIZE;
    skin_ = DEFAULT_SKIN;
    hair_ = DEFAULT_HAIR;
}

void OrcBuilder::setColor(Orc::Color color)
{
    color_ = color;
}

void OrcBuilder::setWool(Orc::Wool wool)
{
    wool_ = wool;
}

void HumanBuilder::setSkin(Human::Skin skin)
{
    skin_ = skin;
}

void HumanBuilder::setHair(Human::Hair hair)
{
    hair_ = hair;
}

std::shared_ptr<AbstractUnit> OrcBuilder::getResult() const
{
    return std::shared_ptr<Orc>(new Orc(size_, color_, wool_));
}

std::shared_ptr<AbstractUnit> HumanBuilder::getResult() const
{
    return std::shared_ptr<Human>(new Human(size_, skin_, hair_));
}
