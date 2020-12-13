#include <iostream>
using namespace std;
typedef struct node *lptr;

struct node
{
     int data;
     lptr next;
};
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
int getKth(lptr P, int k, int n)
{
    int i=1;
    if(k<=0&&k>n)
    return -1;
    else
    {
        while(P!=NULL)
        {
            if (i==k) return P->data;
            else
            {
                P=P->next;
                i++;
            }
        }
        return -1;
    }
}
void replaceData(lptr P, int k, int x)
{
    int i=1;
    while(P!=NULL)
    {
        if(i==k)
        {
            P->data = x;
            break;
        }
        else 
        {
            i++;
            P =P->next;
        }
    }
    
}
void swap(lptr P, int k)
{
    int  n = node_count(P),kthStart, kthEnd;
    kthStart = getKth(P,k,n), kthEnd = getKth(P, n-k+1,n);
    replaceData(P,k,kthEnd);
    replaceData(P,n-k+1,kthStart);
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
    cin>>k;
    swap(L,k);
    print_list(L);
   
}