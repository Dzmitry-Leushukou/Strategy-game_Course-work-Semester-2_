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
    void StartGame();

    //Attributes

    //fields

private:
    QGraphicsScene* scene;
    QGraphicsPolygonItem* select_block;
    QGraphicsPolygonItem* select_unit;
    QGraphicsTextItem *block_info;

    World* map;
    Player *player;
    QList<Enemy*>enemies;

    long long whosTurn;
};

#endif // GAME_H
