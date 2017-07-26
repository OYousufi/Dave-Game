#include"Enemy.h"


Enemy::Enemy()
{

}


Enemy::~Enemy()
{
    cout<<"Enemy Deallocated"<<endl;										// Enemy destructor
}

Enemy::Enemy(LTexture* image, float x, float y)										// Enemy constructor
{
    LSprite = image;												// Load sprite sheet

    tag = 2;

    //Frame 0
    sprite.x = 0;												// Load first enemy sprite frame
    sprite.y = 0;
    sprite.w = 95;
    sprite.h = 100;


    this->Position.x = x;
    this->Position.y = y;														// Set y location

    this->width = sprite.w;										// Set sprite width
    this->height = sprite.h;										// Set sprite height

    friction = 0.95f;														// Set friction
    speedx = 0;																// Set horizontal speed
    speedy = 0;																// Set vertical speed
    alive  = true;														// Set alive
    time=0;
}


void Enemy::Move(int x,int mv)
{
    this->state=x;
    if (x==0)
    {
        while (Position.x<250)
        {

            speedx = 10;
            Position.x+=speedx;
        }
    }
    else if(x==1)
    {
        while (Position.x>750)
        {

            speedx = -10;
            Position.x+=speedx;

        }
    }
    time=0;
}


void Enemy::Move()
{
    if(Position.x<250)
    {
        Position.x = 250;
    }
    else if(Position.x>750)
    {
        Position.x = 750;
    }
    speedx = speedx * friction;
    if (time>10 && state == 0)
        {
            speedx=2.0f;
        }
    else if (time>10 && state == 1)
    {
        speedx=-2.0f;
    }
    Position.x += speedx;
    time++;
}

void Enemy::Render(long int& frame, SDL_Renderer* gRenderer)
{
    LSprite->Render( Position.x - width/2, Position.y - height/2, &sprite, 0.0, NULL, SDL_FLIP_NONE, gRenderer );			// Render enemy plane
}

void Enemy::SetAlive(bool a)
{
    alive = a;
}


void Enemy::Fire()
{

}




