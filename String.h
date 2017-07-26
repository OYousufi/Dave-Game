#pragma once

#include "Character.h"
#include "Point.h"
#include <iostream>

using namespace std;

class String
{
private:
    char* str;
    Point start;
    LTexture* tex;
    SDL_Renderer* gRenderer;
    int sizeofword;
public:
    String();
    String(char* , LTexture*, SDL_Renderer*, int, int, int);
    void Disp();
};
