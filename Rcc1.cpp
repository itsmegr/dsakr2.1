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
        return 1;
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

void reverse(struct queue &Q)
{
    if(Q.rear!=-1)
    {
        int n = dequeue(Q);
        reverse(Q);
        cout<<n<<" ";
        enqueue(Q, n);
    }
     
}
int main()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    struct stack *s1;
    int n,element;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        enqueue(Q, element);
    }
    reverse(Q);
}