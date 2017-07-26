#pragma once
#include "unit.h"


class Bullet : public unit
{
public:
    Bullet(LTexture* image, float x, float y);
    Bullet();
    ~Bullet();
    void Move()
    {

    }
    void Render(long int& frame, SDL_Renderer* gRenderer);
    enum ANIMATION_FRAMES {FLYING_FRAMES = 5};
    SDL_Rect bsprite[ FLYING_FRAMES ];
    void Move(int,int);
    void Fire()
    {

    }
    void SetAlive(bool)
    {

    }
    bool GetAlive();
    bool BULLETCOL(unit* dave)
    {

    }
};

