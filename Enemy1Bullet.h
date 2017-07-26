
#ifndef ENEMY1BULLET_H_INCLUDED
#define ENEMY1BULLET_H_INCLUDED
#include "Unit.h"

class Enemy1Bullet : public unit
{
public:
    Enemy1Bullet(LTexture* image, float x, float y);
    Enemy1Bullet();
    ~Enemy1Bullet();
    void Move();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    enum ANIMATION_FRAMES {FLYING_FRAMES = 5};
    SDL_Rect bsprite[ FLYING_FRAMES ];
    void Move(int,int)
    {

    }
    void Fire()
    {

    }
    void SetAlive(bool)
    {

    }
    bool GetAlive()
    {
        if (Position.y>1000)
        {
            alive=false;
        }
        return alive;

    }
    bool BULLETCOLL(unit*)
    {

    }
    int GetTag()
    {
        return tag;
    }

};



#endif // ENEMY1BULLET_H_INCLUDED
