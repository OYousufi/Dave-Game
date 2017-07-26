#include "Character.h"
#include "Point.h"
#include "String.h"
#include <iostream>

using namespace std;

String::String()
{

}

String::String(char *a, LTexture* t, SDL_Renderer* r, int s, int x, int y)
{
    tex = t;
    str = a;
    gRenderer = r;
    sizeofword = s;
    start.x = x;
    start.y = y;
}

void String::Disp()
{
    int character;
    for (int i = 0; i < sizeofword; i++)
    {
        Point p;
        p.x = 22 + i*32+ start.x;
        p.y = 24 + start.y;
        if (str[i] != ' ')
        {
            if (str[i] == 'a' || str[i] == 'A')
        {
            character = 0;
        }
        else if (str[i] == 'b' || str[i] == 'B')
        {
            character = 1;
        }
        else if (str[i] == 'c' || str[i] == 'C')
        {
            character = 2;
        }
        else if (str[i] == 'd' || str[i] == 'D')
        {
            character = 3;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            character = 4;
        }
        else if (str[i] == 'f' || str[i] == 'F')
        {
            character = 5;
        }
        else if (str[i] == 'g' || str[i] == 'G')
        {
            character = 6;
        }
        else if (str[i] == 'h' || str[i] == 'H')
        {
            character = 7;
        }
        else if (str[i] == 'i' || str[i] == 'I')
        {
            character = 8;
        }
        else if (str[i] == 'j' || str[i] == 'J')
        {
            character = 9;
        }
        else if (str[i] == 'k' || str[i] == 'K')
        {
            character = 10;
        }
        else if (str[i] == 'l' || str[i] == 'L')
        {
            character = 11;
        }
        else if (str[i] == 'm' || str[i] == 'M')
        {
            character = 12;
        }
        else if (str[i] == 'n' || str[i] == 'N')
        {
            character = 13;
        }
        else if (str[i] == 'o' || str[i] == 'O')
        {
            character = 14;
        }
        else if (str[i] == 'p' || str[i] == 'P')
        {
            character = 15;
        }
        else if (str[i] == 'q' || str[i] == 'Q')
        {
            character = 16;
        }
        else if (str[i] == 'r' || str[i] == 'R')
        {
            character = 17;
        }
        else if (str[i] == 's' || str[i] == 'S')
        {
            character = 18;
        }
        else if (str[i] == 't' || str[i] == 'T')
        {
            character = 19;
        }
        else if (str[i] == 'u' || str[i] == 'U')
        {
            character = 20;
        }
        else if (str[i] == 'v' || str[i] == 'V')
        {
            character = 21;
        }
        else if (str[i] == 'w' || str[i] == 'W')
        {
            character = 22;
        }
        else if (str[i] == 'x' || str[i] == 'X')
        {
            character = 23;
        }
        else if (str[i] == 'y' || str[i] == 'Y')
        {
            character = 24;
        }
        else if (str[i] == 'z' || str[i] == 'Z')
        {
            character = 25;
        }
        Character a(tex, character);
        a.SetPosition(&p);
        a.Render(gRenderer);
        }
    }
}
