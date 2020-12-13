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
void printF(struct stack *s)
{
    if(s->top==-1)
    {

    }
    else
    {
       int x = pop(s);
       printF(s);
       cout<<x<<" ";
    }
    
}
int minElement(int *Array, int len)
{
    int min = 99999;
    for(int i=0;i<len;i++)
    {
        if(Array[i]<min)
        {
            min = Array[i];
        }
    }
    return min;
}

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    s1->size = 50;
    s1->top = -1;
    int n,B;
    cin>>n;
    int A[n],max,min,len,area;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int subArray[50];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            len =0;
            for(int k=i;k>=j;k--)
            {
                subArray[i-k] = A[k];
                len++;
            }
            min = minElement(subArray,len);
            // push(s1, min*(len));
            area = min*len;
            if(s1->top ==-1)
            {
                push(s1, area);
            }
            else
            {
                if(area>peep(s1))
                {
                    push(s1, area); 
                    
                }
            }
        }
  
        
    }
    cout<<peep(s1);
}

