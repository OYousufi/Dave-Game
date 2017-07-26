#pragma once

#include "SDL.h"
#include "Button.h"
#include "Button_Pos.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class MainMenu
{
private:
    LTexture* tex;
    SDL_Renderer* gRenderer;
    Button* Newgame;
    Button* LoadGame;
    Button_Pos Newgamepos;
    Button_Pos Loadgamepos;
public:
    MainMenu();
    MainMenu(LTexture* t, SDL_Renderer* r, int x1, int y1, int x2, int y2);
    void Disp(int a, int b, int c, int d);
    Button_Pos New_Game();
    Button_Pos Load_Game();
};
