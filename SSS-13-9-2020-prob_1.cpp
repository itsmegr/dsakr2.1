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
    struct stack *s2;
    s1 = new(stack);
    s2 = new(stack);
    s1->size = 50;
    s1->top = -1;
    s2->size = 50;
    s2->top = -1;
    int size,pushEl,i,max;
    cout<<"Enter the size of stack";
    cin>>size;
    cout<<"enter the elements of satck";
    for(i=0;i<size;i++)
    {
        cin>>pushEl;
        push(s1, pushEl);
    }
    i=-1;
    for(int j=1;j<=size;j++)
    {
        max = -9999;
        while(s1->top != i)
        {
            if(peep(s1)>max&&s1->top == size-1)
            {
                max = pop(s1);
            }
            else if (peep(s1)>max&&s1->top != size-1)
            {
                push(s2, max);
                max = pop(s1);

            }
            
            else
            {
                push(s2, pop(s1));
            }
            
        }
        push(s1, max);
        while(s2->top!=-1)
        {
            push(s1, pop(s2));
        }
        i++;
    }
    while(s1->top!=-1)
    {
            cout<<pop(s1)<<" ";
    }
}

 