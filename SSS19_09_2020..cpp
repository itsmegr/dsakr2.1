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
void sorted_union(lptr L1, lptr L2)
{
    lptr P, T,L3;
    L3 = new(node);
    L3->data = L1->data, L3->next = NULL;
    P=L1->next;
    while(P!=NULL)
    {
        addEnd(L3, P->data);
        P = P->next;
    }
    P = L2;
    int max=-9999,min = 9999, element;
    min_ele(L3,min);
    max_ele(L3,max);

    while(P!=NULL)
    {
        if(find(L3, P->data)==0)
        {
          element = P->data;
          if(element<min) addFront(L3, element);
          else if(element>max) addEnd(L3, element);
          else
          {
              T = L3;
              while(T!=NULL)
              {
                  if(element<T->data)
                  {
                      addBefore(L3, element, T->data);
                      break;
                  }
                  else T = T->next;
              }
          }   
           
        }
        P = P->next;
    }
    print_list(L3);
    cout<<endl;
}

void sorted_inter(lptr L1, lptr L2)
{
    lptr P, T,L3;
    L3 = new(node);
    L3->data = L1->data, L3->next = NULL;
    P=L1->next;
    while(P!=NULL)
    {
        addEnd(L3, P->data);
        P = P->next;
    }
    P = L3;
    int element;
    while(P!=NULL)
    {
        if(find(L2, P->data)==0)
        {
            element = P->data;
            P = P->next;
            del_k(L3, L3, element);
        }
        else  P = P->next;
        
    }
    print_list(L3);
    cout<<endl;
}
void sorted_diff(lptr L1, lptr L2)
{
    lptr P, T,L3;
    L3 = new(node);
    L3->data = L1->data, L3->next = NULL;
    P=L1->next;
    while(P!=NULL)
    {
        addEnd(L3, P->data);
        P = P->next;
    }
     P = L2, T;
    int element;
    while(P!=NULL)
    {
        if(find(L3, P->data)==1)
        {
            element = P->data;
            P = P->next;
            del_k(L3, L3, element);
        }
        else  P = P->next;
        
    }
    print_list(L3);
    cout<<endl;
}
void union_n(lptr L1, lptr L2)
{
    lptr P, T,L3;
    L3 = new(node);
    L3->data = L1->data, L3->next = NULL;
    P=L1->next;
    while(P!=NULL)
    {
        addEnd(L3, P->data);
        P = P->next;
    }
    P = L2;
    int max=-9999,min = 9999, element;
    min_ele(L3,min);
    max_ele(L3,max);

    while(P!=NULL)
    {
        if(find(L3, P->data)==0)
        {
          element = P->data;
          addEnd(L3, element);  
        }
        P = P->next;
    }
    print_list(L3);
    cout<<endl;

}
int main()
{
    lptr L1,L2, L3,P;
    L1 = new(node);
    L2 = new(node);
    L3 = new(node);
    int n,x, max=-9999,min = 9999,k,y;
    cin>>n;
    L1->data = n, L1->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L1,n);
        cin>>n;
    }

    cin>>n;
    L2->data = n, L2->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L2,n);
        cin>>n;
    }
    sorted_union(L1, L2);
    sorted_inter(L1, L2);
    sorted_diff(L1, L2);


    cin>>n;
    L1->data = n, L1->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L1,n);
        cin>>n;
    } 
    cin>>n;
    L2->data = n, L2->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L2,n);
        cin>>n;
    }
    union_n(L1,L2);
    sorted_inter(L1, L2);
    sorted_diff(L1, L2);
    
}