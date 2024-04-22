#include "world.h"
#include "game.h"
#include <time.h>
#include <QPainter>
//#include <QGraphicsScene>

World::World(Game *game)
{
    this->game=game;
    spritesheet.load("");

    game->addSceneItem(this);
}

QRectF World::boundingRect() const
{
    return QRectF(0, 0, Block::SIZE*WIDTH, Block::SIZE*HEIGHT);
}

QPainterPath World::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void World::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int bx = game->camera->getPosition().rx()/Block::SIZE;
    int by = game->camera->getPosition().ry()/Block::SIZE;
    if(bx < 0) bx = 0;
    if(by < 0) by = 0;
    int fx = bx+game->WIDTH/Block::SIZE+2;
    int fy = by+game->HEIGHT/Block::SIZE+2;
    if(fx>WIDTH) fx = WIDTH;
    if(fy>HEIGHT) fy = HEIGHT;



    for(int x = bx; x < fx; x++){
        for(int y = by; y < fy; y++){
            Block *block = world[x][y];
            if(block != NULL){
                block->update();

                qreal size = Block::SIZE;
                QRectF bounds = QRectF(block->getRX() - game->camera->getPosition().rx(),
                                       block->getRY() - game->camera->getPosition().ry(),
                                       size, size);
                painter->drawImage(bounds, spritesheet, block->texture);

            }
        }
    }
}


void World::update(int delta)
{
//    game->camera->pointingOnEntity = false;
//    for(int i = 0; i < entities->length(); i++) {
//        Entity *entity = entities->at(i);

        int DISTANCE_RESERVE = 1000;
/*        if(entity->x+entity->width > game->camera->pos.x() - DISTANCE_RESERVE && entity->x < game->camera->pos.x()+game->WIDTH + DISTANCE_RESERVE &&
            entity->y+entity->height > game->camera->pos.y() - DISTANCE_RESERVE && entity->y < game->camera->pos.y()+game->HEIGHT + DISTANCE_RESERVE){
            entity->update(delta);
*/

            if(game->camera->clickLeft){
                QPointF mouse = game->camera->mouse;
                int rx = mouse.rx() + game->camera->pos.rx(),
                    ry = mouse.ry() + game->camera->pos.ry();
 /*               if(game->player->canReach(rx, ry)){
                    if(entity->rx+entity->width > mouse.rx() && entity->rx < mouse.rx() && entity->ry+entity->height > mouse.ry() && entity->ry < mouse.ry()){
                        entity->hit();
                        game->player->handshake();
                        game->camera->pointingOnEntity = true;
                    }
                }
            }
        }*/
    }
}

void World::generate()
{
    //gen->generateWorld();
    //gen->generateVeins();
}


int World::height(int x)
{
    for(int y = 0; y < HEIGHT; y++){
        if(world[x][y] != NULL) return y;
    }
    return 0;
}

Block* World::getBlock(int x, int y)
{
    if(!validBounds(x, y)) return NULL;
    return world[x][y];
}

void World::setBlock(Block *block)
{
    //delete world[block->x][block->y];
    world[block->x][block->y] = block;
}

AABB World::collide(QRectF rect)
{
    int bx = rect.x()/Block::SIZE;
    int by = rect.y()/Block::SIZE;
    if(bx < 0) bx = 0;
    if(by < 0) by = 0;
    int fx = (bx+rect.width()/Block::SIZE)+game->WIDTH/Block::SIZE+1;
    int fy = (by+rect.height()/Block::SIZE)+game->HEIGHT/Block::SIZE+1;
    if(fx>WIDTH) fx = WIDTH;
    if(fy>HEIGHT) fy = HEIGHT;

    for(int x = bx; x < fx; x++){
        for(int y = by; y < fy; y++){
            Block *block = world[x][y];
            if(block != NULL){
                QRectF blockBox = QRectF(block->getRX(), block->getRY(), Block::SIZE, Block::SIZE);
                AABB collision = AABB(rect, blockBox);
                if(collision.collide)
                    return collision;
            }
        }
    }
    return AABB(rect);
}

bool World::validBounds(int x, int y)
{
    if(x < 0) return false;
    if(y < 0) return false;
    if(x >= WIDTH) return false;
    if(y >= HEIGHT) return false;
    return true;
}
