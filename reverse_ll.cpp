#include <iostream>
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
    lptr L;
    L = new(node);
    int n;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L,n);
        cin>>n;
    }
    reverse(L);
    print_list(L);
}