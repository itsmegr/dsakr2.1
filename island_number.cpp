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
void maze(struct queue &Q, int A[][10], int stx, int sty, int &count)
{
    struct coordinate curr, retuCu,pushCo,discovered;
    int i=0;
    pushCo.x=stx;
    pushCo.y = sty;
    enqueue(Q, pushCo);
    A[sty][stx]=0;

    while(true)
    {
        if(Q.front==-1)
        {
            count++;
            break;
        }
        else
        {
            curr = dequeue(Q);
            A[curr.y][curr.x]=0;
            if(A[curr.y][(curr.x)-1]==1&&(curr.x)-1>=0&&curr.y>=0&&(curr.x)-1<10&&curr.y<10)
            {
                A[curr.y][(curr.x)-1]=0;
                pushCo.x=(curr.x)-1;
                pushCo.y = curr.y;
                enqueue(Q, pushCo);               
                                                                                                                                                                                                                                                                                                                                                                                                                            
            }
            if(A[(curr.y)-1][(curr.x)-1]==1&&(curr.y)-1>=0&&(curr.x)-1>=0&&(curr.y)-1<10&&(curr.x)-1<10)
            {
               A[(curr.y)-1][(curr.x)-1]=0;
                pushCo.x=(curr.x)-1;
                pushCo.y = (curr.y)-1;
                enqueue(Q, pushCo);               
                                                                                                                                                                                                                                                                                                                                                                                                                            
            }
            if(A[curr.y][(curr.x)+1]==1&&curr.y>=0&&(curr.x)+1>=0&&curr.y<10&&(curr.x)+1<10)
            {
                A[curr.y][(curr.x)+1]=0;
                pushCo.x=(curr.x)+1;
                pushCo.y = curr.y;
                enqueue(Q, pushCo);
            }
            if(A[(curr.y)+1][(curr.x)+1]==1&&(curr.y)+1>=0&&(curr.x)+1>=0&&(curr.y)+1<10&&(curr.x)+1<10)
            {
               A[(curr.y)+1][(curr.x)+1]=0;
                pushCo.x=(curr.x)+1;
                pushCo.y = (curr.y)+1;
                enqueue(Q, pushCo);
            }
            if(A[(curr.y)-1][curr.x]==1&&(curr.y)-1>=0&&curr.x>=0&&(curr.y)-1<10&&curr.x<10)
            {
                A[(curr.y)-1][curr.x]=0;
                pushCo.x=curr.x;
                pushCo.y = (curr.y)-1;
                enqueue(Q, pushCo);

            }
            if(A[(curr.y)-1][(curr.x)+1]==1&&(curr.y)-1>=0&&(curr.x)+1>=0&&(curr.y)-1<10&&(curr.x)+1<10)
            {
                A[(curr.y)-1][(curr.x)+1]=0;
                pushCo.x=(curr.x)+1;
                pushCo.y = (curr.y)-1;
                enqueue(Q, pushCo);

            }
            if(A[(curr.y)+1][curr.x]==1&&(curr.y)+1>=0&&curr.x>=0&&(curr.y)+1<10&&curr.x<10)
            {
                    A[(curr.y)+1][curr.x]=0;
                    pushCo.x=curr.x;
                    pushCo.y = (curr.y)+1;
                    enqueue(Q, pushCo);
            }
            if(A[(curr.y)+1][(curr.x)-1]==1&&(curr.y)+1>=0&&(curr.x)-1>=0&&(curr.y)+1<10&&(curr.x)-1<10)
            {
                   A[(curr.y)+1][(curr.x)-1]=0;
                    pushCo.x=(curr.x)-1;
                    pushCo.y = (curr.y)+1;
                    enqueue(Q, pushCo);
            }
            
        }
        i++;
    }
}
int main()
{
    struct queue Q;
    Q.size = 500;
    Q.rear = -1;
    Q.front = -1;
    int A[10][10] = 
    {
        {1,0,1,0,0,0,1,1,1,1},
        {0,0,1,0,1,0,1,0,0,0},
        {1,1,1,1,0,0,1,0,0,0},
        {1,0,0,1,0,1,0,0,0,0},
        {1,1,1,1,0,0,0,1,1,1},
        {0,1,0,1,0,0,1,1,1,1},
        {0,0,0,0,0,1,1,1,0,0},
        {0,0,0,1,0,0,1,1,1,0},
        {1,0,1,0,1,0,0,1,0,0},
        {1,1,1,1,0,0,0,1,1,1}
    };
    int count=0, stx,sty;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(A[i][j]==1)
            {

                maze(Q, A, j, i, count);
            }

        }
    }
    cout<<count;
    
}