#ifndef PLAYER_H
#define PLAYER_H
#include "unit.h"
#include <QList>
class Player
{
public:
    Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *select,QGraphicsPolygonItem *);
    QList<Unit *> getUnits() const;
    void move_unit(QPointF pos, int x1,int y1);
    void show_units();
private:
    QList<Unit*>units;
    QGraphicsScene *scene;
    bool ** used;
    std::pair<int,int>** map;
    QGraphicsPolygonItem * select;
    QGraphicsPolygonItem * select_block;
};

#endif // PLAYER_H
