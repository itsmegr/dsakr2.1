#include <iostream>
using namespace std;
typedef struct node *lptr;

struct node
{
     int data;
     lptr next;
};
void addFront(lptr &P, int x)
{
    lptr T;
    T = new(node);
    T->data = x, T->next = NULL;
    T->next = P;
    P = T;
}
void addEnd(lptr P, int n)
{
    lptr T;
    T = new(node);
    T->data = n, T->next = NULL;
    while(P->next!=NULL)
    P = P->next;

    P->next =T;
}
void addAfter(lptr P, int x, int y)
{

    if(P!=NULL)
    {
        if(P->data==y)
        {
            lptr T;
            T = new(node);
            T->data = x, T->next = NULL;
            T->next = P->next;
            P->next = T;
        }
        else 
        {
            P =P->next;
            addAfter(P,x,y);
        }
    }
}
void print_list(lptr P)
{
    if(P!=NULL)
    {
        int x = P->data;
        cout<<x<<" ";
        P = P->next;
        print_list(P);
    }
    
}
void merge(lptr P1, lptr P2)
{
    lptr T, S =P1;
    while(P1!= NULL)
    {
        T = P1->next;
        addAfter(P1,P2->data,P1->data);
        P1 = T;
        P2 = P2->next;
    }
   int x;
    while(P2!=NULL)
    {
        x = P2->data;
        addEnd(S, x);
        P2 = P2->next;
    }
}
int main()
{
    int n,x,k,y;
    lptr L1,L2,SP,FP;
    L1= new(node);
    cin>>n;
    L1->data = n, L1->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L1,n);
        cin>>n;
    }
    L2= new(node);
    cin>>n;
    L2->data = n, L2->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L2,n);
        cin>>n;
    }
    merge(L1,L2);
    print_list(L1);
}