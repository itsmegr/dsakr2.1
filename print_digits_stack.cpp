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

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    s1->size = 15;
    s1->top = -1;
    int number;
    cin>>number;
    while(number>0)
    {
        push(s1, number%10);
        number= number/10;
    }
    while(s1->top!=-1)
    {
        cout<<(pop(s1))<<" ";
    }

}

