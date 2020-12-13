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
int odd_node_num(lptr P)
{
    if(P!=NULL)
    {
        int x = P->data;
        P = P->next;
        if(x%2==1)
        return 1+ odd_node_num(P);
        else
        return odd_node_num(P);
    }
    else return 0;
    
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
void segra(lptr &L)
{
    lptr P = L,T;
    int oddEls,i;
    oddEls = odd_node_num(L);
    i=1;
    while(i<=oddEls)
    {
      if(P->data%2==1)
      {
          T = P->next;
          del_k(L,L,P->data);
          addEnd(L,P->data);
          i++;
          P = T;
      }
      else P= P->next;
    }
}
int main()
{
    lptr L,SP,FP;
    L = new(node);
    SP =L, FP =L;
    int n,x, max=-9999,min = 9999,k;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L,n);
        cin>>n;
    }
    segra(L);
    print_list(L);

}