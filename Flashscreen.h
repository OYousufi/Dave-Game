#pragma once

#include "string.h"
#include "SDL.h"
#include "SDL_image.h"

class Flashscreen
{
private:
    SDL_Renderer* gRenderer;
    SDL_Surface* gScreenSurface;
    SDL_Surface* surface;
    int width; int height;
public:
    Flashscreen(SDL_Renderer* r, SDL_Window*);
    void Load(const std::string &image_path);
    void Disp(SDL_Window*);
};
