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

int find(lptr P, int x)
{
    if(P!=NULL)
    {
        if(x==P->data)
        return 1;
        else
        {
            P = P->next;
           return find(P,x);
        }

    }
    else return 0;
}
void del_k(lptr &P,lptr L, int k)
{
    // lptr L = P;
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
    n = node_count(L);
    P =L; x = 0;
    while(P!=NULL)
    {
        if(P->data<=n)
        {
            if(getKth(L,P->data,n)<=n)
            {
                replaceData(L,getKth(L,P->data,n), -1);
            }
            replaceData(L,P->data, -1);
        }
        P = P->next;
    }
    while(find(L,-1)!=0)
    {
        del_k(L,L,-1);
    }
    print_list(L);
    //this is okk
}