#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
//#include <QGraphicsScene >
#include "map.h"

#pragma once

//class View;
class Game : public QGraphicsView
{
public:
    //Costructors
    Game(QWidget* parent=NULL);

    //Methods
    void start();

    //Attributes
    QGraphicsScene* scene;
    Map* map;
    short int whosTurn;

private:

};

#endif // GAME_H
