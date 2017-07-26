#include"unit.h"

class Enemy: public unit
{
private:
    int time;
    int state;
public:
    Enemy();
    Enemy(LTexture* image, float x,float y);
    ~Enemy();
    void Move();
    void Move(int direction,int);
    bool BULLETCOLL(unit*)
    {

    }
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Fire();
    void SetAlive(bool);
    bool GetAlive()
    {
        return alive;
    }
    int GetTag()
    {
        return tag;
    }
};
