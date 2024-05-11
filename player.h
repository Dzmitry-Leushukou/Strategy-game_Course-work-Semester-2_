#ifndef PLAYER_H
#define PLAYER_H
#include "unit.h"
#include <QList>

#pragma once

class Player
{
public:
    Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *select,QGraphicsPolygonItem *);
    QList<Unit *> getUnits() const;
    bool move_unit(QPointF pos, int x1,int y1);
    void show_units();
    bool getLose() const;

private:
    QList<Unit*>units;
    QGraphicsScene *scene;
    bool ** used;
    std::pair<int,int>** map;
    QGraphicsPolygonItem * select;
    QGraphicsPolygonItem * select_block;

    bool lose=false;
};

#endif // PLAYER_H
