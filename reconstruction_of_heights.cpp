#include <iostream>
using namespace std;
struct coordinate
{
    int height;
    int number;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct coordinate elements[500];
};
void enqueue(struct queue &Q, struct coordinate curInSta)
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
        Q.elements[Q.rear].height=curInSta.height;
        Q.elements[Q.rear].number=curInSta.number;
        
    }
    
}

struct coordinate dequeue(struct queue &Q)
{
    struct coordinate t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return { -1, -1};
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
void BubbleSort(struct coordinate inpqu[], int n)
{
    for( int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(inpqu[j].number>inpqu[j+1].number)
            {
                swap(inpqu[j], inpqu[j+1]);
            }
            else if(inpqu[j].number==inpqu[j+1].number&&inpqu[j].height>inpqu[j+1].height)
            {
                swap(inpqu[j], inpqu[j+1]);
            }
        }
    }
}
int main()
{
    struct queue Q;
    Q.size = 100;
    Q.rear = -1;
    Q.front = -1;
    int n;
    cin>>n;
    struct coordinate inpqu[n], getOn;
    int A[n], max =-9999;
    for(int i=0;i<n;i++)
    {
        cin>>inpqu[i].height;
        cin>>inpqu[i].number;
    }
    BubbleSort(inpqu, n);
    for(int i=0;i<n;i++)
    {
        max = inpqu[i].height>max?inpqu[i].height:max;
    }
    int fr[max+1];
    for (int i = 0; i <=max; i++)
    {
        fr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(inpqu[i].number==0)
        {
            enqueue(Q, inpqu[i]);
            for (int j = 0; j <=inpqu[i].height; j++)
            {
                fr[j]++;
            }

        }
    }
    for(int i=0;i<=max;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==inpqu[j].height&&fr[i]==inpqu[j].number)
            {
                enqueue(Q, inpqu[j]);
                for (int k = 0; k <=inpqu[j].height; k++)
                {
                    fr[k]++;
                }
                i=0;
                break;
            }
        }
    }
    while(Q.front!=-1)
    {
        getOn = dequeue(Q);
        cout<<"("<<getOn.height<<","<<getOn.number<<") ";
    }

    
}
