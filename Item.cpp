#include "item.h"
using namespace std;

Item::~Item()
{
    tag = 4;
}
Item::Item(LTexture* image,int x, int y)
{
	LSprite = image;

    ItemSprite.x=504;
    ItemSprite.y=60;
    ItemSprite.w=51;
    ItemSprite.h=39;

    this->x = x;
    this->y = y;

}
void Item::Render(long int& frame, SDL_Renderer* gRenderer)
{
    LSprite->Render( x - width/2, y - height/2, &ItemSprite, 0.0, NULL, SDL_FLIP_NONE, gRenderer );			// Render enemy plane
}

