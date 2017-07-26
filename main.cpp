#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "unit.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "bullet.h"
#include "Queue1.h"
#include "String.h"
#include "Character.h"
#include "Button.h"
#include "Button_Pos.h"
#include "MainMenu.h"
#include "MenuBackGround.h"
#include "Flashscreen.h"
#include "IngameMenu.h"
#include "gamescreen.h"
#include "Item.h"
#include "Enemy1Bullet.h"
#include "Enemy02Bullet.h"
#include "fileIO.h"

//Pre defined screen width and height
const int SCREEN_WIDTH = 1050;
const int SCREEN_HEIGHT = 750;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

enum gamestate {mainmenu,gamescreen,ingamemenu,gameover1};
enum screenstate {screen1,screen2,screen3,screen4};

LTexture gSpriteSheetTexture,eSpriteSheetTexture,e1SpriteSheetTexture,bSpriteSheetTexture,Image,ISpriteSheetTexture,ESpriteSheetTexture,E2SpriteSheetTexture;


bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{
    //Start up SDL and create window

    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            Queue1 obj;

            bool quit = false;                      //Main loop flag

            Flashscreen splash(gRenderer, gWindow);
            splash.Load("Images/flashiat.png");

            splash.Disp(gWindow);

            MainMenu menu(&Image, gRenderer,375 , 100, 375,600);
            MenuBackground mainmenubg(gRenderer, 1050, 750);
            mainmenubg.Load("images/backg.png");
            IngameMenu Imenu(&Image,gRenderer,150,150,150,300,150,450);
            MenuBackground ingamebg(gRenderer, 1050, 750);
            ingamebg.Load("images/m.png");

            SDL_Event e;                            //Event handler
            int delay =0 ;
            int edelay = 0;
            long int frame = 0;                     //Current animation frame

            bool Inmenu = false;

            /* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            int random = 0;
            FILE* filePointer;                          //Declaring a file pointer
            char buff[32];
            float w,h,c,d,z,f;
            unit* dave = NULL;
            unit* enemy = NULL;
            unit* enemy1= NULL;
            unit* bullet= NULL;

            bool gameover = false;
            gamestate state;
            state=mainmenu;
            screenstate state1;
            state1 = screen1;
            int dead1 = 0;
            int dead2 = 0;
            int dead3 = 0;

            while (!gameover)
            {


            if (state==mainmenu)
            {
                quit = false;
                while (!quit)
                {
                    if( e.type == SDL_QUIT )
                        {
                            quit = true;
                            gameover = true;
                        }

                    while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                        {
                            if(e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                int x,y;
                                SDL_GetMouseState( &x, &y );
                                if( x < menu.New_Game().x_end && x > menu.New_Game().x_start && y < menu.New_Game().y_end && y > menu.New_Game().y_start )
                                {

                                    w = 650;
                                    h = 600;                         //Declaring a character array to store a line
                                    c = SCREEN_WIDTH/4;
                                    d = SCREEN_HEIGHT/4;
                                    z = SCREEN_WIDTH-400;
                                    f = SCREEN_HEIGHT-100;
                                    dave=NULL;
                                    enemy=NULL;
                                    enemy1=NULL;
                                    state=gamescreen;
                                    quit = true;
                                }
                                else if(x < menu.Load_Game().x_end && x > menu.Load_Game().x_start && y < menu.Load_Game().y_end && y > menu.Load_Game().y_start)
                                {

                                    dave=NULL;
                                    enemy=NULL;
                                    enemy1=NULL;

                                    filePointer = fopen("game.txt", "r");    //Opening file as read only
                                    fileIO I;
                                    int x = I.getcounter();
                                    if (filePointer!=NULL)
                                    {
                                        for (int i=0;i<x+3;i++)
                                        {
                                            I.load(filePointer);
                                            int ID = I.getTags();
                                            if (ID == 1)
                                            {
                                                w = I.geta();
                                                h = I.getb();
                                            }
                                            if (ID == 2)
                                            {
                                                c = I.geta();
                                                d = I.getb();
                                            }
                                            if (ID == 3)
                                            {
                                                z = I.geta();
                                                f = I.getb();
                                            }
                                        }
                                        fclose(filePointer);
                                    }
                                    state=gamescreen;
                                    quit = true;
                                }



                            }
                        }

                        SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
                        SDL_RenderClear( gRenderer );
                        mainmenubg.Disp();
                        menu.Disp(0, 0,0, 0);


                        SDL_RenderPresent(gRenderer);

                }
            }
            if (state==gamescreen)
            {
                Gamescreen gs(gRenderer,&ISpriteSheetTexture);
                quit=false;

                const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
                while( !quit )                          //While application is running
                {
                    if (dave==NULL && dead1 ==0 )
                    {
                        dave = new Player(&gSpriteSheetTexture, (float)w, (float)h);
                        obj.Enqueue(dave);
                    }

                    if (state1==screen1 && dead1 == 0)
                    {
                        if (dave->GetPoint().x>1050)
                        {
                            Point p;
                            p.x = 0;
                            p.y = dave->GetPoint().y;
                            dave->SetPoint(p);
                            state1=screen2;
                        }
                    }
                    if (state1==screen2 && dead1 == 0)
                    {
                        if (dave->GetPoint().x>1050)
                        {
                            Point p;
                            p.x = 0;
                            p.y = dave->GetPoint().y;
                            dave->SetPoint(p);
                            state1=screen3;
                        }
                        else if (dave->GetPoint().x<-10)
                        {
                            Point p;
                            p.x = 1050;
                            p.y = dave->GetPoint().y;
                            dave->SetPoint(p);
                            state1=screen1;
                        }

                    }
                    if (state1==screen3 && dead1 == 0)
                    {
                        if (dave->GetPoint().x>1050)
                        {
                            Point p;
                            p.x = 0;
                            p.y = dave->GetPoint().y;
                            dave->SetPoint(p);
                            state1=screen4;
                        }
                        else if (dave->GetPoint().x<-10)
                        {
                            Point p;
                            p.x = 1050;
                            p.y = dave->GetPoint().y;
                            dave->SetPoint(p);
                            state1=screen2;
                        }

                    }
                    if (state1==screen4 && dead1 == 0)
                    {
                        if (dave->GetPoint().x<-10)
                        {
                            Point p;
                            p.x = 1050;
                            p.y = dave->GetPoint().y;
                            dave->SetPoint(p);
                            state1=screen3;
                        }
                    }

                    if (enemy==NULL && state1==screen2 && dead2==0 )
                    {
                        enemy = new Enemy(&eSpriteSheetTexture, (float)c, (float)d);
                        obj.Enqueue(enemy);
                    }
                    if (enemy1==NULL && state1==screen3 && dead3==0)
                    {
                        enemy1 = new Enemy01(&e1SpriteSheetTexture,(float)z, (float)f);
                        obj.Enqueue(enemy1);
                    }


                    if(frame%25 == 0 )					// Set enemy plane generation frequency
                    {
                        if (edelay>30 && state1 == screen2 && dead2 == 0)
                        {
                            Enemy1Bullet* Ebullet = new Enemy1Bullet(&ESpriteSheetTexture,enemy->GetPoint().x+10,enemy->GetPoint().y-10);
                            obj.Enqueue(Ebullet);
                            edelay = 0;
                        }

                        random = rand() % 2;
                        if (random==0)
                        {
                            if (state1 == screen2 && enemy!=NULL && dead2==0)
                            {
                                enemy->Move(0,NULL);
                            }
                            else if (state1==screen3 && enemy1!=NULL && dead3==0)
                            {
                                enemy1->Move(0,NULL);
                            }
                        }
                        else
                        {
                            if (state1 == screen2 && enemy!=NULL && dead2==0)
                            {
                                enemy->Move(1,NULL);
                            }
                            else if (state1==screen3 && enemy1!=NULL && dead3==0)
                            {
                                enemy1->Move(1,NULL);
                            }

                        }
                    }


                    while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                    {


                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                            gameover = true;
                        }




                    }

                    if(currentKeyStates[ SDL_SCANCODE_SPACE ] && state1!=screen1 && state1!=screen2 )
                    {
                        if(delay>30 && dead1 == 0)
                        {
                            bullet = new Bullet(&bSpriteSheetTexture,dave->GetPoint().x +65, dave->GetPoint().y+30);
                            obj.Enqueue(bullet);
                            if (state1==screen4 && enemy1!=NULL && dead3 == 0)
                            {
                                enemy1->BULLETCOLL(bullet);
                            }
                            delay = 0;

                        }


                    }
                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                    {
                        if (state1 == screen1)
                        {
                            if (gs.Screen1Obj(dave->GetPoint().x+70,dave->GetPoint().y) == 0 && gs.Screen1Obj(dave->GetPoint().x+70,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(RIGHT,0);
                            }
                        }
                        else if (state1 == screen2)
                        {
                            if (gs.Screen2Obj(dave->GetPoint().x+70,dave->GetPoint().y) == 0 && gs.Screen2Obj(dave->GetPoint().x+70,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(RIGHT,0);
                            }
                        }
                        else if (state1 == screen3)
                        {
                            if (gs.Screen3Obj(dave->GetPoint().x+70,dave->GetPoint().y) == 0 && gs.Screen3Obj(dave->GetPoint().x+70,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(RIGHT,0);
                            }
                        }
                        else if (state1 == screen4)
                        {
                            if (gs.Screen3Obj(dave->GetPoint().x+70,dave->GetPoint().y) == 0 && gs.Screen3Obj(dave->GetPoint().x+70,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(RIGHT,0);
                            }
                        }

                    }


                    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
                    {
                        if (state1 == screen1)
                        {
                            if (gs.Screen1Obj(dave->GetPoint().x-5,dave->GetPoint().y) == 0 && gs.Screen1Obj(dave->GetPoint().x-5,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(LEFT,0);
                            }
                        }
                        else if (state1 == screen2)
                        {
                            if (gs.Screen2Obj(dave->GetPoint().x-5,dave->GetPoint().y) == 0 && gs.Screen2Obj(dave->GetPoint().x-5,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(LEFT,0);
                            }
                        }
                        else if (state1 == screen3)
                        {
                            if (gs.Screen3Obj(dave->GetPoint().x-5,dave->GetPoint().y) == 0 && gs.Screen3Obj(dave->GetPoint().x-5,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(LEFT,0);
                            }
                        }
                        else if (state1 == screen4)
                        {
                            if (gs.Screen4Obj(dave->GetPoint().x-5,dave->GetPoint().y) == 0 && gs.Screen4Obj(dave->GetPoint().x-5,dave->GetPoint().y+70) == 0)
                            {
                                dave->Move(LEFT,0);
                            }
                        }
                    }

                    if(currentKeyStates[ SDL_SCANCODE_UP ])
                    {

                        if (state1 == screen1)
                        {
                            if (gs.Screen1Obj(dave->GetPoint().x,dave->GetPoint().y-10) == 0 && gs.Screen1Obj(dave->GetPoint().x+65,dave->GetPoint().y-10) == 0)
                            {
                                dave->Move(UP,0);
                            }

                        }
                        else if (state1 == screen2)
                        {
                                if (gs.Screen2Obj(dave->GetPoint().x,dave->GetPoint().y-10) == 0 && gs.Screen2Obj(dave->GetPoint().x+65,dave->GetPoint().y-10) == 0)
                                {
                                    dave->Move(UP,0);
                                }

                        }
                        else if (state1 == screen3)
                        {
                            if (gs.Screen3Obj(dave->GetPoint().x,dave->GetPoint().y-10) == 0 && gs.Screen3Obj(dave->GetPoint().x+65,dave->GetPoint().y-10) == 0)
                            {
                                dave->Move(UP,0);
                            }

                        }
                        else if (state1 == screen4)
                        {
                            if (gs.Screen4Obj(dave->GetPoint().x,dave->GetPoint().y-10) == 0 && gs.Screen4Obj(dave->GetPoint().x+65,dave->GetPoint().y-10) == 0)
                            {
                            dave->Move(UP,0);
                            }

                        }
                    }

                    if (currentKeyStates[ SDL_SCANCODE_ESCAPE ])
                    {
                        state = ingamemenu;
                        quit = true;
                    }


                    if(frame%25 == 0 && state1==screen3 && enemy1!=NULL && dead3 == 0)
                        {
                            if (enemy1->BULLETCOLL(dave)==true)
                            {
                                Enemy02Bullet* Ebullet1 = new Enemy02Bullet(&E2SpriteSheetTexture,enemy1->GetPoint().x-10,enemy1->GetPoint().y+10);
                                obj.Enqueue(Ebullet1);
                            }
                        }

                    SDL_SetRenderDrawColor( gRenderer, 0, 0xFF, 0xFF, 0xFF );    //Clear screen
                    SDL_RenderClear( gRenderer );

                    if (state1 == screen1)
                    {
                        gs.Disp1();
                    }
                    if (state1 == screen2)
                    {
                        gs.Disp2();
                    }
                    if (state1 == screen3)
                    {
                        gs.Disp3();
                    }
                    if (state1 == screen4)
                    {
                        gs.Disp4();
                    }

                    obj.COL(enemy1,state1,&dead1,&dead2,&dead3 ,dave,enemy);

                    obj.Move(gs,state1,&dead1);
                    obj.Render(frame,gRenderer,state1);
                    obj.Dequeue();
                    if (dead2 == 1)
                    {
                        enemy = NULL;
                    }
                    if (dead3 == 1)
                    {
                        enemy1 = NULL;
                    }

                    if (dead1 == 1)
                    {
                        quit = true;
                        state = gameover1;
                    }
                    else if (dead1 == 3)
                    {
                        quit = true;
                        state = gameover1;
                    }

                    SDL_RenderPresent( gRenderer );
                    //Update screen

                    ++frame;
                    ++delay;
                    ++edelay;                    //Go to next frame
                }
            }
                if (state==ingamemenu)
                {
                    quit = false;

                    while(!quit)
                    {

                        SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
                        SDL_RenderClear( gRenderer );
                        ingamebg.Disp();
                        Imenu.Disp(255,0,0,0);
                        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                        {
                             if( e.type == SDL_QUIT )
                            {
                                quit = true;
                                gameover = true;
                            }

                            if(e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                int x,y;
                                SDL_GetMouseState( &x, &y );
                                if( x < Imenu.Resume_pos().x_end && x > Imenu.Resume_pos().x_start && y < Imenu.Resume_pos().y_end && y > Imenu.Resume_pos().y_start )
                                {
                                    state=gamescreen;
                                    quit = true;
                                }
                                if (x<Imenu.Savegame_pos().x_end && x>Imenu.Savegame_pos().x_start && y<Imenu.Savegame_pos().y_end && y>Imenu.Savegame_pos().y_start)
                                {
                                    FILE* filewriter;                          //Declaring a file pointer
                                    filewriter = fopen("game.txt", "w");    //Opening file as read only
                                    obj.save(filewriter);
                                    fclose(filewriter);
                                }
                                if (x<Imenu.Mainmenu_pos().x_end && x>Imenu.Mainmenu_pos().x_start && y<Imenu.Mainmenu_pos().y_end && y>Imenu.Mainmenu_pos().y_start)
                                {

                                    state=mainmenu;
                                    dave->SetAlive(false);
                                    if(enemy1!=NULL)
                                    {
                                        enemy1->SetAlive(false);
                                    }
                                    if(enemy!=NULL)
                                    {
                                        enemy->SetAlive(false);
                                    }
                                    state1 = screen1;
                                    obj.Dequeue();
                                    quit = true;
                                    dead1 = 0;
                                    dead2 = 0;
                                    dead3 = 0;
                                }

                            }
                        }
                        SDL_RenderPresent( gRenderer );



                    }


                }
                if (state == gameover1)
                {
                    quit = false;
                    while (!quit)
                    {
                        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                        {
                            if( e.type == SDL_QUIT )
                            {
                                quit = true;
                                gameover = true;
                            }
                        }
                        if (dead1 == 1)
                        {
                            SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
                            SDL_RenderClear( gRenderer );

                            MenuBackground over(gRenderer,1050,750);
                            over.Load("images/gm.png");
                            over.Disp();
                            SDL_RenderPresent( gRenderer );
                        }
                        else if (dead1 == 3)
                        {
                            SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
                            SDL_RenderClear( gRenderer );

                            MenuBackground over(gRenderer,1050,750);
                            over.Load("images/w.png");
                            over.Disp();
                            SDL_RenderPresent( gRenderer );
                        }
                    }
                }
            }

        }
    }
    //Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if( !gSpriteSheetTexture.LoadFromFile( "images/batmans.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !eSpriteSheetTexture.LoadFromFile( "images/Enemy1.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !e1SpriteSheetTexture.LoadFromFile( "images/Enemy01.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !bSpriteSheetTexture.LoadFromFile( "images/bat.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !Image.LoadFromFile( "Images/font.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !E2SpriteSheetTexture.LoadFromFile( "images/ENB.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !ESpriteSheetTexture.LoadFromFile( "images/1948.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !ISpriteSheetTexture.LoadFromFile( "images/fullplatform.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

    return success;
}

void close()
{
    //Free loaded images
    gSpriteSheetTexture.Free();
    eSpriteSheetTexture.Free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


