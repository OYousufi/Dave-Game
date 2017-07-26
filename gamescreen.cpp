#include "gamescreen.h"

Gamescreen::Gamescreen(SDL_Renderer* r,LTexture* image)
{
    gRenderer = r;
    this->image = image;
}


void Gamescreen::Disp1()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
           if (a[i][j] == 0)
            {

            }
            else if (a[i][j] == 1)
            {
                SDL_Rect rect = {150,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (a[i][j] == 2)
            {
                SDL_Rect rect = {0,75,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (a[i][j] == 3)
            {
                SDL_Rect rect = {225,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (a[i][j] == 4)
            {
                SDL_Rect rect = {300,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (a[i][j] == 5)
            {
                SDL_Rect rect = {0,0,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }

        }
    }
}

void Gamescreen::Disp2()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
           if (b[i][j] == 0)
            {

            }
            else if (b[i][j] == 1)
            {
                SDL_Rect rect = {150,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (b[i][j] == 2)
            {
                SDL_Rect rect = {0,75,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (b[i][j] == 3)
            {
                SDL_Rect rect = {225,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (b[i][j] == 4)
            {
                SDL_Rect rect = {0,0,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (b[i][j] == 5)
            {
                SDL_Rect rect = {0,0,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }

        }
    }
}

void Gamescreen::Disp3()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
           if (c[i][j] == 0)
            {

            }
            else if (c[i][j] == 1)
            {
                SDL_Rect rect = {150,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (c[i][j] == 2)
            {
                SDL_Rect rect = {0,75,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (c[i][j] == 3)
            {
                SDL_Rect rect = {225,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (c[i][j] == 4)
            {
                SDL_Rect rect = {300,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (c[i][j] == 5)
            {
                SDL_Rect rect = {0,0,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
        }
    }
}

void Gamescreen::Disp4()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
           if (d[i][j] == 0)
            {

            }
            else if (d[i][j] == 1)
            {
                SDL_Rect rect = {150,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (d[i][j] == 2)
            {
                SDL_Rect rect = {0,75,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (d[i][j] == 3)
            {
                SDL_Rect rect = {225,225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (d[i][j] == 4)
            {
                SDL_Rect rect = {300, 225,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (d[i][j] == 5)
            {
                SDL_Rect rect = {0,0,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }
            else if (d[i][j] == 6)
            {
                SDL_Rect rect = {150, 0,75,75};
                image->Render(75 * j, 75 * i, &rect,0.0, NULL, SDL_FLIP_NONE, gRenderer );
            }

        }
    }
}


int Gamescreen::Screen1Obj(int x, int y)
{
    int r = a[int(y/75)][int(x/75)];
    if (r == 0)
    {
        return 0;
    }
    else if (r == 1 || r == 2 || r == 3)
    {
        return 1;
    }
    else if (r == 4 || r == 5)
    {
        return 2;
    }
}

int Gamescreen::Screen2Obj(int x, int y)
{
    int r = b[int(y/75)][int(x/75)];
    if (r == 0)
    {
        return 0;
    }
    else if (r == 1 || r == 2 || r == 3)
    {
        return 1;
    }
    else if (r == 4 || r == 5)
    {
        return 2;
    }
}

int Gamescreen::Screen3Obj(int x, int y)
{
    int r = c[int(y/75)][int(x/75)];
    if (r == 0)
    {
        return 0;
    }
    else if (r == 1 || r == 2 || r == 3)
    {
        return 1;
    }
    else if (r == 4 || r == 5)
    {
        return 2;
    }
}

int Gamescreen::Screen4Obj(int x, int y)
{
    int r = d[int(y/75)][int(x/75)];
    if (r == 0)
    {
        return 0;
    }
    else if (r == 1 || r == 2 || r == 3)
    {
        return 1;
    }
    else if (r == 4 || r == 5)
    {
        return 2;
    }
    else if (r == 6)
    {
        return 3;
    }
}

