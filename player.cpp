#include "player.h"

Player::Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map)
{
    this->scene=scene;
    this->used=used;
    this->map=map;

    QPolygonF p({{0,0},{22,0},{22,22},{0,22}});
    select=new QGraphicsPolygonItem(p);
    select->setPen(QPen(QColor("red")));
    scene->addItem(select);
    select->setPos(-32,-32);

    Unit* u=new Unit(scene,used,map,select);
    u->Spawn(3);
    units.push_back(u);
    scene->addItem(u);
}

QList<Unit *> Player::getUnits() const
{
    return units;
}
