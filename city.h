#ifndef CITY_H
#define CITY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <queue>

#pragma once

class city:public QGraphicsPixmapItem
{
public:
    city(QGraphicsItem *parent=NULL);

    void create(short);
    void destroy();
    void check();
    void build(int id);
    void addHp();
    //Getters
    bool getIs_city() const;
    short getOwner() const;
    int getLevel() const;
    int getGrow_from() const;

    //Setters
    void setGrow_from(int newGrow_from);

    int getBuild_id() const;

    int getBuild_finish() const;

    int getHp() const;

private:
    bool is_city;
    short owner;
    int level=1;
    int hp=100;
    int grow_from=10;

    //bool buildings[];//What was built
    /*
    0 - Builder
    1 - Settler
    2 - Knight
    3 - Knight LVL 2
    */
    int build_id=4;//Id
    int build_finish=0;//When
};

#endif // CITY_H
