#include <iostream>
using namespace std;
#include<string>


struct coordinate
{
    int x;
    int y;
};

struct stack
{
    int size =200;
    int top;
    struct coordinate elements[200];
};
void push (struct stack *s, struct coordinate curInSta)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->top++;
            s->elements[s->top].x = curInSta.x;
            s->elements[s->top].y = curInSta.y;
            
        }
        
    }

struct coordinate pop(struct stack *s)
{
    if(s->top==-1)
    {
        return { -1, -1};
    }
    else
    {   
        return  s->elements[s->top--];
    }
    
}
struct coordinate peep(struct stack *s)
{
      if(s->top==-1)
    {
        return {-1, -1};
    }
    else
    {
        return  s->elements[s->top];
    }

}

int main()
{
    struct stack *s1;
    s1 = new(stack);
    s1->top=-1;
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
    // retuCu = pop(s1);
    // cout<<retuCu.x<<" "<<retuCu.y<<endl;
    // retuCu = pop(s1);
    // cout<<retuCu.x<<" "<<retuCu.y;
    int i=0;
    pushCo.x=stx;
    pushCo.y = sty;
    push(s1, pushCo);
    A[sty][stx]=0;

    while(true)
    {
        if(s1->top==-1)
        {
            cout<<"NO SOLUTION";
            break;
        }
        else
        {
            curr = pop(s1);
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
                    push(s1, pushCo);
                   

                                                                                                                                                                                                                                                                                                                                                                                                                               

                }
                if(A[curr.y][(curr.x)+1]==1)
                {
                    A[curr.y][(curr.x)+1]==0;
                    pushCo.x=(curr.x)+1;
                    pushCo.y = curr.y;
                    push(s1, pushCo);
                   


                }
                if(A[(curr.y)-1][curr.x]==1)
                {
                    A[(curr.y)-1][curr.x]==0;
                    pushCo.x=curr.x;
                    pushCo.y = (curr.y)-1;
                    push(s1, pushCo);
                   


                }
                if(A[(curr.y)+1][curr.x]==1)
                {
                     A[(curr.y)+1][curr.x]==0;
                     pushCo.x=curr.x;
                     pushCo.y = (curr.y)+1;
                     push(s1, pushCo);
                   

                }
            }
            
        }
        i++;
        

    }




}