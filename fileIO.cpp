#include "fileIO.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

fileIO::fileIO()
{
    counter = 0;
}

fileIO::~fileIO()
{

}

void fileIO::load(FILE* filePointer)
{
    char buff[32];
    if (filePointer!=NULL)
    {
        fgets(buff, 32, (FILE*)filePointer);
        tag = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        a =  atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        b = atoi(buff);
        std::cout << "tag coordinate is: " <<tag<<std::endl;
        std::cout << "x coordinate is: " <<a<<std::endl;
        std::cout << "y coordinate is: " <<b<<std::endl;

    }

//          ################################################## P E E B B I AMMO ##########################################


}

float fileIO::geta()
{
    return a;
}

float fileIO::getb()
{
    return b;
}

int fileIO::getTags()
{
    return tag;
}

int fileIO::getcounter()
{
    FILE* filePointer;
    char buff[32];
    filePointer = fopen("game.txt", "r");    //Opening file as read only
    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter+=1/3;                                      //increase line count/
    }

    fclose(filePointer);                                //close file when done

    return counter;
}
