#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QPushButton>
#include <button.h>
#include "world.h"
#include "log.h"
#include "player.h"

#pragma once


class Game : public QGraphicsView
{
public:
    //Costructors
    Game(QWidget* parent=NULL);

    //Methods
//    void StartGame();

    //Attributes

    //Fields

    //Slots
public slots:
    void next_turn();
private:
    QGraphicsScene* scene;
    static QGraphicsPolygonItem* select_block;
    static QGraphicsPolygonItem* select_unit;
    QGraphicsTextItem *block_info;

    Button *skip_button;

    World* map;
    //QVector<Player *>players;

    long long whosTurn;
};

#endif // GAME_H
