#include <iostream>
using namespace std;
#include<string>
union stacData
{
    char c;
    int i;
    float f;
    int tag[100];
};
struct queue
{
    int size;
    int front;
    int rear;
    union stacData elements[100];
};
void enqueueInt(struct queue &Q, int x)
{
    if(((Q.rear+1)%Q.size)==Q.front)
    {
        cout<<"queue is full"<<endl<<endl;
    }
    else
    {
        if(Q.front==-1)
        {
            Q.rear = 0, Q.front=0;
        }
        else
        {
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear].i=x;
        
    }
    
}
void enqueueChar(struct queue &Q, char x)
{
    if(((Q.rear+1)%Q.size)==Q.front)
    {
        cout<<"queue is full"<<endl<<endl;
    }
    else
    {
        if(Q.front==-1)
        {
            Q.rear = 0, Q.front=0;
        }
        else
        {
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear].c=x;
        
    }
    
}
void enqueueFlo(struct queue &Q, float x)
{
    if(((Q.rear+1)%Q.size)==Q.front)
    {
        cout<<"queue is full"<<endl<<endl;
    }
    else
    {
        if(Q.front==-1)
        {
            Q.rear = 0, Q.front=0;
        }
        else
        {
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear].f=x;
        
    }
    
}
int dequeueInt(struct queue &Q)
{
    int t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        if(Q.front==Q.rear)
        {
            t = Q.elements[Q.front].i;
            Q.front=-1, Q.rear=-1;
        }
        else
        {
            t = Q.elements[Q.front].i;
            Q.front = (Q.front+1)%Q.size;
        }
        return t;
    }
    
}
char dequeueChar(struct queue &Q)
{
    char t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return '\0';
    }
    else
    {
        if(Q.front==Q.rear)
        {
            t = Q.elements[Q.front].c;
            Q.front=-1, Q.rear=-1;
        }
        else
        {
            t = Q.elements[Q.front].c;
            Q.front = (Q.front+1)%Q.size;
        }
        return t;
    }
    
}
float dequeueFlo(struct queue &Q)
{
    float t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return -1.0;
    }
    else
    {
        if(Q.front==Q.rear)
        {
            t = Q.elements[Q.front].f;
            Q.front=-1, Q.rear=-1;
        }
        else
        {
            t = Q.elements[Q.front].f;
            Q.front = (Q.front+1)%Q.size;
        }
        return t;
    }
    
}


int main ()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    int ta,pushn;
    char pushch;
    float pushfl;
    while(true)
    {
        cout<<"what do want to enqueue in Stack 1 for int, 2 for float, 3 for char and any key to dequeue"<<endl;
        cin>>ta;
        if(ta==1)
        {
            cin>>pushn;
            enqueueInt(Q, pushn);
            Q.elements[Q.rear].tag[Q.rear] = ta;

        }
        else if(ta==2)
        {
            cin>>pushfl;
            enqueueFlo(Q, pushfl);
            Q.elements[Q.rear].tag[Q.rear] = ta;
        }
        else if(ta==3)
        {
            cin>>pushch;
            enqueueChar(Q, pushch);
            Q.elements[Q.rear].tag[Q.rear] = ta;
        }
        else
        {
            break;        
        }
        
           
    }
    cout<<" check "<<Q.elements[Q.front].tag[Q.front]<<endl;
    while(Q.front !=-1)
    {
        if(Q.elements[Q.front].tag[Q.front]==1)
        {
            cout<<dequeueInt(Q)<<" ";
        }
        else if(Q.elements[Q.front].tag[Q.front]==2)
        {
            cout<<dequeueFlo(Q)<<" ";
        }
        else if(Q.elements[Q.front].tag[Q.front]==3)
        {

            cout<<dequeueChar(Q)<<" ";
        }
        else
        {
            break;
        }
        
           
    }
 


    
    
}