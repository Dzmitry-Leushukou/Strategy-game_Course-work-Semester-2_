#include "city.h"

city::city(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    is_city=false;
    owner=-1;

    setFlag(ItemIsSelectable, false);
    setFlag(ItemIsMovable, false);
}

void city::create(short owner)
{
    is_city=true;
    this->owner=owner;
    switch(owner)
    {
    case 0:
        setPixmap(QPixmap(":game/resource/city.png"));
        break;
    case 1:
        setPixmap(QPixmap(":game/resource/city2.png"));
        break;
    case 2:
        setPixmap(QPixmap(":game/resource/city3.png"));
        break;
    case 3:
        setPixmap(QPixmap(":game/resource/city4.png"));
        break;
    }
}

void city::change_owner(short owner)
{
    this->owner=owner;
    setPixmap(QPixmap(":game/resource/city.png"));
}

void city::destroy()
{
    is_city=false;
    owner=-1;
}

bool city::getIs_city() const
{
    return is_city;
}

short city::getOwner() const
{
    return owner;
}

int city::getLevel() const
{
    return level;
}
