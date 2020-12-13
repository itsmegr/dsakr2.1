#include <iostream>
#include <string>
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
int findMid(string str, int l, int h)
{
    struct stack *s1;
    s1 = new(stack);
    s1->size = 50;
    s1->top = -1;
    int i=l;
   while(i<=h)
    {
        if(str[i]=='(')
        push(s1, i);
        else
        {
            int x = peep(s1);
            if((i-x-1)%2==0)
            pop(s1);
        }
        if(s1->top==-1) break;
        else i++;
        
    }
    return i;
}
int compute_score(string str, int l, int h)
{
    if(h-l==1)
    return 1;
    else
    {
        int mid = findMid(str,l,h);
        if(mid == h)
        return 2*(compute_score(str, l+1, h-1)) ;
        else
        return compute_score(str, l, mid) + compute_score(str, mid+1, h);
        
    }
    
}
int main()
{

    string str;
    getline(cin, str);
    cout<<compute_score(str, 0, str.length()-1);
}