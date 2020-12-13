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
    struct coordinate elements[50];
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

int main()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    int A[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            A[i][i]=0;
        }
    }
    for(int i=1;i<=6;i++)
    {
        A[1][i] =1;
        if(i!=2)
        {
            A[3][i]=1;
        }
        if(i!=5)
        {
            A[6][i]=1;
        }
    }
    A[2][1]=1, A[2][3]=1, A[4][6]=1,A[5][1]=1,A[5][4]=1,A[5][6]=1;
    struct coordinate curr, retuCu,pushCo,discovered;
    int stx, sty, desx, desy;
    cin>>stx>>sty>>desx>>desy;
    int i=0;
    pushCo.x=stx;
    pushCo.y = sty;
    enqueue(Q, pushCo);
    A[sty][stx]=0;

    while(true)
    {
        if(Q.front==-1)
        {
            cout<<"NO SOLUTION";
            break;
        }
        else
        {
            curr = dequeue(Q);
            A[curr.y][curr.x]=0;
            // cout<<curr.x<<" "<<curr.y;
            if(curr.x==desx&&curr.y==desy)
            {
                cout<<"found a route"<<endl;
                break;
            }
               
            else
            {
                if(A[curr.y][(curr.x)-1]==1)
                {
                    A[curr.y][(curr.x)-1]==0;
                    pushCo.x=(curr.x)-1;
                    pushCo.y = curr.y;
                    enqueue(Q, pushCo);
                   

                                                                                                                                                                                                                                                                                                                                                                                                                               

                }
                if(A[curr.y][(curr.x)+1]==1)
                {
                    A[curr.y][(curr.x)+1]==0;
                    pushCo.x=(curr.x)+1;
                    pushCo.y = curr.y;
                    enqueue(Q, pushCo);
                   


                }
                if(A[(curr.y)-1][curr.x]==1)
                {
                    A[(curr.y)-1][curr.x]==0;
                    pushCo.x=curr.x;
                    pushCo.y = (curr.y)-1;
                    enqueue(Q, pushCo);
                   


                }
                if(A[(curr.y)+1][curr.x]==1)
                {
                     A[(curr.y)+1][curr.x]==0;
                     pushCo.x=curr.x;
                     pushCo.y = (curr.y)+1;
                     enqueue(Q, pushCo);
                   

                }
            }
            
        }
        i++;
        

    }




}