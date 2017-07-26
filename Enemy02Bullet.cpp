
#include "Enemy02Bullet.h"
Enemy02Bullet::Enemy02Bullet()
{

}

Enemy02Bullet::~Enemy02Bullet()
{
    cout<<"Bullet Deallocated"<<endl;										// Bullet destructor
}

Enemy02Bullet::Enemy02Bullet(LTexture* image, float x, float y)							// Bullet constructor
{
    LSprite = image;												// Loads sprite sheet
    tag=-3;
    bsprite[ 0 ].x = 140;												// Loads first bullet sprite frame
    bsprite[ 0 ].y = 133;
    bsprite[ 0 ].w = 43;
    bsprite[ 0 ].h = 14;

    this->Position.x = x;															// Set x location
    this->Position.y = y;															// Set y location

    this->width = bsprite[ 0 ].w;										// Set sprite width
    this->height = bsprite[ 0 ].h;										// Set sprite height

    friction = 0.95f;														// Set friction
    speedx = 0;																// Set horizontal speed
    speedy = 0;																// Set vertical speed
    alive  = true;															// Set alive
}

void Enemy02Bullet::Move()
{
    speedx = 5;															// Change vertical speed to 30 units/s
    Position.x-=speedx;																// Change y location based on speed
}

void Enemy02Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    LSprite->Render( Position.x - width/2, Position.y - height/2, &bsprite[0], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
}
