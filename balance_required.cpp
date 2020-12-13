#include <iostream>
using namespace std;
#include<string>

struct stack
{
    int size;
    int top;
    char elements[50];

};
void push (struct stack *s, char x)
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
        return -1;
    }
    else
    {
       
        return  s->elements[s->top--];
    }
    
}
int peep(struct stack *s)
{
      if(s->top==-1)
    {
        return -1;
    }
    else
    {
        return  s->elements[s->top];
    }

}

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    string symStr,OP("{[("),CP("}])");
    char returnCha;
    int foundIn,i,foundInCl,k=0;
    s1->size = 1000;
    s1->top = -1;
    getline(cin, symStr);
    
    
    for( i=0;i<symStr.length();i++)
    {
        foundIn = OP.find(symStr[i]);
        foundInCl = CP.find(symStr[i]);

        if(foundIn>-1)
        {
            push(s1, symStr[i]);
        }
        else if (foundInCl>-1)
        {
            if(peep(s1)==-1)
            {
                k++;
            }
            else
            {
                pop(s1);
            }
            
        }

    }

 if(k==0)
 {
     cout<<(s1->top)+1;
 }
 else
 {
     cout<<k;
 }  
}