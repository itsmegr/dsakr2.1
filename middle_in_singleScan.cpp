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



int middle(lptr P, lptr SP, lptr FP)

{
    if(FP->next!=NULL)
    {
        FP = FP->next;
        if(FP->next!=NULL)

        {
          FP = FP->next;
          SP = SP->next;
          return middle(P, SP,FP);
        }
        else return 0;
    }
    else return 1;
}

// int main()
// {
//     lptr L;
//     L = new(node);
//     int n,x;

//     cin>>n;
//     L->data = n, L->next = NULL;
//     cin>>n;
//     while(n>0)
//     {
//         addEnd(L,n);
//         cin>>n;
//     }

//     if(middle(L,SP,FP)==0)
//     cout<<SP->data<<" "<<SP->next->data;
//     else cout<<SP->data;

//     cout<<middle(L,L,L);

// }