#include <iostream>
using namespace std;
typedef struct node *lptr;

struct node
{
     int data;
     lptr next;
};
int node_count(lptr P)
{
    if(P->next!=NULL)
    {
        P = P->next;
        return 1+node_count(P);
    }
    else return 1;
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
void palindrome(lptr P, int n)
{
    int i=1;
    while(i<=(n+1)/2)
    {
        if(getKth(P,i,n)!=getKth(P,n-i+1,n))
        {
            cout<<"This is not palindrome"<<endl;
            return ;
        }
        i++;
    }
    cout<<"This is palindrome"<<endl;
}
int main()
{
    lptr L,P;
    L = new(node);
    int n,x, max=-9999,min = 9999,k,y;
    cin>>n;
    L->data = n, L->next = NULL;
    cin>>n;
    while(n>=0)
    {
        addEnd(L,n);
        cin>>n;
    }
    n = node_count(L);
    palindrome(L,n);
}