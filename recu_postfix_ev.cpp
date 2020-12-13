#include <iostream>
using namespace std;
#include<string>
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

void postFixEv(int *elements,string postStr, int &top,int i)
{
    string operatr("+-*/");
    int foundInPo,operand2,operand1,finalAn;
    if(i == postStr.length())
    {

    }
    else
    {

        foundInPo= operatr.find(postStr[i]);
        if(foundInPo==-1)
        {
            // push(s1, int(postStr[i])-48);
            elements[++top] = int(postStr[i])-48;
            
        }
        else
        {
            operand2 = elements[top--];
            operand1 = elements[top--];
            finalAn = evalu(operand1, operand2, postStr[i]);
            elements[++top] = finalAn;
        }
        postFixEv(elements, postStr, top, i+1);
        
    }
    
}
int main()
{
    string postStr,infixStr,operatr("+-*/");
    int elements[100], top =-1,foundInPo,operand2,operand1,finalAn, i=0;
    getline(cin, postStr);
    postFixEv(elements, postStr, top,i);
    cout<<elements[top];

}