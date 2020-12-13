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
int checkAfter(lptr T1, lptr T2)
{
        while(T2!=NULL)
        {
            if(T1->data==T2->data)
            {
                T1 = T1->next;
                T2 = T2 ->next;
            }
            else return 0;
        }
        return 1;
}

int find(lptr P,lptr P1)
{
    int retV;
    if(P!=NULL)
    {
        if(P1->data==P->data)
        {
            retV = checkAfter(P->next,P1->next);
            if(retV == 0) return find(P->next, P1);
            else return 1;
        }
        else
        {
           return find(P->next, P1);
        }

    }
    else return 0;
}

int main()
{
    int n,x,k,y;
    lptr L1,L2,SP,FP;
    L1= new(node);
    cin>>n;
    L1->data = n, L1->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L1,n);
        cin>>n;
    }
    L2= new(node);
    cin>>n;
    L2->data = n, L2->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L2,n);
        cin>>n;
    }
    cout<<find(L1, L2);


}