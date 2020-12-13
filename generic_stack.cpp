#include <iostream>
using namespace std;
#include<string>
union stacData
{
    char c;
    int i;
    float f;
};

struct stack
{
    int size;
    int top;
    union stacData elements[100];
};
void pushInt (struct stack *s, int x)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->top].i = x;
        }
        
    }
void pushfloat (struct stack *s, float x)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->top].f = x;
        }
        
    }
void pushchar (struct stack *s, char x)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->top].c = x;
        }
        
    }
union stacData pop(struct stack *s)
{
    union stacData retUn;
    if(s->top==-1)
    {
        retUn.c = '\0', retUn.i = -1, retUn.f = -1.0;
        return retUn;
    }
    else
    {
       retUn = s->elements[s->top--];
       return  retUn;
    }
    
}

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    string postStr,operat("+-*/");
    s1->size=100;
    s1->top =-1;
    int tag[100],i=0,pushn;
    char pushch;
    float pushfl;
    while(true)
    {
        cout<<"what do want to push in Stack 1 for int, 2 for float, 3 for char and any key to pop"<<endl;
        cin>>tag[i];
        if(tag[i]==1)
        {
            cin>>pushn;
            pushInt(s1, pushn);
            i++;
        }
        else if(tag[i]==2)
        {
            cin>>pushfl;
            pushfloat(s1, pushfl);
            i++;

        }
        else if(tag[i]==3)
        {
            cin>>pushch;
            pushchar(s1, pushch);
            i++;
        }
        else
        {
            i--;
            break;
            
        }
        
           
    }
    union stacData getUn;
    while(s1->top!=-1)
    {
        getUn = pop(s1);
        if(tag[i]==1)
        cout<<getUn.i<<endl;
        else if(tag[i]==2)
        cout<<getUn.f<<endl;
        else if(tag[i]==3)
        cout<<getUn.c<<endl;

        i--;  
    }
 


    
    
}