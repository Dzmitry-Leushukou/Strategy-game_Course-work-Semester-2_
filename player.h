#ifndef PLAYER_H
#define PLAYER_H
#include "unit.h"
#include <QList>
class Player
{
public:
    Player();
    QList<Unit *> getUnits() const;

private:
    QList<Unit*>units;
};

#endif // PLAYER_H
