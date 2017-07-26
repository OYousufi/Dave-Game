#include "Point.h"
#include "LTexture.h"
#include "unit.h"

enum MOTION {RIGHT, LEFT, UP, DOWN};
enum STATE {idle,walk_forward,walk_backward,jump,fall};

class Player: public unit
{
private:
    int score;
    int movement;
    STATE state;
    int time;
public:
    Player();
    ~Player();
    Player(LTexture* Image,float,float);
    int UpdateScore(bool diamond);
    void Move(int direction,int mv);
    void Move();
    void Fire();
    void SetAlive(bool a);
    void setstate(STATE);
    STATE getstate();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool GetAlive();
    bool BULLETCOLL(unit*)
    {

    }
    int GetTag()
    {
        return tag;
    }

};
