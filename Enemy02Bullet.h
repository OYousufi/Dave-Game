#ifndef ENEMY02BULLET_H_INCLUDED
#define ENEMY02BULLET_H_INCLUDED
#include "unit.h"
class Enemy02Bullet : public unit
{
public:
    Enemy02Bullet(LTexture* image, float x, float y);
    Enemy02Bullet();
    ~Enemy02Bullet();
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
        alive = true;
        if (Position.x<-100)
        {
            alive = false;
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


#endif // ENEMY02BULLET_H_INCLUDED

