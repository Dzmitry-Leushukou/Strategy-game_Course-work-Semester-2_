#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "world.h"
#include "log.h"
#include "player.h"
// #include "enemy.h"
#pragma once

//class View;
class Game : public QGraphicsView
{
public:
    //Costructors
    Game(QWidget* parent=NULL);

    //Methods


    //Attributes

    short int whosTurn;

private:
    QGraphicsScene* scene;
    World* map;
    void StartGame();
};

#endif // GAME_H
