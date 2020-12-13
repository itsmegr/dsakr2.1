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
void addBefore( lptr &L, lptr P, int x, int y)
{
    if(L->data ==y )
    {
        lptr T;
        T = new(node);
        T->data = x, T->next = NULL;
        T->next = L;
        L = T;
    }
    else if(P!=NULL)
    {
        if(P->next->data==y)
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
            addBefore(L,P,x,y);
        }
    }
}
int just_grater(lptr P, int x)
{
    while(P!=NULL)
    {
        if(P->data>x) return P->data;
        else if(P->data==x) return -1;
        P = P->next;
    }
    return -1;
}
void insertionSort(lptr &L)
{
    lptr P =L->next,T;
    int k,q;
    while(P!=NULL)
    {
        k = P->data;
        q =just_grater(L,P->data);
        if(q!=-1)
        {
            T = P->next;
            del_k(L,L,k);
            addBefore(L,L,k,q);
            P =T;
        }
        else P = P->next;
    }

}
int main()
{
    lptr L,SP,FP;
    L = new(node);
    SP =L, FP =L;
    int n,x, max=-9999,min = 9999,k,y;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L,n);
        cin>>n;
    }
    insertionSort(L);
    print_list(L);

}