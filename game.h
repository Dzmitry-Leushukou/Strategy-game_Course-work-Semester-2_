#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "world.h"
#include "log.h"
#include "player.h"
#include "enemy.h"
#pragma once

//class View;
class Game : public QGraphicsView
{
public:
    //Costructors
    Game(QWidget* parent=NULL);

    //Methods
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //Attributes

    //fields

private:
    long long whosTurn;
    QGraphicsScene* scene;
    QGraphicsPolygonItem* select_block;
    QGraphicsPolygonItem* select_unit;
    World* map;
    void StartGame();
    Player *player;
    QList<Enemy*>enemies;
};

#endif // GAME_H
