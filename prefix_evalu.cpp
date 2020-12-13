#include <iostream>
#include <iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    string elements[50];
};
void enqueue(struct queue &Q, string x)
{
    if(((Q.rear+1)%Q.size)==Q.rear)
    {
        cout<<"queue is full"<<endl;
    }
    else
    {
        if(Q.front==-1)
        {
            Q.rear = 0, Q.front=0;
        }
        else
        {
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear]=x;
        
    }
    
}

string dequeue(struct queue &Q)
{
    string t;
    if(Q.front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return "-1";
    }
    else
    {
        if(Q.front==Q.rear)
        {
            t = Q.elements[Q.front];
            Q.front=-1, Q.rear=-1;
        }
        else
        {
            t = Q.elements[Q.front];
            Q.front = (Q.front+1)%Q.size;
        }
        return t;
    }
    
}
int evalu(int operand1, int operand2, string opertr)
{
    if(opertr == "+")
    {
        return operand1+operand2;
    }
    else if(opertr == "-")
    {
        return operand1-operand2;
    }
    else if(opertr == "*")
    {
        return operand1*operand2;
    }
    else if(opertr == "/")
    {
        return operand1/operand2;
    }
    else
    {
        return 0;
    }
    
}
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 
void prefixEva(struct queue &Q,string prefix)
{
    string oprtr("+-*/");
    string a =dequeue(Q),b = dequeue(Q),c = dequeue(Q);
    int afind,bfind,cfind,evl;
    while(Q.front!=Q.rear)
    {
        afind = oprtr.find(a), bfind = oprtr.find(b),cfind = oprtr.find(c);
       
        if(afind>-1 && bfind==-1 && cfind==-1)
        {
            evl = evalu(stoi(b), stoi(c), a);
            enqueue(Q, to_string(evl));
            a =dequeue(Q),b = dequeue(Q),c = dequeue(Q);
            if(Q.front==-1)
            {
                break;
            }
        }
        else
        {
            enqueue(Q, a);
            a=b;
            b=c;
            c=dequeue(Q);
        }
        
    }
   
    while(true)
    {
        afind = oprtr.find(a), bfind = oprtr.find(b),cfind = oprtr.find(c);
        if(afind>-1 && bfind==-1 && cfind==-1)
        {
            evl = evalu(stoi(b), stoi(c), a);
            cout<<evl<<endl;
            break;
        }
        else
        {
            string tem;
            tem = a;
            a=b;
            b=c; 
            c=tem;
        }
    }


}
int main()
{
    struct queue Q;
    Q.size = 30;
    Q.rear = -1;
    Q.front = -1;
    string prefix;
    getline(cin, prefix);
    for(int i=0;i<prefix.length();i++)
    {
        enqueue(Q, getString(prefix[i]));
    }
    prefixEva(Q, prefix);
   
}