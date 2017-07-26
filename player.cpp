#include "player.h"

Player::~Player()
{
    cout<<"Player Deallocated"<<endl;
}
Player::Player(LTexture* image,float x,float y)
{
    LSprite = image;


    state=idle;


    this->Position.x = x;
    this->Position.y = y;

    //this->width = sprite.w;
    //this->height = sprite.h;

    speedx = 0;
    speedy = 0;
    alive  = true;
    friction = 0.5f;
    movement = 1;
    time = 0;
    tag = 1;
}

int Player::UpdateScore(bool diamond)
{

}

void Player::Move(int direction,int mv)
{
    if (Position.y<80)
    {
        Position.y = 80;
    }
    if (mv!=1)
    {
        if(direction==LEFT)
        {
            setstate(walk_backward);
            speedx = -5;
            Position.x+=speedx;
        }
        if(direction==RIGHT)
        {
            setstate(walk_forward);
            speedx = 5;
            Position.x+=speedx;
        }

        if(direction==UP)
        {
            if(state!=fall)
            {
                setstate(jump);
                speedy = -10;
                Position.y+=speedy;
                time=0;
            }

        }

    }

}

void Player::Move()
{
    if (Position.y<80)
    {
        Position.y = 80;
    }
    speedx = speedx * friction;
    if (state!=jump)
    {
        if (time>30)
        {
            speedy = 4.0f;
        }
        Position.x = Position.x + speedx;
        Position.y = Position.y + speedy;
        if (Position.y>700)
        {
            Position.y=700;
        }
    }
    else
    {
        speedy*=friction;
        state = fall;
    }
    time++;
}

void Player::SetAlive(bool a)
{
    alive = a;
}


void Player::Fire()
{

}

void Player::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if (state == idle|| state==fall)
    {
        sprite.x = 130;
        sprite.y = 0;
        sprite.h = 70;
        sprite.w = 65;
        LSprite->Render( Position.x - width/2, Position.y - height/2, &sprite, 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    }
    else if (state == walk_forward)
    {
        if (Position.y==700)
        {
            sprite.x = 0;
            sprite.y = 0;
            sprite.h = 70;
            sprite.w = 65;
        }
        else
        {


            if (movement==0)
            {   sprite.x = 130;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==1)
            {
                sprite.x = 195;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==2)
            {
                sprite.x = 260;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==3)
            {
                sprite.x = 325;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==4)
            {
                sprite.x = 0;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else
            {
                sprite.x = 65;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
        }
        LSprite->Render( Position.x - width/2, Position.y - height/2, &sprite, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (state == walk_backward)
    {
        if (Position.y==700)
        {
            sprite.x = 0;
            sprite.y = 0;
            sprite.h = 70;
            sprite.w = 65;
        }
        else
        {



            if (movement==0)
            {   sprite.x = 130;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==1)
            {
                sprite.x = 195;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==2)
            {
                sprite.x = 260;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==3)
            {
                sprite.x = 325;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else if (movement==4)
            {
                sprite.x = 0;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
            else
            {
                sprite.x = 65;
                sprite.y = 0;
                sprite.h = 70;
                sprite.w = 65;
            }
        }
        LSprite->Render( Position.x - width/2, Position.y - height/2, &sprite, 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    }
    else if (state=jump)
    {
        sprite.x = 65;
        sprite.y = 0;
        sprite.h = 70;
        sprite.w = 65;
        LSprite->Render( Position.x - width/2, Position.y - height/2, &sprite, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}

void Player::setstate(STATE stat)
{
    this->state = stat;
    if (movement==5)
    {
        movement=0;
    }
    movement++;

}

STATE Player::getstate()
{
    return state;
}

bool Player::GetAlive()
{
    return alive;
}




