#include <iostream>
using namespace std;
typedef struct node *lptr;

struct node
{
     int data;
     lptr next;
};
void insertL1(lptr &P, int n)
{
    if(P==NULL)
    {
        P=new(node);
        P->data = n, P->next = NULL;
    }
    else
    {
        lptr T, L=P;
        T = new(node);
        T->data = n, T->next = NULL;
        while(L->next!=NULL)
        L=L->next;

        L->next =T;
    }
}
lptr find(lptr P, int x)
{
    if(P!=NULL)
    {
        if(x==P->data)
        return P;
        else
        {
            P = P->next;
           return find(P,x);
        }

    }
    else return NULL;
}
void insert(lptr &P, int n, lptr L1)
{
    if(P==NULL)
    {
        P=new(node);
        P->data = n, P->next = NULL;
    }
    else
    {
        if(find(L1, n)==NULL)
        {
            lptr T, L=P;
            T = new(node);
            T->data = n, T->next = NULL;
            while(L->next!=NULL)
            L=L->next;

            L->next =T;

        }
        else
        {
            lptr L=P;
            while(L->next!=NULL)
            L=L->next;
            L->next=find(L1, n);
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
    lptr L1=NULL, L2=NULL, L3=NULL, L4=NULL;
    int n; cin>>n;
    while(n>0)
    {
        insertL1(L1, n);
        cin>>n;
    }
    cin>>n;
    while(n>0)
    {
        insert(L2, n, L1);
        cin>>n;
    }
        cin>>n;
    while(n>0)
    {
        insert(L3, n, L1);
        cin>>n;
    }
        cin>>n;
    while(n>0)
    {
        insert(L4, n, L1);
        cin>>n;
    }
    lptr T=L2;
    while(true)
    {
        if(find(L1, T->data)!=NULL)
        break;
        T=T->next;
    }
    cout<<"2 1 3 4 "<<T->data<<endl;
         T=L4;
    while(true)
    {
        if(find(L1, T->data)!=NULL)
        break;
        T=T->next;
    }
    cout<<"4 1 3 "<<T->data<<endl;
         T=L3;
    while(true)
    {
        if(find(L1, T->data)!=NULL)
        break;
        T=T->next;
    }
    cout<<"3 1 "<<T->data<<endl;
}