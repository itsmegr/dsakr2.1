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
void reverse(lptr &P)
{
    lptr Q = P->next,R;
    P->next =NULL;
    while(Q!=NULL)
    {
        R =Q->next;
        Q->next = P;
        P =Q,Q=R;
    }
}

void sum(lptr P1, lptr P2, int extra, lptr L1, lptr L2)
{
    int res;
    if(P1!=NULL&&P2!=NULL)
    {
        res = P1->data+P2->data+extra;
        if(res>=10)
        {
            sum(P1->next,P2->next, 1,L1,L2);
            cout<<res%10;
        }
        else
        {
            sum(P1->next,P2->next, 0, L1, L2);
            cout<<res%10;
        }
        
    }
    else
    {
        if(P1==NULL&&P2!=NULL) cout<<P2->data+extra;
        else if(P2==NULL&&P1!=NULL) cout<<P1->data+extra;
        else cout<<extra;
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
    reverse(L1);
    reverse(L2);
    sum(L1,L2,0,L1,L2);
}