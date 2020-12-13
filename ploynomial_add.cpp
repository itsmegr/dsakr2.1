#include <iostream>
using namespace std;
typedef struct node *lptr;
struct pol{
    int a;
    int b;
};
struct node
{
     struct pol data;
     lptr next;
};
void addEnd(lptr P, int x, int y)
{
    lptr T;
    T = new(node);
    T->data.a = x,T->data.b = y, T->next = NULL;
    while(P->next!=NULL)
    P = P->next;

    P->next =T;
}

void print_list(lptr P)
{
    if(P!=NULL)
    {
        int x = P->data.a,y = P->data.b;
        cout<<x<<" "<<y<<" ";
        P = P->next;
        print_list(P);
    }
    
}
void min_ele(lptr P, int &min)
{
    if(P!=NULL)
    {
        min = P->data.b<min?P->data.b:min;
        min_ele(P->next, min);
    }

}
int find(lptr P, int x)
{
    if(P!=NULL)
    {
        if(x==P->data.b)
        return 1;
        else
        {
            P = P->next;
           return find(P,x);
        }

    }
    else return 0;
}
void Add_same(lptr P, int x, int y)
{
    if(P!=NULL)
    {
        if(y==P->data.b)
        {
            P->data.a = P->data.a+x;
            return;
        }
        else
        {
            P = P->next;
            Add_same(P,x,y);
        }

    }
}
void addBefore(lptr P,int y, int p, int q)
{

    if(P!=NULL)
    {
        if(P->next->data.b==y)
        {
            lptr T;
            T = new(node);
            T->data.a = p,T->data.b = q, T->next = NULL;
            T->next = P->next;
            P->next = T;
        }
        else 
        {
            P =P->next;
            addBefore(P,y,p,q);
        }
    }
}
void Pol_addi(lptr P1, lptr P2)
{
    lptr L = P1;
    int min = 9999;
    min_ele(P1, min);
    while(P2!=NULL)
    {
        if(find(P1,P2->data.b)==1)
        {
            Add_same(P1, P2->data.a, P2->data.b);
        }
        else if(P2->data.b<min)
        {
            addEnd(P1, P2->data.a,P2->data.b);
        }
        else if(find(P1,P2->data.b)==0)
        {
            while(L->next->next!=NULL)
            {
                if(P2->data.b<L->data.b&&P2->data.b>L->next->data.b)
                {
                    addBefore(P1, L->next->data.b, P2->data.a,P2->data.b);
                    break;
                }
                L=L->next;
            }
        }
        P2 = P2->next;
    }
}
int main()
{
    lptr P1,P2;
    P1 = new(node);
    P2 = new(node);
    int x, max=-9999,min = 9999,k,y;
    cin>>x>>y;
    P1->data.a = x,P1->data.b = y, P1->next = NULL;
    cin>>x>>y;
    while(x>=0&&y>=0)
    {
        addEnd(P1,x,y);
        cin>>x;
        if (x<0) break;
        cin>>y;
    }
    cin>>x>>y;
    P2->data.a = x,P2->data.b = y, P2->next = NULL;
    cin>>x>>y;
    while(x>=0&&y>=0)
    {
        addEnd(P2,x,y);
        cin>>x;
        if (x<0) break;
        cin>>y;
    }
    Pol_addi(P1,P2);
    print_list(P1);

}