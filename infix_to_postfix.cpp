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

char pop(struct stack *s)
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
char peep(struct stack *s)
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

int main ()
{
    struct stack *s1;
    s1 = new(stack);
    string infixStr,operat("+-*/");
    s1->size = 1000;
    s1->top = -1;
    getline(cin, infixStr);
    int power, topMochPow,foundIn;
    char topMoCh;
    for(int i=0;i<infixStr.length();i++)
    {
        foundIn =operat.find(infixStr[i]);
        // cout<<"came in loop   "<<foundIn<<endl;
        if(infixStr[i]=='(')
        {
            push(s1, '(');
        }
        else if(foundIn!=-1)
        {
            if(infixStr[i]=='+'||infixStr[i]=='-') { power =1;}
            else {power =2;}
            int j =1;
            
            while(j<10)
            {
                if(s1->top>-1)
                {
                    topMoCh = peep(s1);
                    if(topMoCh=='+'||topMoCh=='-') { topMochPow =1;}
                    else if (topMoCh =='('){topMochPow = -1;}
                    else {topMochPow =2;}
                }


                if(power<=topMochPow&&s1->top>-1)
                {
                    cout<<pop(s1);
                }
                else
                {
                    push(s1, infixStr[i]);
                    break;
                }
                j++;
            }
            

        }
        else if(infixStr[i]==')')
        {
            while (true)
            {
                if(peep(s1)!='('&&s1->top>-1)
                {
                    cout<<pop(s1);
                }
                else if(peep(s1)=='('){pop(s1);break;}
                else {break;}
            }
        }
        else
        {
            cout<<infixStr[i];
        }
        
    }


    while(s1->elements[s1->top]!=-1)
    {
        cout<<pop(s1);
    }
    
}