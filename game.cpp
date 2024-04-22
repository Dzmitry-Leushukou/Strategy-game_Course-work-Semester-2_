#include "game.h"

Game::Game(QWidget *parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1440,900);
    setFixedSize(1440,900);
    setScene(scene);


}

void Game::start()
{
    map = new Map(scene);
    map->placeBlocks();
}
