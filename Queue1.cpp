#include"Queue1.h"
#include<iostream>

using namespace std;

Queue1::Queue1()
{
    head = NULL;        //initializes
    tail = NULL;
}

Queue1::~Queue1()
{
    while(head!=NULL)
    {
        Node* temp = head;  //pop  func
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    cout << "Queue destructor called" << endl;
}

void Queue1::Enqueue(unit* unit)
{
    if(head == NULL)    //if queue doesn't exist
    {
        head = new Node;    //new node is made
        head->unit = unit;  //head unit is pointed towards unit
        head->prev = NULL;  //head prev is nullified
        head->next = NULL;  //head next is nullified
        tail = head;    //tail points where head points
    }
    else
    {
        tail->next = new Node;  //new node is creatd, tail next points towards it
        tail->next->unit = unit;    //enemy planes are enqueued
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue1::Dequeue()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if (temp->unit->GetAlive() == false)
        {
            Node* dlt = temp;
            temp=temp->next;
            if (dlt->prev != NULL)
            {
                dlt->prev->next = dlt->next;
            }
            else
            {
                head = temp;
            }
            if (dlt->next != NULL)
            {
                dlt->next->prev = dlt->prev;
            }
            else
            {
                tail = dlt->prev;
            }
            delete dlt;
        }
        else temp=temp->next;
    }
}

void Queue1::Render(long int& frame, SDL_Renderer* gRenderer,int state)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if (temp->unit->GetTag()==2 || temp->unit->GetTag()==-2)
        {
            if (state==1)
            {
                temp->unit->Render(frame, gRenderer);
                temp=temp->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        else if (temp->unit->GetTag()==3 || temp->unit->GetTag()==-3)
        {
            if (state==2)
            {
                temp->unit->Render(frame, gRenderer);
                temp=temp->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        else
        {
            temp->unit->Render(frame, gRenderer);
            temp=temp->next;
        }


    }
}

void Queue1::Move(Gamescreen gs, int state,int* p)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if (temp->unit->GetTag()==1 && *p == 0)
        {
            if (state==0)
            {
                if (gs.Screen1Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+73) == 0 && gs.Screen1Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+73) == 0)
                {
                    temp->unit->Move();
                }
            }
            else if( state == 1 )
            {
                if (gs.Screen2Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+75) == 0 && gs.Screen2Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 0)
                {
                    temp->unit->Move();
                }
                if (gs.Screen2Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+75) == 2 && gs.Screen2Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 2)
                {
                    temp->unit->SetAlive(false);
                    *p = 1;
                }
            }
            else if( state == 2)
            {
                if (gs.Screen3Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+75) == 0 && gs.Screen3Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 0)
                {
                    temp->unit->Move();
                }
                if (gs.Screen3Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+75) == 2 && gs.Screen3Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 2)
                {
                    temp->unit->SetAlive(false);
                }

            }
            else if( state == 3)
            {
                if (gs.Screen4Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+75) == 0 && gs.Screen4Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 0)
                {
                    temp->unit->Move();
                }
                if (gs.Screen4Obj(temp->unit->GetPoint().x,temp->unit->GetPoint().y+75) == 2 && gs.Screen4Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 2)
                {
                    temp->unit->SetAlive(false);
                    *p = 1;
                }
                if (gs.Screen4Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y) == 3 || gs.Screen4Obj(temp->unit->GetPoint().x+70,temp->unit->GetPoint().y+75) == 3)
                {
                    *p = 3;
                }
            }
        }
        else
        {
            temp->unit->Move();
        }

        temp = temp->next;
    }
}

int Queue1::counter()
{
    Node*temp=head;
    int c = 0;
    while(temp != tail->next)
    {
        c++;
        temp=temp->next;
        return c;
    }
}

void Queue1::save(FILE* filewriter)
{


    Node* temp=head;

    char buff[32];
    char* c=NULL;
    char* d=NULL;
    char* e=NULL;
    while(temp != NULL)
    {

        if(temp->unit->GetTag()!=-1)
        {
            cout<<temp->unit->GetTag()<<endl;
            e=itoa(temp->unit->GetTag(),buff,10);
            fputs(e,(FILE*)filewriter);
            fputs("\n",(FILE*)filewriter);
            c=itoa(temp->unit->GetPoint().x, buff, 10);
            fputs(c, (FILE*)filewriter);
            fputs("\n",(FILE*)filewriter);
            d=itoa(temp->unit->GetPoint().y, buff, 10);
            fputs(d, (FILE*)filewriter);
            fputs("\n", (FILE*)filewriter);

        }
        temp = temp->next;


    }
}


void Queue1::COL(unit* K,int a , int* p,int* e, int* e1, unit* d, unit* K1)
{
    Node* temp = head;
    while (temp != NULL)
    {
    if (temp->unit->GetTag()==-1 && a == 2 && *e1==0)
    {


        if ((temp->unit->GetPoint().y < K->GetPoint().y + 95) && (temp->unit->GetPoint().y >  K->GetPoint().y - 95) &&
                (temp->unit->GetPoint().x < K->GetPoint().x + 45/2) && (temp->unit->GetPoint().x > K->GetPoint().x - 45/2))
        {
            K->SetAlive(false);
            *e1 = 1;
        }

    }
    if (temp->unit->GetTag()==-1 && a == 1 && *e==0)
    {


        if ((temp->unit->GetPoint().y < K1->GetPoint().y + 95) && (temp->unit->GetPoint().y >  K1->GetPoint().y - 95) &&
                (temp->unit->GetPoint().x < K1->GetPoint().x + 45/2) && (temp->unit->GetPoint().x > K1->GetPoint().x - 45/2))
        {
            K1->SetAlive(false);
            *e = 1;
        }

    }
    else if(temp->unit->GetTag()==-2 && a == 1 && *p==0 )
    {
        if (temp->unit->GetPoint().y < d->GetPoint().y+75  && temp->unit->GetPoint().y >d->GetPoint().y
            && temp->unit->GetPoint().x < d->GetPoint().x+75 && temp->unit->GetPoint().x > d->GetPoint().x)
        {
            d->SetAlive(false);
            *p = 1;
        }

    }
    else if(temp->unit->GetTag()==-3 && a == 2 && *p==0 )
    {
        if ((temp->unit->GetPoint().y < d->GetPoint().y + 75) && (temp->unit->GetPoint().y >  d->GetPoint().y ) &&
                (temp->unit->GetPoint().x < d->GetPoint().x + 75) && (temp->unit->GetPoint().x > d->GetPoint().x ))
        {
            d->SetAlive(false);
            *p = 1;
        }

    }
     else if(temp->unit->GetTag()==2 && a == 1 && *p==0 )
    {
        if ((temp->unit->GetPoint().y < d->GetPoint().y + 75) && (temp->unit->GetPoint().y >  d->GetPoint().y ) &&
                (temp->unit->GetPoint().x < d->GetPoint().x + 75) && (temp->unit->GetPoint().x > d->GetPoint().x ))
        {
            d->SetAlive(false);
            *p = 1;
        }

    }
     else if(temp->unit->GetTag()==3 && a == 2 && *p==0 )
    {
        if ((temp->unit->GetPoint().y < d->GetPoint().y + 75) && (temp->unit->GetPoint().y >  d->GetPoint().y ) &&
                (temp->unit->GetPoint().x < d->GetPoint().x + 75) && (temp->unit->GetPoint().x > d->GetPoint().x ))
        {
            d->SetAlive(false);
            *p = 1;
        }

    }

    temp = temp->next;
    }


}

