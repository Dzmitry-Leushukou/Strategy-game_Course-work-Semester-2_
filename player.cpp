#include "player.h"

Player::Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *select,QGraphicsPolygonItem *select_block)
{
    this->scene=scene;
    this->used=used;
    this->map=map;
    this->select_block=select_block;
    Unit* u=new Unit(scene,used,map,select,select_block);
    u->Spawn(3);
    units.push_back(u);
    scene->addItem(u);
    scene->addItem(select);
}

QList<Unit *> Player::getUnits() const
{
    return units;
}
