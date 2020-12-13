#include <iostream>
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
void addBefore(lptr P, int x, int y)
{

    if(P!=NULL)
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
            addBefore(P,x,y);
        }
    }
}
void addAfter(lptr P, int x, int y)
{

    if(P!=NULL)
    {
        if(P->data==y)
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
            addAfter(P,x,y);
        }
    }
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
void rev_print(lptr P)
{
    if(P!=NULL)
    {
        int x = P->data;
        P = P->next;
        rev_print(P);
        cout<<x<<" ";
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
void max_ele(lptr P, int &max)
{
    if(P!=NULL)
    {
        max = P->data>max?P->data:max;
        max_ele(P->next, max);
    }
}
void min_ele(lptr P, int &min)
{
    if(P!=NULL)
    {
        min = P->data<min?P->data:min;
        min_ele(P->next, min);
    }

}
int middle(lptr P, lptr &SP, lptr &FP)
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
int even_node_num(lptr P)
{
    if(P!=NULL)
    {
        int x = P->data;
        P = P->next;
        if(x%2==0)
        return 1+ even_node_num(P);
        else
        return even_node_num(P);
    }
    else return 0;
    
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
  
    print_list(L);
    cout<<endl;

    cin>>k;
    addFront(L, k);
     print_list(L);
    cout<<endl;

    cin>>x>>y;
    addBefore(L, x,y);
    print_list(L);
    cout<<endl;

    cin>>x>>y;
    addAfter(L,x,y);
    print_list(L);
    cout<<endl;


    cin>>k;
    del_k(L,L,k);
      print_list(L);
    cout<<endl;

    min_ele(L,min);
    del_k(L,L,min);
        print_list(L);
    cout<<endl;

    max_ele(L,max);
    del_k(L,L,max);
        print_list(L);
    cout<<endl;




}