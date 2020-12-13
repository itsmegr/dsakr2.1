#include <iostream>
using namespace std;
typedef struct node *lptr;
typedef struct SLnode *slptr;

struct node
{
     int data;
     lptr next;
};
struct SLnode
{
    lptr ptr1;
    lptr ptr2;
    struct SLnode *next;
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
void createSL(slptr &SL, lptr p1, lptr p2)
{
    slptr T, P=SL;
    T = new(SLnode);
    T->ptr1 = p1;
    T->ptr2 = p2;
    T->next = NULL;
    if(SL==NULL)
    {
        SL = T;
    }
    else
    {
        while(P->next!=NULL) P= P->next;
        P->next = T;
    }
    
}
void merge(slptr &SL, lptr p1, lptr p2)
{
    lptr tempptr, p1back = p1, p2back=p2;
    createSL(SL, p1, p2);
    while(p2!=NULL&&p1!=NULL)
    {
        p1 = p1->next;
        if(p1==NULL) break;
        while(p1->data<p2->data)
        {
            p1=p1->next;
            p1back = p1back->next;
            if(p1==NULL) break;
        }
        if(p1==NULL) break;
        p1back->next=NULL;
        p1back = p1;
        p2 = p2->next;
        if(p2==NULL) break;
        while(p2->data<p1->data)
        {
            p2 = p2->next;
            p2back = p2back->next;
            if(p2==NULL) break;
        }
         if(p2==NULL) break;
        p2back->next=NULL;
        p2back=p2;
        createSL(SL, p1, p2);
        
    }
    if(p2==NULL) 
    createSL(SL, p1, p2);

    
    

}
int main()
{
    lptr L1=NULL, L2 = NULL, P;
    create(L1);
    create(L2);
    slptr SL = NULL, Temp;
    merge(SL,L1, L2);
    Temp = SL;
    while(Temp!=NULL)
    {
        P = Temp->ptr1;
        while(P!=NULL) 
        {
            cout<<P->data<<" ";
            P = P->next;
        }
        P = Temp->ptr2;
        while(P!=NULL)
        {
            cout<<P->data<<" ";
            P = P->next;
        }
        Temp = Temp->next;
    }

}