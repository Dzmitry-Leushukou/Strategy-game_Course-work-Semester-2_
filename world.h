#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsItem>
#include <QImage>
#include "block.h"
#include "aabb.h"

class Game;
class World : public QGraphicsItem
{
public:
    World(Game *game);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void paintBackground(QPainter *painter);
    void update(int delta);

    QString name = "starter";

    const static int WIDTH = 2048, HEIGHT = 128;
    QImage spritesheet;

    Block*** world;
    Game *game;
    bool validBounds(int x, int y);
    AABB collide(QRectF rect);
    void setBlock(Block *block);
    Block *getBlock(int x, int y);
    int height(int x);
    void generate();
};

#endif // WORLD_H
