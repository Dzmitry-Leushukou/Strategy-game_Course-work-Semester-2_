#ifndef GAME_H
#define GAME_H

#include "camera.h"
#include "world.h"
#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
//#include "player.h"

#pragma once

class View;
class Game
{
public:
    Game(View *view);
    void load();
    void update();
    int WIDTH,HEIGHT;

    Camera *camera;
    World *world;
    //Player *player;
    View *view;
    QGraphicsScene *scene;

private:

};

#endif // GAME_H
