#ifndef VIEW_H
#define VIEW_H


#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsScene>
#include "game.h"

#pragma once

class View: public QGraphicsView
{

public:
    View(QGraphicsScene *scene);
    QGraphicsScene* get_scene();
public slots:
    void update();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Game *game;
};

#endif // VIEW_H
