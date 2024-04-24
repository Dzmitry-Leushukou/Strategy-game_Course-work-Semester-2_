#include "world.h"
//#include "game.h"





World::World(QGraphicsScene* &scene, QWidget* w, QGraphicsPolygonItem * select)
{
    this->scene=scene;
    this->select=select;
    qDebug()<<scene;
    widget=w;
    gen.seed(time(0));

    placeBlocks();
    normalise_world();

    scene->addItem(select);

    contenent_distribution();
}

void World::placeBlocks()
{
    unitstay=new bool*[1440/32];
    map = new std::pair<int,int>*[1440/32];
    height_map=new int*[1440/32];

    for(int i=0;i<1440/32;i++)
    {
        unitstay[i]=new bool[896/32];
        map[i]=new std::pair<int,int>[896/32];
        height_map[i]=new int[896/32];

        for(int j=0;j<896/32;j++)
        {
            unitstay[i][j]=false;

            short id=generate_block(),res=gen_res(id);
            if(i==0||i==1440/32-1||j==0||j==896/32-1)
                id=0,res=gen_res(id);
            map[i][j]={id,res};

            Block* block=new Block(id,res, widget,scene,select);

            height_map[i][j]=block->getHeight();

            block->setPos(32*i,32*j);
            blocks.push_back(block);
            scene->addItem(block);
        }

    }
}

short World::generate_block()
{

    //Water gen
    short g=gen()%8;

    if(g<1)
    {
        return 0;
    }

    //Other block type gen
    g=gen()%10;

    if(g>0)
        return 1;
    return 2;
}

short World::gen_res(short id)
{
    short res;
    //0 - nothing 1 - wheat 2 - stone 3 - iron 4 - fish
    if(id==0)
    {
        res=gen()%10;

        if(res!=4)
            return 0;

        return 4;

    }
    if(id==1)
    {
        res=gen()%6;

        if(res==0)
        {
            res=gen()%10;

            if(res<6)
                return 1;

            if(res<8)
                return 2;

                return 3;
        }

        return 0;
    }
    if(id==2)
    {
        res=gen()%3;

        if(res==0)
        {
            res=gen()%10;

            if(res<6)
                return 2;

            return 3;
        }

        return 0;
    }
}

void World::normalise_world()
{

    add_log("Normalise world started");
    for(int i=1;i<1440/32-1;i++)
        for(int j=1;j<896/32-1;j++)
        {

            if(height_map[i][j]==2)
            if(i+1<1440/32&&abs(height_map[i][j]-height_map[i+1][j])>1)
            {
                if(i-1>=0&&abs(height_map[i][j]-height_map[i-1][j])>1)
                {
                    if(j-1>=0&&abs(height_map[i][j]-height_map[i][j-1])>1)
                    {
                        if(j+1<896/32&&abs(height_map[i][j]-height_map[i][j+1])>1)
                        {
                            getBlock(i*32,j*32)->change(1);
                            add_log("Normalise: "+std::to_string(i)+" "+std::to_string(j));
                        }
                    }
                }
            }

        }
    add_log("Normalise world ended");

}

void World::contenent_name_creator()
{
    for(int i=0;i<35;i++)
        for(int j=i,n=35;n!=0;n--,j++)
        {
            contenent_name[i*35+35-n]=s1[j]+s2[i];
        }
}

void World::contenent_distribution()
{
    contenent_name_creator();

    bool **used=new bool*[1440/32];
    for(int i=0;i<1440/32;i++)
    {

        used[i]=new bool[896/32];
        for(int j=0;j<896/32;j++)
        {

            used[i][j]=false;
        }

    }

    int num=-1;
    for(int i=1;i<1440/32;i++)
    {
        for(int j=1;j<896/32;j++)
        {
            if(!used[i][j]&&map[i][j].first!=0)
            {
                num++;
                std::queue<std::pair<int,int>>q;
                q.push({i,j});
                used[i][j]=true;
                while(!q.empty())
                {
                    std::pair<int,int>pos=q.front();
                    q.pop();

                    getBlock(pos.first*32,pos.second*32)->setContinent(contenent_name[num]);
                    if(map[pos.first-1][pos.second].first>0&&used[pos.first-1][pos.second])
                    {
                        used[pos.first-1][pos.second]=true;
                        q.push({pos.first-1,pos.second});
                    }
                    if(map[pos.first+1][pos.second].first>0&&!used[pos.first+1][pos.second])
                    {
                        used[pos.first+1][pos.second]=true;
                        q.push({pos.first+1,pos.second});
                    }
                    if(map[pos.first][pos.second+1].first>0&&!used[pos.first][pos.second+1])
                    {
                        used[pos.first][pos.second+1]=true;
                        q.push({pos.first,pos.second+1});
                    }
                    if(map[pos.first][pos.second-1].first>0&&!used[pos.first][pos.second-1])
                    {
                        used[pos.first][pos.second-1]=true;
                        q.push({pos.first,pos.second-1});
                    }
                }
            }
        }

    }

    for(int i=0;i<1440/32;i++)
        delete[] used[i],used[i]=nullptr;
    delete[] used;
    used=nullptr;
}

QList<Block *> World::getBlocks()
{
    return blocks;
}

Block *World::getBlock(int x, int y)
{
    x/=32;
    y/=32;
    int ind=y+std::max(x-1,0)*(896/32);
    return blocks[ind];
}

bool** World::getUnitstay()
{
    return unitstay;
}

std::pair<int, int> **World::getMap()
{
    return map;
}
