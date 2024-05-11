#ifndef WORLD_H
#define WORLD_H

#include <QList>
#include "block.h"
#include <QGraphicsScene>
#include <ctime>
#include <random>
#include <QWidget>
#include "city.h"
#include "player.h"
#include <queue>


#pragma once

class World
{
public:
    //QTimer * timer;
    //Constructors
    World(QGraphicsScene*, QWidget*,QGraphicsPolygonItem*,QGraphicsPolygonItem *, QGraphicsTextItem *,QVector<Player*> &players_);

    //Methods
    void placeBlocks();
    short generate_block();
    short gen_res(short);
    void normalise_world();
    void contenent_name_creator();
    void contenent_distribution();
    void set_player(Player * pl);
    //Getters
    QList<Block*>getBlocks();
    Block* getBlock(int,int);
    bool** getUnitstay();
    std::pair<int,int> **getMap();

    //Setters


private:

    QVector<Player*>& players;
    QList<QList<Block*>>blocks;
    QList<city*>cities;
    QGraphicsScene *scene;
    QWidget *widget;
    std::mt19937 gen;
    QGraphicsPolygonItem * select;
    QGraphicsTextItem * block_info;


    bool **unitstay;
    int** height_map;
    std::pair<int,int> **map;
    QGraphicsPolygonItem * select_unit;
    const std::string s1[35]={"Eur","As","Got","Wer","Rat","Pol","Akl","Ban","Bel","Rus","Ukr","Pl","Lith","Lath","Garf","Yellow","Plot","Cher","Quar","Wed","Ear","Tir","Unit","Is","And","Sam","Frank","Ger","Hes","Jefr","Ken","Link","Zyran","Xer","Cosc"};
    const std::string s2[35]={"ope","asia","stone","ella","anna","land","easy","elly","yard","york","unia","uran","anian","org","onion","axia","asird","arc","ocraine","erid","opposite","ugoria","agoria","egoria","ugonist","agonist","yniel","uniel","enie","uland","eland","early","airan","ure","ore"};
    std::string contenent_name[35*35+1];
};

#endif // WORLD_H
