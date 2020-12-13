#include <iostream>
using namespace std;
#include<string>


struct coordinate
{
    int x;
    int y;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct coordinate elements[100];
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
        Q.elements[Q.rear].x=curInSta.x;
        Q.elements[Q.rear].y=curInSta.y;
        
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
void neg_to_pos(struct queue &Q,int A[][5], int i, int j)
{
    struct coordinate pushCo;
    if(A[i-1][j]<0&&i-1>=0)
    {
        pushCo.x =i-1;
        pushCo.y =j;
        enqueue(Q, pushCo);
    }
    if(A[i+1][j]<0&&i+1<4)
    {
        pushCo.x =i+1;
        pushCo.y =j;
        enqueue(Q, pushCo);
    }
    if(A[i][j-1]<0&&j-1>=0)
    {
        pushCo.x =i;
        pushCo.y =j-1;
        enqueue(Q, pushCo);
    }
    if(A[i][j+1]<0&&j+1<5)
    {
        pushCo.x =i;
        pushCo.y =j+1;
        enqueue(Q, pushCo);
    }
}

int main()
{
    struct queue Q;
    Q.size = 100;
    Q.rear = -1;
    Q.front = -1;
    int A[4][5]={
        {-1,-9,0,-1,0},
        {-8,-3,-2,9,-7},
        {2,0,0,-6,0},
        {0,-7,-3,5,-4}
    };
    struct coordinate getCo;
    int count=0;
    while (true)
    {
        int i;
        for(i=0;i<4;i++)
        {
            int j;
            for(j=0;j<5;j++)
             if(A[i][j]<0) break;
            if(j<5) break;
        }
        if(i==4) break;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(A[i][j]>0)
                neg_to_pos(Q,A, i,j);
            }
        }

        while(Q.front!=-1)
        {
           getCo = dequeue(Q);    
           if( A[getCo.x][getCo.y]<0)
           A[getCo.x][getCo.y] = -1 * A[getCo.x][getCo.y];
        }
        count++;
    }
    cout<<count;
}