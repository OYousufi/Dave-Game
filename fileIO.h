#pragma once
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class fileIO
{
    public:
        fileIO();
        ~fileIO();
        void load(FILE* filePointer);
        float geta();
        float getb();
        int getTags();
        int getcounter();
    private:
        float a;
        float b;
        int tag;
        float counter;
};
