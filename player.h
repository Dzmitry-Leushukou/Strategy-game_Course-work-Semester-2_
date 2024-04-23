#ifndef PLAYER_H
#define PLAYER_H
#include "unit.h"
#include <QList>
class Player
{
public:
    Player(QGraphicsScene *scene, bool ** used,  std::pair<int,int>** map);
    QList<Unit *> getUnits() const;

private:
    QList<Unit*>units;
    QGraphicsScene *scene;
    bool ** used;
    std::pair<int,int>** map;
};

#endif // PLAYER_H
