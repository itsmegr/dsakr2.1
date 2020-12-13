#include <iostream>
#include <string>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int elements[50];
};
void enqueue(struct queue &Q, int x)
{
    if(((Q.rear+1)%Q.size)==Q.rear)
    {
        cout<<"queue is full"<<endl;
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
        Q.elements[Q.rear]=x;
        
    }
    
}

int dequeue(struct queue &Q)
{
    int t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return 1;
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
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
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
int main()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    struct stack *s1;
    s1 = new(stack);
    s1->size = 15;
    s1->top = -1;
    int n,element;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        enqueue(Q, element);
    }
    for(int i=1;i<=n;i++)
    {
       if(i<=n/2)
       {
            element = dequeue(Q);
            enqueue(Q, element);
       }
       else
       {
          element = dequeue(Q);
          push(s1, element);
       }
       
    }
    reverse(s1);
    for(int i=1;i<=n/2;i++)
    {
        element = dequeue(Q);
        enqueue(Q, element);
        element = pop(s1);
        enqueue(Q, element);
    }
    while(Q.front !=-1)
    {
        cout<<dequeue(Q)<<" ";
    }
  

}