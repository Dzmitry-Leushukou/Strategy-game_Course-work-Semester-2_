#include "game.h"
#include "view.h"

Game::Game(View *view)
{
    this->view=view;
    this->scene=view->get_scene();
    QScreen *chosen = nullptr;
    QRect resolution={1,1,1023,600};
    this->WIDTH=resolution.width();
    this->HEIGHT=resolution.height();

}

void Game::load()
{
    //this->camera=new Camera(this);
    //this->world=new World(this);
    //this->world->load();

    //Texture Loading
}

void Game::update()
{
    //world->update(16);
    //camera->update();
}

void Game::addSceneItem(QGraphicsItem* t)
{
    scene->addItem(t);
}

