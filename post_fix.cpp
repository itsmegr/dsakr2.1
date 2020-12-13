#include <iostream>
using namespace std;
#include<string>

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
int evalu(int operand1, int operand2, char opertr)
{
    switch (opertr)
    {
    case '+':
        return operand1+operand2;
        break;
    case '-':
        return operand1-operand2;
        break;
    
    case '*':
        return operand1*operand2;
        break;
    
    case '/':
        return operand1/operand2;
        break;
    
    default:
    return 0;
        break;
    }

}

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    string postStr,operatSec("+-*/");
    s1->size=100;
    s1->top =-1;
    getline(cin,postStr);
    int foundIn,operand1, operand2, finalAn;
    for(int i=0;i<postStr.length();i++)
    {
        
        foundIn = operatSec.find(postStr[i]);
        if(foundIn==-1)
        {
            push(s1, int(postStr[i])-48);
        }
        else
        {
            operand2 = pop(s1);
            operand1 = pop(s1);
            finalAn = evalu(operand1, operand2, postStr[i]);
            push(s1, finalAn);
            


        }
        
    }
    cout<<s1->elements[s1->top]<<endl;

    
    
}