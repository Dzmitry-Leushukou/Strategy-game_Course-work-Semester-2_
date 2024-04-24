#include "player.h"

Player::Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *select)
{
    this->scene=scene;
    this->used=used;
    this->map=map;

    Unit* u=new Unit(scene,used,map,select);
    u->Spawn(3);
    units.push_back(u);
    scene->addItem(u);
    scene->addItem(select);
}

QList<Unit *> Player::getUnits() const
{
    return units;
}
