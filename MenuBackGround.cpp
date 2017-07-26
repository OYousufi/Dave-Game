#include "MenuBackGround.h"

MenuBackground::MenuBackground(SDL_Renderer* r, int w, int h)
{
    gRenderer = r;
    width = w;
    height = h;
}

void MenuBackground::Load(const std::string &image_path)
{
    surface = IMG_Load(image_path.c_str());
    if (!surface)
    {
        std::cout << "Failed to load surface" << std::endl;
    }
    tex = SDL_CreateTextureFromSurface(gRenderer, surface);
    if (!tex)
    {
        std::cout << "Failed to create texture" << std::endl;
    }
    SDL_FreeSurface(surface);

}

void MenuBackground::Disp()
{
    SDL_Rect rect = {0, 0, width, height};
    if (tex)
    {
        SDL_RenderCopy(gRenderer, tex, NULL, &rect);
    }
}
