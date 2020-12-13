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
void del_kth_ele(lptr &P,lptr L, int k)
{
    if(k==1)
    {
        P = P->next;
    }
    else if(L->next!=NULL)
    {
        int i=2;
        while(L->next!=NULL)
        {
            if(i==k)
            {
                L->next = L->next->next;
            }
            else
            {
                L = L->next;
            }
            i++;
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
int main()
{
    lptr L,P,T1,T2;
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
    n = node_count(L);
    P =L;
    int i = 1;
    while(i<=n/2)
    {
        T2 = getKth(L ,n,n);
        del_kth_ele(L, L,n);
        T1 = P->next;
        P->next = T2;
        P = P->next;
        P->next = T1;
        P = P->next;
        i++;
    }
    print_list(L);
}
