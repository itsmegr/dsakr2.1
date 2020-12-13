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
int node_count(lptr P)
{
    if(P->next!=NULL)
    {
        P = P->next;
        return 1+node_count(P);
    }
    else return 1;
}
lptr getKth(lptr P, int k, int n)
{

    while(P!=NULL)
    {
        if (P->data==k) return P;
        else
        {
            P=P->next;
        }
    }
    return P;
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

int main()
{
    int n,x,k,y;
    lptr L1,L2,P,FP,T;
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
    n = node_count(L1);
    T = getKth(L1, 6, n);
    P = L2;
    while(P!=NULL)
    {
        P =P->next;
    }
    P = T;
    cout<<T->data;
}