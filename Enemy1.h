#pragma once
#include "unit.h"
#include "bullet.h"



class Enemy01: public unit
{
private:
    int state;
    int time;
public:
    Enemy01();
    Enemy01(LTexture* image, float x,float y);
    ~Enemy01();
    void Move();
    void Move(int direction,int);
    bool BULLETCOLL(unit* dave);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Fire()
    {

    }
    void SetAlive(bool);

    bool GetAlive()
    {
        return alive;
    }
    int GetTag()
    {
        return tag;
    }
};



