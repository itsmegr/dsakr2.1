#include <iostream>
using namespace std;
typedef struct node *lptr;

struct node
{
     int data;
     lptr next;
};
void create(lptr &L)
{
    lptr P,T;
    int n;
    cin>>n;
    while(n>0)
    {
        P = L;
        T = new(node);
        T->data = n;
        T->next = NULL;
        if(L==NULL)
        L = T;
        else
        {
            while(P->next!=NULL)
            P = P->next;
            P->next =T;
        }
        cin>>n;  
    }
}
void addEnd(lptr &L, int n)
{
    lptr T, P=L;
    T = new(node);
    T->data = n;
    T->next = NULL;
    if(L==NULL)
    L = T;
    else
    {
        while(P->next!=NULL)
        P = P->next;
        P->next =T;
    }
    
}
void merge(lptr p1, lptr p2, lptr &L)
{
    if(p1!=NULL&&p2!=NULL)
    {
        while(p1->data<p2->data)
        {
            addEnd(L, p1->data);
            p1 = p1->next;
            if(p1==NULL) break;
        }
        if(p1==NULL) {
            merge(p1, p2, L);
            return;
        }
        while(p2->data<p1->data)
        {
            addEnd(L, p2->data);
            p2 = p2->next;
            if(p2==NULL) break;
        }
        merge(p1, p2, L);
    }
    else if(p1==NULL)
    {
        while(p2!=NULL)
        {
            addEnd(L, p2->data);
            p2 = p2->next;
        }
    }
    else if(p2==NULL)
    {
        while(p1!=NULL)
        {
            addEnd(L, p1->data);
            p1 = p1->next; 
        }
    }
}
int main()
{
    lptr L1 =NULL,L2=NULL, P;
    create(L1);

    create(L2);
    lptr L3 = NULL, p1, p2;
    if(L1->data<L2->data) 
    {
        p1=L1, p2 =L2;
    }
    
    else
    {
        p1 = L2, p2  = L1;
    }
    merge(p1, p2, L3);
    P = L3;

    while(P!=NULL)
    {
        cout<<P->data<<" ";
        P = P->next;
    }
}