#include <iostream>
using namespace std;
#include<string>

struct stack
{
    int size = 1000;
    int top;
    string elements[50];

};
void push (struct stack *s, string x)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->top] = x;
        }
        
    }

string pop(struct stack *s)
{
    if(s->top==-1)
    {
        return "-1";
    }
    else
    {
       
        return  s->elements[s->top--];
    }
    
}
string peep(struct stack *s)
{
    if(s->top==-1)
    {
        return "-1";
    }
    else
    {
        return  s->elements[s->top];
    }

}
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 

void prefix_to_postfix(struct stack *s1, string prefix,int i )
{
     string  operat("+-*/"),sendString("");
     int foundIn = operat.find(prefix[i]);
     if(i == -1)
     {
     }
     else
     {
        if(foundIn==-1)
        {
            push(s1, getString(prefix[i]));
        }
        else
        {
            sendString = sendString + pop(s1);
            sendString = sendString + pop(s1);
            sendString = sendString + getString(prefix[i]);
            push(s1, sendString);           
        }
        prefix_to_postfix(s1, prefix, i-1);
     }
     

}


int main()
{
    struct stack *s1;
    s1 = new(stack);
    s1->top = -1;
    int op;
    cin>>op;
    cin.ignore();
    string input_string;
    getline(cin,input_string);
    int i= input_string.length()-1; 
    prefix_to_postfix(s1, input_string, i);
    cout<<pop(s1)<<endl;
   
}