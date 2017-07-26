
#pragma once

#include "SDL.h"
#include "Button.h"
#include "Button_Pos.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class IngameMenu
{
private:
    LTexture* tex;
    SDL_Renderer* gRenderer;
    Button* Resume;
    Button* SaveGame;
    Button* Mainmenu;
    Button_Pos Resumepos;
    Button_Pos Savepos;
    Button_Pos Mainmenupos;
public:
    IngameMenu();
    IngameMenu(LTexture* t, SDL_Renderer* r, int x1, int y1, int x2, int y2, int x3, int y3);
    void Disp(int, int, int, int);
    Button_Pos Resume_pos();
    Button_Pos Savegame_pos();
    Button_Pos Mainmenu_pos();
};
