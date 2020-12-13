#include<bits/stdc++.h>
using namespace std;
typedef struct node *lptr;
struct node
{
     int data;
     lptr next;
};
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
    int i=1;

    while(P!=NULL)
    {
        if (i==k) return P;
        else
        {
            P=P->next;
            i++;
        }
    }
    return P;

}
int main()
{
    lptr L,P,FP,SP;
    L = new(node);
    int n,x, max=-9999,min = 9999,k,y;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L,n);
        cin>>n;
    }
    P =L;
    n = node_count(L);
    while(P->next!=NULL)
    {
        P = P->next;
    }
    P->next = getKth(L,5,n);
    FP = L;
    SP =L;

    while(SP!=NULL)
    {
        if (FP ==SP)
        {
            cout<<"1"<<" ";
            break;
        }
        FP = FP->next->next;
        SP = SP->next;
    }
    cout<<P->next->data<<" ";

}