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

void postfix_to_prefix(struct stack *s1, string postfix,int i )
{
     string  operat("+-*/"),sendString(""), operand1, operand2;
     int foundIn = operat.find(postfix[i]);
     if(i == postfix.length())
     {
     }
     else
     {
        if(foundIn==-1)
        {
            push(s1, getString(postfix[i]));
        }
        else
        {
            operand1 = pop(s1);
            operand2 = pop(s1);
            sendString = getString(postfix[i]) + operand2 + operand1;
            
            push(s1, sendString);           
        }
        postfix_to_prefix(s1, postfix, i+1);
     }
       
}
void infix_to_postfix(struct stack *s1, string infixStr,int i, string &postStr)
{
        string operat("+-*/"),topMoCh;
        int power, topMochPow,foundInInfix;
        if(i == infixStr.length())
        {
        }
        else
        {
            foundInInfix =operat.find(infixStr[i]);
            // cout<<"came in loop   "<<foundInInfix<<endl;
            if(infixStr[i]=='(')
            {
                push(s1, getString('('));
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
                        topMoCh = peep(s1);
                        if(topMoCh=="+"||topMoCh=="-") { topMochPow =1;}
                        else if (topMoCh =="("){topMochPow = -1;}
                        else {topMochPow =2;}
                    }


                    if(power<=topMochPow&&s1->top>-1)
                    {
                        // cout<<pop(s1);
                        postStr = postStr+pop(s1);

                    }
                    else
                    {
                        push(s1, getString(infixStr[i]));
                        break;
                    }
                    j++;
                }
                

            }
            else if(infixStr[i]==')')
            {
                while (true)
                {
                    if(peep(s1)!="("&&s1->top>-1)
                    {
                        // cout<<pop(s1);
                        postStr = postStr+pop(s1);
                    
                    }
                    else if(peep(s1)=="("){pop(s1);break;}
                    else {break;}
                }
            }
            else
            {
                // cout<<infixStr[i];
                postStr = postStr+infixStr[i];
            
            }
            infix_to_postfix(s1, infixStr, i+1, postStr);

        }
        

}

void postfix_to_infix(struct stack *s1, string postfix,int i)
{
     string  operat("+-*/"),sendString(""),operand2,operand1;
     int foundIn = operat.find(postfix[i]);
     if(i == postfix.length())
     {
     }
     else
     {
        if(foundIn==-1)
        {
            push(s1, getString(postfix[i]));
        }
        else
        {
            operand1 = pop(s1);
            operand2 = pop(s1);
            sendString = "(" + operand2 + getString(postfix[i]) +  operand1 +")";
            push(s1, sendString);        
        }
        postfix_to_infix(s1, postfix, i + 1);
     }

    
}
int main()
{
    struct stack *s1;
    s1 = new(stack);
    s1->top = -1;
    int op;
    cout<<"enter the repective key to perform that operation:"<<endl<<
    "1: prefix to postfix"<<endl<<
    "2: postfix to prefix"<<endl<<
    "3: infix to postfix"<<endl<<
    "4: infix to prefix"<<endl<<
    "5: postfix to infix"<<endl<<
    "6: prefix to infix"<<endl;
    cin>>op;
    cin.ignore();
    string input_string;
   
    if(op==1)
    {
         getline(cin,input_string);
         int i= input_string.length()-1;
        prefix_to_postfix(s1, input_string, i);
        cout<<pop(s1)<<endl;
    }
    else if(op==2)
    {
        getline(cin,input_string);
         int i= input_string.length()-1;
        postfix_to_prefix(s1, input_string, 0);
        cout<<pop(s1)<<endl;

    }
    else if (op==3)
    {
        getline(cin,input_string);
         int i= input_string.length()-1;
        string postStr="";
        infix_to_postfix(s1, input_string, 0, postStr);
        while(s1->top != -1)
        {
            // cout<<pop(s1);
            postStr = postStr+pop(s1);
        
        }
        cout<<postStr;

    }
    else if(op==4)
    {
        getline(cin,input_string);
         int i= input_string.length()-1;
        string postStr="";
        infix_to_postfix(s1, input_string, 0, postStr);
        while(s1->top != -1)
        {
            // cout<<pop(s1);
            postStr = postStr+pop(s1);
        
        }
        cout<<postStr<<endl;
        postfix_to_prefix(s1, postStr, 0);
        cout<<pop(s1)<<endl;

    }
    else if (op==5)
    {
        getline(cin,input_string);
         int i= input_string.length()-1;
        postfix_to_infix(s1, input_string, 0);
        cout<<pop(s1)<<endl;

    }
    else if (op==6)
    {
        getline(cin,input_string);
         int i= input_string.length()-1;
        prefix_to_postfix(s1, input_string, i);
        input_string = pop(s1);
        postfix_to_infix(s1, input_string, 0);
        cout<<pop(s1)<<endl;
    }
    else
    {
        cout<<"Sorry wrong Input"<<endl;
    }
    
}





































