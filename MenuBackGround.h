#pragma once

#include "string.h"
#include "SDL.h"
#include "SDL_image.h"

class MenuBackground
{
private:
    SDL_Renderer* gRenderer;
    SDL_Surface *surface;
    SDL_Texture* tex;
    int width; int height;
public:
    MenuBackground(SDL_Renderer* r, int w, int h);
    void Load(const std::string &image_path);
    void Disp();
};
