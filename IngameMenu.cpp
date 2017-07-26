#include "IngameMenu.h"

IngameMenu::IngameMenu()
{

}

IngameMenu::IngameMenu(LTexture* t, SDL_Renderer* r, int x1, int y1, int x2, int y2, int x3, int y3)
{
    tex = t;
    gRenderer = r;
    Resume = new Button("RESUME", x1, y1, tex, gRenderer, 6);
    SaveGame = new Button("SAVE GAME", x2, y2, tex, gRenderer, 9);
    Mainmenu = new Button("MAIN MENU", x3, y3, tex, gRenderer, 9);
    Resumepos = Resume->position();
    Savepos = SaveGame->position();
    Mainmenupos = Mainmenu->position();
}

void IngameMenu::Disp(int a, int b, int c, int d)
{
    Resume->Display(a, b, c, d);
    SaveGame->Display(a, b,c, d);
    Mainmenu->Display(a, b, c, d);
}

Button_Pos IngameMenu::Resume_pos()
{
    return Resumepos;
}

Button_Pos IngameMenu::Savegame_pos()
{
    return Savepos;
}

Button_Pos IngameMenu::Mainmenu_pos()
{
    return Mainmenupos;
}
