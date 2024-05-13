#ifndef CITY_H
#define CITY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#pragma once

class city:public QGraphicsPixmapItem
{
public:
    city(QGraphicsItem *parent=NULL);

    void create(short);
    void change_owner(short);
    void destroy();

    bool getIs_city() const;
    short getOwner() const;

    //void build();
    int getLevel() const;

    int getGrow_from() const;

private:
    bool is_city;
    short owner;
    int level=1;
    int houses=5;
    int grow_from=10;
    //bool buildings[];//What was built
    /*
    0 - Builder
    1 - Settler
    2 - Knight
    3 - Knight LVL 2
    4 -
    */
    int build_now;//Id
    int build_finish;//When
};

#endif // CITY_H
