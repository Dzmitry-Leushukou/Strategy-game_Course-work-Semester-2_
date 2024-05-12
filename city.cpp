#include "city.h"

city::city()
{
    is_city=false;
    owner=-1;
}

void city::create(short owner)
{
    is_city=true;
    this->owner=owner;
}

void city::change_owner(short owner)
{
    this->owner=owner;
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
