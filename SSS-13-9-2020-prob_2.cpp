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
void compute_score(struct stack *s1,struct stack *s2, string str)
{
    if(str.length()==1)
    {

    }
    else
    {
        int i=0;
        while(i<str.length())
        {
            if(str[i]=='('&&str[i+1]==')')
            {
                str.erase(i+1,1);
                str.replace(i, 1, "*");
                push(s1,1);
                i++;
            }
            else if(str[i]=='('&&str[i+1]=='*'&&str[i+2]==')')
            {
                str.erase(i+1,2);
                str.replace(i, 1, "*");
                push(s2, (2*pop(s1)));
                i++;
            }
            else if(str[i]=='*')
            {
                if(str[i+1]=='*')
                {
                    str.erase(i+1,1);
                    push(s2, (pop(s1)+pop(s1)));
                    i++;
                }
                else
                {
                    push(s2, pop(s1));
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        while(s2->top !=-1)
        {
            push(s1, pop(s2));
        }
        compute_score(s1, s2,str);
    }  
}
int main()
{
    struct stack *s1, *s2;
    s1 = new(stack);
    s1->size = 50;
    s1->top = -1;
    s2 = new(stack);
    s2->size = 50;
    s2->top = -1;
    string str;
    getline(cin, str);
    compute_score(s1, s2,str);
    cout<<pop(s1);
}