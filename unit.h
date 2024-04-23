#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsPixmapItem>
#include <ctime>
#include <random>

class Unit : public QGraphicsPixmapItem
{
public:
    Unit(QGraphicsScene*, bool**, std::pair<int,int>** map);
    void Spawn(int);
    void Spawn(int,int x,int y);
    void drawUnit();
    void SetAttributes();
private:
    int id;
    int attack;
    int hp;
    int actions;
    QGraphicsScene* scene;
    bool **used;
    std::pair<int,int> **map;
};

#endif // UNIT_H
