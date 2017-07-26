
#include "Enemy1Bullet.h"
Enemy1Bullet::Enemy1Bullet()
{

}

Enemy1Bullet::~Enemy1Bullet()
{
    cout<<"Bullet1 Deallocated"<<endl;										// Bullet destructor
}

Enemy1Bullet::Enemy1Bullet(LTexture* image, float x, float y)							// Bullet constructor
{
    LSprite = image;												// Loads sprite sheet

    tag=-2;

    bsprite[ 0 ].x = 0;												// Loads first bullet sprite frame
    bsprite[ 0 ].y = 138;
    bsprite[ 0 ].w = 29;
    bsprite[ 0 ].h = 22;
//
//    bsprite[ 1 ].x = 550;												// Loads first bullet sprite frame
//    bsprite[ 1 ].y = 110;
//    bsprite[ 1 ].w = 25;
//    bsprite[ 1 ].h = 25;
//
//
//    bsprite[ 2 ].x = 585;												// Loads second bullet sprite frame
//    bsprite[ 2 ].y = 110;
//    bsprite[ 2 ].w = 20;
//    bsprite[ 2 ].h = 30;
//
//    bsprite[ 3 ].x = 620;												// Loads third bullet sprite frame
//    bsprite[ 3 ].y = 110;
//    bsprite[ 3 ].w = 25;
//    bsprite[ 3 ].h = 25;
//
//    bsprite[ 4 ].x = 710;												// Loads first bullet sprite frame
//    bsprite[ 4 ].y = 110;
//    bsprite[ 4 ].w = 30;
//    bsprite[ 4 ].h = 20;

    this->Position.x = x;															// Set x location
    this->Position.y = y;															// Set y location

    this->width = bsprite[ 0 ].w;										// Set sprite width
    this->height = bsprite[ 0 ].h;										// Set sprite height

    //friction = 0.95f;														// Set friction
    speedx = 0;																// Set horizontal speed
    speedy = 0;																// Set vertical speed
    alive  = true;															// Set alive
}

void Enemy1Bullet::Move()
{
    speedy = 5;															// Change vertical speed to 30 units/s
    Position.y+=speedy;																// Change y location based on speed
}

void Enemy1Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    LSprite->Render( Position.x - width/2, Position.y - height/2, &bsprite[0], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );			// Render bullet
}

