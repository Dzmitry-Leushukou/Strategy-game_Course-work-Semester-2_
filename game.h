#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "block.h"

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
    //Map* map; TODO
    short int whosTurn;
private:

};

#endif // GAME_H
