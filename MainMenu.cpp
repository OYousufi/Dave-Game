#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::MainMenu(LTexture* t, SDL_Renderer* r, int x1, int y1, int x2, int y2)
{
    tex = t;
    gRenderer = r;
    Newgame = new Button("NEW GAME", x1, y1, tex, gRenderer, 8);
    LoadGame = new Button("LOAD GAME", x2, y2, tex, gRenderer, 9);
    Newgamepos = Newgame->position();
    Loadgamepos = LoadGame->position();
}

void MainMenu::Disp(int a, int b, int c, int d)
{
    Newgame->Display(a, b, c, d);
    LoadGame->Display(a, b,c, d);
}

Button_Pos MainMenu::New_Game()
{
    return Newgamepos;
}

Button_Pos MainMenu::Load_Game()
{
    return Loadgamepos;
}

