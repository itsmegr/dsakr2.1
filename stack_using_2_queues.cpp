#include <iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int elements[50];
};
void enqueue(struct queue &Q, int x)
{
    if(((Q.rear+1)%Q.size)==Q.rear)
    {
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
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear]=x;
        
    }
    
}

int dequeue(struct queue &Q)
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
void pushCostly(struct queue &Q1,struct queue &Q2,int x)
{
    if(((Q1.rear+1)%Q1.size)==Q1.rear)
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        if(Q1.front==-1)
        {
            enqueue(Q1, x);
        }
        else
        {
            while (Q1.front!=-1)
            {
                enqueue(Q2, dequeue(Q1));
            }
            enqueue(Q1, x);
            while (Q2.front!=-1)
            {
                enqueue(Q1, dequeue(Q2));
            }      
        }
    }
    
    
}
int pop(struct queue &Q1)
{
    return dequeue(Q1);
}
void push(struct queue &Q1, int x)
{
    enqueue(Q1, x);
}
int popCostly(struct queue &Q1,struct queue &Q2)
{
    int element;
    if(Q1.front==-1)
    {
        cout<<"stack is empty";
        return -1;
    }
    else
    {
        while (Q1.front!=Q1.rear)
        {
            enqueue(Q2, dequeue(Q1));
        }
        element = dequeue(Q1);
        while (Q2.front!=-1)
        {
            enqueue(Q1, dequeue(Q2));
        }
        return element;
    }
    
}

void pushCostlyFunc(struct queue &Q1,struct queue &Q2)
{
    int action,element;
    while (true)
    {
        cout<<"want to Push or pop 1 for push 2 for pop and aby other key to stop "<<endl;
        cin>>action;
        if(action==1)
        {
            cout<<pop(Q1)<<endl;
        }
        else if(action==2)
        {
            cout<<"enter the element "<<endl;
            cin>>element;
            pushCostly(Q1, Q2, element);
        }
        else
        {
            break;
        }
        
    }
    
}

void popCostlyFunc(struct queue &Q1,struct queue &Q2)
{
    int action,element;
    while (true)
    {
        cout<<"want to Push or pop 1 for push 2 for pop and aby other key to stop "<<endl;
        cin>>action;
        if(action==1)
        {
            cout<<popCostly(Q1, Q2)<<endl;
        }
        else if(action==2)
        {
            cout<<"enter the element "<<endl;
            cin>>element;
            push(Q1, element);
        }
        else
        {
            break;
        }
        
    }
}





int main()
{
    struct queue Q1,Q2;
    Q1.size = 30;
    Q1.rear = -1;
    Q1.front = -1;
    Q2.size = 30;
    Q2.rear = -1;
    Q2.front = -1;
    int element,progTy; 
    cout<<"What kind of programme you want run 1 for push COstly and 2 for POPCostly"<<endl;
    cin>>progTy;
    if(progTy==1)
    pushCostlyFunc(Q1, Q2);
    else if (progTy==2)
    popCostlyFunc(Q1, Q2);
    else
    cout<<"Sorry Invalid Inpput";
}