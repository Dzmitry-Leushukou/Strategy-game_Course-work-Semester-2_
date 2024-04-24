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

    QPolygonF p({{0,0},{32,0},{32,32},{0,32}});
    select_block=new QGraphicsPolygonItem(p);
    select_block->setPen(QPen(QColor("yellow")));

    select_block->setPos(-32,-32);

    QPolygonF p1({{0,0},{22,0},{22,22},{0,22}});
    select_unit=new QGraphicsPolygonItem(p1);
    select_unit->setPen(QPen(QColor("red")));
    select_unit->setPos(-32,-32);

    map = new World(scene,this,select_block);

    add_log("Map was generated");

    player=new Player(scene,map->getUnitstay(), map->getMap(),select_unit);


}

void Game::StartGame()
{
    //for(int i=0;i<3;i++)
    //Enemy[i].spawn();
}
