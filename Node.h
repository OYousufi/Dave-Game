#pragma once
#include"unit.h"

struct Node
{
    unit* unit;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete unit;  //unit is called in destructor
    }
};

