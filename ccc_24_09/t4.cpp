#include <bits/stdc++.h>
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
lptr getKth_add(lptr P, int k, int n)
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

int partition(lptr L,  int l, int h)
{
    int n = node_count(L),a,b;
    int pi = getKth(L, l, n), i = l+1, j=h;
    while(i<j)
    {
        
        if(getKth(L, i, n)>pi)
        {
            if(getKth(L, j, n)<pi)
            {
               
                a = getKth_add(L, i, n)->data;
                getKth_add(L, i, n)->data = getKth_add(L, j, n)->data;
                getKth_add(L, j, n)->data=a;
   

                i++, j--;
            }
            else
            {
                j--;
            }
            
        }
        else
        {
            i++;
        }
        
    }
    if(getKth(L, j, n)>pi)
    {
        i--;
        swap(getKth_add(L, l, n)->data, getKth_add(L, i, n)->data);

    }
    else
    {
        swap(getKth_add(L, l, n)->data, getKth_add(L, i, n)->data);
    }
    return i;
}
void quick_sort(lptr P, int lower, int higher)
{
    int i;
    if(lower<higher)
    {
        i=partition(P, lower, higher);
        quick_sort(P, lower, i-1);
        quick_sort(P, i+1, higher);
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
    n = node_count(L1);
    quick_sort(L1, 1, n);
    print_list(L1);
}