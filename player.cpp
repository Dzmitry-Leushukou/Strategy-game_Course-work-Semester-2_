#include "player.h"

Player::Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map)
{
    this->scene=scene;
    this->used=used;
    this->map=map;
    Unit* u=new Unit(scene,used,map);
    u->Spawn(3);
    units.push_back(u);
    scene->addItem(u);
}

QList<Unit *> Player::getUnits() const
{
    return units;
}
