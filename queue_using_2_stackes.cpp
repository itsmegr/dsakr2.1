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
        return -1;
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
        return -1;
    }
    else
    {
        return s->elements[s->top];
    }
    
}
void enqueueCostly(struct stack *s1,struct stack *s2, int x)
{
    if(s1->top==s1->size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        if(s1->top==-1)
        {
            push(s1, x);
        }
        else
        {
            while (s1->top!=-1)
            {
                push(s2, pop(s1));
            }
            push(s1, x);
            while (s2->top!=-1)
            {
                push(s1, pop(s2));
            }    
        }
    }
    
    
}
int dequeue(struct stack *s1)
{
    return pop(s1);
}
void enqueue(struct stack *s1, int x)
{
    push(s1, x);
}
int dequeueCostly(struct stack *s1,struct stack *s2)
{
    int element;
    if(s1->top==-1)
    {
        cout<<"queue is empty";
        return -1;
    }
    else
    {
        while (s1->top!=0)
        {
            push(s2, pop(s1));
        }
        element = pop(s1);
        while (s2->top!=-1)
        {
            push(s1, pop(s2));
        }
        return element;
    }
    
}

void enqueueCostlyFunc(struct stack *s1,struct stack *s2)
{
    int action,element;
    while (true)
    {
        cout<<"want to enqueue or dequeue? 2 for enqueue, 1 for dequeue and any other key to stop "<<endl;
        cin>>action;
        if(action==1)
        {
            cout<<dequeue(s1)<<endl;
        }
        else if(action==2)
        {
            cout<<"enter the element "<<endl;
            cin>>element;
            enqueueCostly(s1, s2, element);
        }
        else
        {
            break;
        }
        
    }
    
}

void dequeueCostlyFunc(struct stack *s1,struct stack *s2)
{
    int action,element;
    while (true)
    {
        cout<<"want to enqueue or dequeue? 2 for enqueue, 1 for dequeue and any other key to stop "<<endl;
        cin>>action;
        if(action==1)
        {
            cout<<dequeueCostly(s1,s2)<<endl;
        }
        else if(action==2)
        {
            cout<<"enter the element "<<endl;
            cin>>element;
            enqueue(s1, element);
        }
        else
        {
            break;
        }
        
    }
}





int main()
{
    struct stack *s1, *s2;
    s1 = new(stack);
    s2 = new(stack);
    s1->size = 30;
    s1->top = -1;
    s2->size = 30;
    s2->top = -1;
    int progTy; 
    cout<<"What kind of programme you want run 1 for enqueue Costly and 2 for DequeueCostly"<<endl;
    cin>>progTy;
    if(progTy==1)
    enqueueCostlyFunc(s1, s2);
    else if (progTy==2)
   dequeueCostlyFunc(s1,s2);
    else
    cout<<"Sorry Invalid Inpput";
}