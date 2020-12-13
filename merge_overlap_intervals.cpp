#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int elements[50];

};
void push (struct stack *s, int x)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->top] = x;
        }
        
    }

int pop(struct stack *s)
{
    if(s->top==-1)
    {
        cout<<"stack is empty";
        return 0;
    }
    else
    {
        return s->elements[s->top--];
    }
    
}
int peep(struct stack *s)
{
    if(s->top==-1)
    {
        cout<<"stack is empty";
        return 0;
    }
    else
    {
        return s->elements[s->top];
    }
    
}

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    s1->size = 15;
    s1->top = -1;
    int interval_start, interval_end,outputIn[2],j;
    
    for(int i=1;i<=6;i++)
    {
        j=1;
        cin>>interval_start>>interval_end;
        if(s1->top==-1)
        {
            push(s1, interval_start);
            push(s1, interval_end);
        }
        else if(interval_start > peep(s1))
        {
            while(s1->top!=-1)
            {
                outputIn[j]= pop(s1);
                j--;
            }
            cout<<"{"<<outputIn[0]<<","<<outputIn[1]<<"}"<<endl;
            push(s1, interval_start);
            push(s1, interval_end);
        }
        else if(interval_end>peep(s1))
        {
            pop(s1);
            push(s1, interval_end);
        }
  

    }
    j=pop(s1);
    cout<<"{"<<pop(s1)<<","<<j<<"}"<<endl;
}