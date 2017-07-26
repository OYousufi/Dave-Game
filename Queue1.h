#pragma once
#include"Node.h"
#include "gamescreen.h"

class Queue1
{
private:
    Node* head;
    Node* tail;
public:
    Queue1();
    ~Queue1();
    void Enqueue(unit*);
    void Dequeue();
    void Render(long int& frame, SDL_Renderer* gRenderer, int state);
    void Move(Gamescreen, int, int*);
    void save(FILE* filewriter);
    int counter();
    void COL(unit*,int,int*,int*,int*,unit*,unit*);
};
