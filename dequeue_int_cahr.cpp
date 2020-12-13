#include <iostream>
using namespace std;
union stacData
{
    char c;
    int i;
    int tag[100];
};
struct queue
{
    int size;
    int front;
    int rear;
    union stacData elements[50];
};
void enqueueRear(struct queue &Q, int x)
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
        Q.elements[Q.rear].tag[Q.rear]=1;
        
    }
    
}
void enqueueFront(struct queue &Q, int x)
{

    if(Q.front-1==Q.rear||Q.front-1+Q.size==Q.rear)
    {
        if(Q.front-1+Q.size==Q.rear)
        cout<<"queue is full"<<endl;
        else if(Q.front-1==Q.rear)
        cout<<"queue is full"<<endl;
    }
    else
    {
        if(Q.front==-1)
        {
            Q.rear = 0, Q.front=0;
        }
        else
        {
            Q.front = (Q.front-1);
            if(Q.front<0)
            Q.front = Q.size+Q.front;
        }
        Q.elements[Q.front].i=x;
         Q.elements[Q.rear].tag[Q.rear]=1;
        
    }
    
}
void enqueueRearChar(struct queue &Q, char x)
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
         Q.elements[Q.rear].tag[Q.rear]=2;
        
    }
    
}
void enqueueFrontChar(struct queue &Q, char x)
{

    if(Q.front-1==Q.rear||Q.front-1+Q.size==Q.rear)
    {
        if(Q.front-1+Q.size==Q.rear)
        cout<<"queue is full"<<endl;
        else if(Q.front-1==Q.rear)
        cout<<"queue is full"<<endl;
    }
    else
    {
        if(Q.front==-1)
        {
            Q.rear = 0, Q.front=0;
        }
        else
        {
            Q.front = (Q.front-1);
            if(Q.front<0)
            Q.front = Q.size+Q.front;
        }
        Q.elements[Q.front].c=x;
         Q.elements[Q.rear].tag[Q.rear]=2;
        
    }
    
}

int dequeueFront(struct queue &Q)
{
    int t;
    if(Q.front==-1&&Q.rear==-1)
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
int dequeueRear(struct queue &Q)
{
    int t;
    if(Q.rear==-1&&Q.front==-1)
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
            t = Q.elements[Q.rear].i;

            Q.rear = (Q.rear-1);
            if(Q.rear<0)
            Q.rear = Q.rear+Q.size;
        }
        return t;
    }
    
}
char dequeueFrontChar(struct queue &Q)
{
    char t;
    if(Q.front==-1&&Q.rear==-1)
    {
        cout<<"Queue is empty"<<endl;
        return '1';
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
char dequeueRearChar(struct queue &Q)
{
    char t;
    if(Q.rear==-1&&Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return '1';
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
            t = Q.elements[Q.rear].c;

            Q.rear = (Q.rear-1);
            if(Q.rear<0)
            Q.rear = Q.rear+Q.size;
        }
        return t;
    }
    
}
int main()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    enqueueFrontChar(Q, 'N');
    enqueueRear(Q, 17);
    // enqueueFrontChar(Q, 'N');
    enqueueFrontChar(Q, 'I');
    enqueueFrontChar(Q, 'T');
    enqueueRear(Q, 9);
    enqueueFrontChar(Q, 'C');
    enqueueRear(Q, 20);
    enqueueFrontChar(Q, 'S');
    enqueueRear(Q, 21);
    enqueueFrontChar(Q, 'E');
    int i=1;
    while(i<=4)
    {
        cout<<dequeueRear(Q)<<" ";
        i++;
    }
}