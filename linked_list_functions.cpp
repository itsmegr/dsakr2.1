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
void insert(lptr P, int x, int y)
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
            insert(P,x,y);
        }
    }
}
void del_front(lptr &P)
{
    P = P->next;
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
    int n,x, max=-9999,min = 9999,k;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>=0)

    lptr L;
    L = new(node);
    int n,x;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>0)

    {
        addEnd(L,n);
        cin>>n;
    }
  
    print_list(L);
    cout<<endl;


    rev_print(L);
    cout<<endl;

    cout<<node_count(L)<<endl;

    min_ele(L, min);
    cout<<min<<endl;

    max_ele(L,max);
    cout<<max<<endl;


    if(middle(L,SP,FP)==0)
    cout<<SP->data<<" "<<SP->next->data<<endl;
    else cout<<SP->data<<endl;

    cout<<odd_node_num(L)<<endl;

    cout<<even_node_num(L)<<endl;

    cin>>k;
    cout<<find(L, k);
    





    cin>>x;
    insert(L, x, 5);
    print_list(L);

}