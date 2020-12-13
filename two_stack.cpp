#include <iostream>
using namespace std;
#include<string>

struct stack
{
    int sizeA = 100;
    int sizeB= 100;
    int topA;
    int topB;
    int elements[200];

};
void pushA (struct stack *s, int x)
    {
        if(s->topA == s->sizeA -1)
        cout<<"stack is full";
        else
        {
            s->elements[++s->topA] = x;
        }
        
    }
void pushB (struct stack *s, int x)
{
    if(s->topB == 199-(s->sizeB))
    cout<<"stack is full";
    else
    {
        s->elements[--s->topB] = x;
    }
    
}


int popA(struct stack *s)
{
    if(s->topA==-1)
    {
        return -1;
    }
    else
    {
       
        return  s->elements[s->topA--];
    }
    
}
int popB(struct stack *s)
{
    if(s->topB==200)
    {
        return -1;
    }
    else
    {
       
        return  s->elements[s->topB++];
    }
    
}


int main ()
{
    struct stack *s1;
    s1 = new(stack);
    s1->topA = -1;
    s1->topB = 200;
    int stackNo, number;
   
    
    while(true)
    {
        cout<<"want to add number in which stack 1 for stack1 and 2 for stack2 and any other key to not add"<<endl;
        cin>>stackNo;
        if( stackNo==1)
        {
              cout<<"enter the number"<<endl;
              cin>>number;
              pushA(s1, number);

        }
          
        else if(stackNo ==2)
        {
            cout<<"enter the number"<<endl;
            cin>>number;
            pushB(s1, number);

        }
            
        else 
           break;
    }
      
    while(true)
    {
        cout<<"want to pop elemen in which stack 1 for stack1 and 2 for stack2 and any other number to not pop up"<<endl;
        cin>>stackNo;
        if( stackNo==1)
           cout<<popA(s1)<<endl;
        else if(stackNo ==2)
           cout<<popB(s1)<<endl;
        else 
           break;
    }
    return 0;
    
}