#include "Flashscreen.h"

Flashscreen::Flashscreen(SDL_Renderer* r, SDL_Window* gWindow)
{
    gScreenSurface = SDL_GetWindowSurface( gWindow );
    gRenderer = r;
}

void Flashscreen::Load(const std::string &image_path)
{
    surface = IMG_Load(image_path.c_str());
    if (!surface)
    {
        std::cout << "Failed to load surface" << std::endl;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(gRenderer, surface);
    if (!tex)
    {
        std::cout << "Failed to create texture" << std::endl;
    }
}

void Flashscreen::Disp(SDL_Window* gWindow)
{

    for (int i=0;i<10;i++)
            {
                if (i%2==0)
                {
                    SDL_BlitSurface(surface, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    SDL_Delay(500);
                    SDL_RenderPresent( gRenderer );
                }
                else
                {
                    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
                    SDL_RenderClear( gRenderer );
                    SDL_RenderPresent( gRenderer );
                }
            }
}
