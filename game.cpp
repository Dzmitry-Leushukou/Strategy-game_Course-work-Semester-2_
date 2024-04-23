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

    map = new World(scene,this);

    add_log("Map was generated");

    player=new Player(scene,map->getUnitstay(), map->getMap());

}

void Game::StartGame()
{
    //for(int i=0;i<3;i++)
    //Enemy[i].spawn();
}
