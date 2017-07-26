#pragma once

#include "Character.h"
#include "Point.h"
#include "String.h"
#include <iostream>
#include "Button_Pos.h"
#include "SDL.h"

using namespace std;

class Button
{
private:
    String* word;
    Point start;
    LTexture* tex;
    SDL_Renderer* gRenderer;
    int sizec;
    Button_Pos pos;
public:
    Button();
    Button(char*, int, int, LTexture*, SDL_Renderer*, int);
    void Display(int, int, int, int);
    Button_Pos position();
};

