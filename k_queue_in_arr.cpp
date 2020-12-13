#include <iostream>
using namespace std;
struct queue
{
    int size;
    int front[5];
    int rear[5];
    int elements[50];
};
void enqueue(struct queue &Q, int i, int x)
{
    if(((Q.rear[i]+1)%Q.size)==Q.rear[i])
    {
        cout<<"queue is full"<<endl<<endl;
    }
    else
    {
        if(Q.front[i]==-1)
        {
            Q.rear[i] = (i*5)-5, Q.front[i]= (i*5)-5;
        }
        else
        {
            Q.rear[i] = (Q.rear[i]+1)%Q.size;
        }
        Q.elements[Q.rear[i]]=x;
        
    }
    
}

int dequeue(struct queue &Q,int i)
{
    int t;
    if(Q.front[i]==-1)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        if(Q.front==Q.rear)
        {
            t = Q.elements[Q.front[i]];
            Q.front[i]=-1, Q.rear[i]=-1;
        }
        else
        {
            t = Q.elements[Q.front[i]];
            Q.front[i] = (Q.front[i]+1)%Q.size;
        }
        return t;
    }
    
}
int main()
{
    struct queue Q;
    Q.size = 10;
    for(int i=0;i<5;i++)
    {
        Q.rear[i] = -1;
        Q.front[i]= -1;
    }
    enqueue(Q, 2, 5);
    enqueue(Q, 4, 10);
    cout<<dequeue(Q, 4);


}