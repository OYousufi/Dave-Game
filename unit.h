#pragma once
#include <iostream>
#include "LTexture.h"
#include "Point.h"
#include "SDL.h"
#include <iostream>
using namespace std;

class unit
{
protected:
    bool alive;
    LTexture* LSprite;
    float speedx;
    float speedy;
    int width;
    int height;
    float friction;
    SDL_Rect sprite;
    Point Position;
    int tag;
public:
    virtual void Move()=0;
    virtual void Collision(unit* u)
    {
    }
    virtual ~unit()
    {

    }
    virtual void Move(int,int)=0;
    virtual void Fire()=0;
    virtual void SetAlive(bool)=0;
    Point GetPoint()
    {
        return Position;
    }
    virtual bool BULLETCOLL(unit* dave)
    {

    }
    virtual bool GetAlive()=0;
    int GetTag()
    {
        return tag;
    }
    virtual void Render(long int& frame, SDL_Renderer* gRenderer)=0;
    void SetPoint(Point a)
    {
        Position = a;
    }

};
