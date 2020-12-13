#include <iostream>
using namespace std;
#include<string>

struct stack
{
    int size;
    int top;
    char elements[50];

};
void pushIn (struct stack *s, char x)
    {
        if(s->top == s->size -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->top] = x;
        }
        
    }

char popIn(struct stack *s)
{
    if(s->top==-1)
    {
        return 'n';
    }
    else
    {
       
        return  s->elements[s->top--];
    }
    
}
char peepIn(struct stack *s)
{
      if(s->top==-1)
    {
        return 'n';
    }
    else
    {
        return  s->elements[s->top];
    }

}
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
    string postStr(""),infixStr,operat("+-*/");
    s1->size = 1000;
    s1->top = -1;
    getline(cin, infixStr);
    int power, topMochPow,foundInInfix;
    char topMoCh;
    for(int i=0;i<infixStr.length();i++)
    {
        foundInInfix =operat.find(infixStr[i]);
        // cout<<"came in loop   "<<foundInInfix<<endl;
        if(infixStr[i]=='(')
        {
            pushIn(s1, '(');
        }
        else if(foundInInfix!=-1)
        {
            if(infixStr[i]=='+'||infixStr[i]=='-') { power =1;}
            else {power =2;}
            int j =1;
            
            while(j<10)
            {
                if(s1->top>-1)
                {
                    topMoCh = peepIn(s1);
                    if(topMoCh=='+'||topMoCh=='-') { topMochPow =1;}
                    else if (topMoCh =='('){topMochPow = -1;}
                    else {topMochPow =2;}
                }


                if(power<=topMochPow&&s1->top>-1)
                {
                    // cout<<popIn(s1);
                    postStr = postStr+popIn(s1);

                }
                else
                {
                    pushIn(s1, infixStr[i]);
                    break;
                }
                j++;
            }
            

        }
        else if(infixStr[i]==')')
        {
            while (true)
            {
                if(peepIn(s1)!='('&&s1->top>-1)
                {
                    // cout<<popIn(s1);
                    postStr = postStr+popIn(s1);
                
                }
                else if(peepIn(s1)=='('){popIn(s1);break;}
                else {break;}
            }
        }
        else
        {
            // cout<<infixStr[i];
            postStr = postStr+infixStr[i];
         
        }
        
    }


    while(s1->elements[s1->top]!=-1)
    {
        // cout<<popIn(s1);
        postStr = postStr+popIn(s1);
      
    }
















    string operatSec("+-*/");
    int foundInPo,operand1, operand2, finalAn;
    for(int i=0;i<postStr.length();i++)
    {
        
        foundInPo = operatSec.find(postStr[i]);
        if(foundInPo==-1)
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
    cout<<peep(s1)<<endl;
    
}