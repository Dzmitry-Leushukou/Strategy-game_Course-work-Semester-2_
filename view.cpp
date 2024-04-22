#include "view.h"
#include <QOpenGLWidget>
#include <QDebug>
#include "block.h"
#include <QApplication>

View::View(QGraphicsScene *scene)
{
    setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setViewport(new QOpenGLWidget(this));
    setMouseTracking(true);

    game=new Game(this);
    game->load();
}

QGraphicsScene *View::get_scene()
{
    return this->scene();
}

void View::update()
{
    game->update();
    this->scene()->update(QRectF(0, 0, game->WIDTH, game->HEIGHT));
}

void View::mousePressEvent(QMouseEvent *event)
{
    /*
    if(event->button() == Qt::LeftButton)
        game->camera->clickLeft = true;
    if(event->button() == Qt::RightButton)
        game->camera->clickRight = true;
*/
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
    /*
    if(event->button() == Qt::LeftButton)
        game->camera->clickLeft = false;
    if(event->button() == Qt::RightButton)
        game->camera->clickRight = false;
*/
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    // game->camera->mouse = event->pos();
}
