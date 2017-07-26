#include "Enemy1.h"
#include "player.h"
#include "bullet.h"
using namespace std;
Enemy01::Enemy01()
{

}


Enemy01::~Enemy01()
{
    cout<<"Enemy Deallocated"<<endl;										// Enemy destructor
}

Enemy01::Enemy01(LTexture* image, float x, float y)										// Enemy constructor
{
    LSprite = image;												// Load sprite sheet
    tag = 3;
    //Frame 0
    sprite.x = 0;												// Load first enemy sprite frame
    sprite.y = 0;
    sprite.w = 65;
    sprite.h = 95;


    this->Position.x = x;
    this->Position.y = y;														// Set y location

    this->width = sprite.w;										// Set sprite width
    this->height = sprite.h;										// Set sprite height

    friction = 0;														// Set friction
    speedx = 0;																// Set horizontal speed
    speedy = 0;																// Set vertical speed
    alive  = true;															// Set alive
    time = 0 ;
}


void Enemy01::Move(int x,int mv)
{
    this->state=x;
    if (x==0)
    {
        while (Position.y<250)
        {

            speedy = 10;
            Position.y+=speedy;
        }
    }
    else
    {
        while (Position.y>450)
        {

            speedy = -10;
            Position.y+=speedy;

        }
    }
    time=0;
}


void Enemy01::Move()
{
    if (Position.y<250)
    {
        Position.y = 250;
    }
    else if(Position.y>450)
    {
        Position.y = 450;
    }
    speedy = speedy * friction;
    if (time>10 && state == 0)
        {
            speedy=2.0f;
        }
    else if (time>10 && state == 1)
    {
        speedy=-2.0f;
    }
    Position.y += speedy;
    time++;
}



void Enemy01::Render(long int& frame, SDL_Renderer* gRenderer)
{
    LSprite->Render( Position.x - width/2, Position.y - height/2, &sprite, 0.0, NULL, SDL_FLIP_NONE, gRenderer );			// Render enemy plane
}

void Enemy01::SetAlive(bool a)
{
    alive = a;

}


bool Enemy01::BULLETCOLL(unit* dave)
{
    bool fire = false;
    if (dave->GetPoint().y-30<=this->Position.y + 50)
    {
       fire = true;
    }
    else
    {
        fire = false;
    }
    return fire;
}


