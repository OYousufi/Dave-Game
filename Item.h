#ifndef ITEM_H
#define ITEM_H

#include "unit.h"


class Item : public unit
{
private:
    float x;
    float y;
    SDL_Rect ItemSprite;
public:
    //GarbageBin(Point);
    Item(LTexture*,int,int);
    ~Item();
    void Collision(unit*)
    {

    }
    void Move()
    {

    }
    void Fire()
    {

    }
    void SetPoint()
    {

    }
    bool GetAlive()
    {

    }
    void Move(int,int)
    {

    }
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool BULLETCOLL(unit*)
    {

    }
    int GetTag()
    {
        return tag;
    }

};

#endif // ITEM_H

