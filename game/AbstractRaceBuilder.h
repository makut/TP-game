# pragma once
# include "AbstractRace.h"

class AbstractUnitBuilder
{
protected:
    AbstractUnitBuilder();
    AbstractUnit::Size size_;
public:
    virtual ~AbstractUnitBuilder() = 0;

    virtual void reset() = 0;
    void setSize(AbstractUnit::Size);
    virtual std::shared_ptr<AbstractUnit> getResult() const = 0;

    static const AbstractUnit::Size DEFAULT_SIZE;
};

class OrcBuilder : public AbstractUnitBuilder
{
public:
    OrcBuilder();
    ~OrcBuilder() = default;

    virtual void reset() override;
    void setColor(Orc::Color);
    void setWool(Orc::Wool);
    virtual std::shared_ptr<AbstractUnit> getResult() const override;

    static const Orc::Color DEFAULT_COLOR;
    static const Orc::Wool DEFAULT_WOOL;
private:
    Orc::Color color_;
    Orc::Wool wool_;
};

class HumanBuilder : public AbstractUnitBuilder
{
public:
    HumanBuilder();
    ~HumanBuilder() = default;

    virtual void reset() override;
    void setSkin(Human::Skin);
    void setHair(Human::Hair);
    virtual std::shared_ptr<AbstractUnit> getResult() const override;

    static const Human::Skin DEFAULT_SKIN;
    static const Human::Hair DEFAULT_HAIR;
private:
    Human::Skin skin_;
    Human::Hair hair_;
};