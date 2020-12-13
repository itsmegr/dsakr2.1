#include <iostream>
using namespace std;
typedef struct node *lptr;


struct node
{
     int data;
     lptr next;
};
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
int node_count(lptr P)
{
    if(P->next!=NULL)
    {
        P = P->next;
        return 1+node_count(P);
    }
    else return 1;
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
void del_sth(lptr &P,lptr L, int k)
{

   if(k==P->data)
    {
        P = P->next;
    }
   else if(L->next!=NULL)
   {
        if(k==L->next->data)
        {
            L->next = L->next->next;
        }
        else 
        {
            L = L->next;
            del_sth(P, L, k);
        }
   }
    
}
void del_dup(lptr &P, lptr L)
{
    if(L->next!=NULL)
    {
        if(L->data==L->next->data)
        {
            del_sth(P,P, L->next->data);
            del_dup(P, L->next);
        }
        else 
        {
            L = L->next;
            del_dup(P, L);
        }
    }
}

int main()
{
    lptr L,P;
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
    del_dup(L,L);
    print_list(L);
}