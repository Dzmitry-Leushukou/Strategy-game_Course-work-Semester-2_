#include "player.h"

Player::Player() {}

QList<Unit *> Player::getUnits() const
{
    return units;
}
