#include<bits/stdc++.h>
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
int node_count(lptr P)
{
    if(P==NULL)
    return 0;
    else if(P->next!=NULL)
    {
        P = P->next;
        return 1+node_count(P);
    }
    else return 1;
}
int getKth(lptr P, int k, int n)
{
    int i=1;
    if(k<=0&&k>n)
    return -1;
    else
    {
        while(P!=NULL)
        {
            if (i==k) return P->data;
            else
            {
                P=P->next;
                i++;
            }
        }
        return -1;
    }
}
void del_kth_ele(lptr &P,lptr L, int k)
{
    if(k==1)
    {
        P = P->next;
    }
    else if(L->next!=NULL)
    {
        int i=2;
        while(L->next!=NULL)
        {
            if(i==k)
            {
                L->next = L->next->next;
            }
            else
            {
                L = L->next;
            }
            i++;
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
void dequeue(lptr &L)
{
    int n = node_count(L);
    if(n==0)
    cout<<"queue is empty"<<endl;
    else
    {
        cout<<getKth(L,1,n)<<endl;
        del_kth_ele(L,L,1);
    }
    

    
}
void enqueue(lptr L, int x)
{
    int n = node_count(L);
    addEnd(L, x);

}
int main()
{
    lptr L,P;
    L = new(node);
    int n,x, max=-9999,min = 9999,k,y;
    L->data = 1, L->next = NULL;
    enqueue(L,2);
    enqueue(L,3);
    enqueue(L,4);
    enqueue(L,5);
    dequeue(L);dequeue(L);dequeue(L);dequeue(L);dequeue(L);
}
