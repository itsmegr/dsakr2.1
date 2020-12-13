#include <iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int elements[50];
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
        Q.elements[Q.rear]=x;
        
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
        Q.elements[Q.front]=x;
        
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
            t = Q.elements[Q.front];
            Q.front=-1, Q.rear=-1;
        }
        else
        {
            t = Q.elements[Q.front];
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
            t = Q.elements[Q.front];
            Q.front=-1, Q.rear=-1;
        }
        else
        {
            t = Q.elements[Q.rear];

            Q.rear = (Q.rear-1);
            if(Q.rear<0)
            Q.rear = Q.rear+Q.size;
        }
        return t;
    }
    
}
void push(struct queue &Q, int x)
{
    enqueueFront(Q, x);
}
int pop(struct queue &Q)
{
   return dequeueFront(Q);
}
void impliment_stack(struct queue &Q)
{
    // push(Q, 5);
    // push(Q, 6);
    // push(Q, 7);
    // push(Q, 8);
    // cout<<pop(Q);
}
void enqueue(struct queue &Q, int x)
{
    enqueueRear(Q, x);
}
int dequeue(struct queue &Q)
{
    return dequeueFront(Q);
}
void impliment_queue(struct queue &Q)
{
    enqueue(Q, 5);
    enqueue(Q, 6);
    enqueue(Q, 7);
    enqueue(Q, 8);
    cout<<dequeue(Q);
}
int main()
{
    struct queue Q;
    Q.size = 5;
    Q.rear = -1;
    Q.front = -1;

    impliment_stack(Q);
    impliment_queue(Q);

}