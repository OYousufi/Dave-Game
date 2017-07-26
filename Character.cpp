
#include "Character.h"
#include "Point.h"
#include <iostream>

using namespace std;

Character::Character()
{

}

Character::Character(LTexture* image, int i)
{
    Image = image;
    if (i <= 10)
    {
        rect.x =  (i) * 44;
    }
    else if (i <= 21 && i > 10)
    {
        rect.x = ((i) - 11) * 44;
    }
    else if (i <= 32 && i > 21)
    {
        rect.x = ((i) - 22) * 44;
    }
    if (i <= 10)
    {
        rect.y = 0;
    }
    else if (i <= 21 && i > 10)
    {
        rect.y = 48;
    }
    else if (i <= 32 && i > 21)
    {
        rect.y = 96;
    }
    rect.w = 44;
    rect.h = 48;

    this->width = rect.w;
    this->height = rect.h;
}

Character::~Character()
{
    Image = NULL;
}

void Character::SetPosition(Point* p)
{
    position.x = p->x;
    position.y = p->y;
}

void Character::Render(SDL_Renderer* gRenderer)
{
    Image->Render( position.x - width/2, position.y - height/2, &rect, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

