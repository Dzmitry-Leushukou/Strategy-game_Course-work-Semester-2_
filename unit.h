#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsPixmapItem>
#include <ctime>
#include <random>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Unit : public QGraphicsPixmapItem
{
public:
    Unit(QGraphicsScene*&, bool**, std::pair<int,int>** map, QGraphicsPolygonItem *&,QGraphicsPolygonItem *& );
    void Spawn(int);
    void Spawn(int,int x,int y);
    void drawUnit();
    void SetAttributes();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void move(int x, int y);
    void hide_select();
    bool getMoves() const;

    void setMoves(bool newMoves);

private:
    int id;
    int attack;
    int hp;
    int actions;
    bool moves;
    //int moves;
    QGraphicsScene* scene;
    bool **used;
    std::pair<int,int> **map;
    QGraphicsPolygonItem * select;
    QGraphicsPolygonItem * select_block;
};

#endif // UNIT_H
