#include <iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    string elements[50];
};
void enqueue(struct queue &Q, string x)
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

string dequeue(struct queue &Q)
{
    string t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return "-1";
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
int main()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    int n;
    cin>>n;
    string dequ("1"),enq1, enq2;
    cout<<"0 ";
    enqueue(Q, dequ);
    for(int i=1;i<n;i++)
    {
        dequ = dequeue(Q);
        cout<<dequ<<" ";
        enq1 = dequ + "0";
        enqueue(Q, enq1);
        enq2 = dequ+"1";
        enqueue(Q, enq2);
    }

}