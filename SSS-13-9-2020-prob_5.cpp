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
void insert(struct stack *s, int x)
{
    if(s->top==-1)
    {
        push(s, x);
    }
    else
    {
        int a = pop(s);
        insert(s,x);
        push(s,a);

    }
    
}
void reverse(struct stack *s)
{
    if(s->top==-1)
    {

    }
    else
    {
       int x = pop(s);
       reverse(s);
       insert(s, x); 
    }
    
}

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    s1->size = 50;
    s1->top = -1;
    int n,B;
    cin>>n;
    int A[n],max;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        push(s1, A[i]);
    }
    reverse(s1);
    while(s1->top!=-1)
    {
        cout<<pop(s1)<<" ";
    }
}

