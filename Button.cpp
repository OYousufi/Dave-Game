#include "Button.h"

#include "Character.h"
#include "Point.h"
#include "String.h"
#include <iostream>

using namespace std;

Button::Button()
{

}

Button::Button(char* a, int x, int y, LTexture* tex, SDL_Renderer* ren, int sizeofword)
{
    this->tex = tex;
    gRenderer = ren;
    start.x = x;
    start.y = y;
    word = new String(a, tex, ren, sizeofword, x + 10, y + 10);
    sizec = sizeofword;
}

void Button::Display(int a, int b, int c, int d)
{
    SDL_SetRenderDrawColor(gRenderer, a, b, c, d);
    SDL_Rect rect = {start.x, start.y, 32 * sizec + 20, 68};
    SDL_RenderFillRect(gRenderer, &rect);
    word->Disp();
}

Button_Pos Button::position()
{
    pos.x_start = start.x;
    pos.x_end = start.x + 32 * sizec + 20;
    pos.y_start = start.y;
    pos.y_end = 68 + start.y;
    return pos;
}
