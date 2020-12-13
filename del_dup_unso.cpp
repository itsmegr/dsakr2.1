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
void del_k(lptr &P,lptr L, int k)
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
            del_k(P, L, k);
        }
   }
    
}
void find(lptr P, int x, int &last_ind)
{
    int i = 1;
    while(P!=NULL)
    {
        if(x==P->data)
        {
            last_ind = i;
            P =P->next;
        }
        else P =P->next;
        i++;
        
    }
}
void del_dup(lptr &P, lptr L)
{
    int i=1,last_ind;
    while(L!=NULL)
    {
        last_ind =i;
        find (P,L->data, last_ind);
        if(last_ind!=i)
        {
            del_kth_ele(P, P, last_ind);
        }
        else
        {
            i++;
            L = L->next;
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