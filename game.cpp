#include "game.h"

Game::Game(QWidget *parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1440,896);
    setFixedSize(1440,896);
    setScene(scene);

    add_log("Game scene was created");

}

void Game::start()
{
    map = new World(scene,this);
    //map->placeBlocks();

    add_log("Map was generated");
}
