#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QPushButton>
#include <button.h>
#include <QFont>
#include "world.h"
#include "log.h"
#include "player.h"

#pragma once



class Game : public QGraphicsView
{
    Q_OBJECT
public:
    //Costructors
    Game(QWidget* parent=NULL);

    //Methods

    //Attributes

    //Fields
    static long long whosTurn;
    //Slots
public slots:
    void next_turn();
private:
    QGraphicsScene* scene;
    QGraphicsPolygonItem* select_block;
    QGraphicsPolygonItem* select_unit;
    QGraphicsTextItem *block_info;
    QGraphicsTextItem *turn_info;
    QGraphicsTextItem *res_info;

    Button *skip_button;

    World* map;
    QVector<Player *>players;


};

#endif // GAME_H
