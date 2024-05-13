#ifndef PLAYER_H
#define PLAYER_H
#include "unit.h"
#include <QList>
#include "button.h"
#pragma once

class Player
{
public:
    Player(QGraphicsScene *&scene, int ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *select,QGraphicsPolygonItem *,Button *& action_button,int);
    QList<Unit *> getUnits() const;
    bool move_unit(QPointF pos, int x1,int y1);
    void show_units();
    bool getLose() const;
    Unit* getUnit(QPointF);
    QVector<int>resource_amount={0,0,0,0,0};
private:
    QList<Unit*>units;
    QGraphicsScene *scene;
    int ** used;
    std::pair<int,int>** map;
    QGraphicsPolygonItem * select;
    QGraphicsPolygonItem * select_block;

    int number;
    bool lose=false;

    Button * action_button;


};

#endif // PLAYER_H
