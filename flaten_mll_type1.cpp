#include <bits/stdc++.h>
using namespace std;
typedef struct node *lptr; 
typedef struct mlnode *mlptr;

//I am using linked list only for construction of MLL, not for sorting
struct node
{
     int data;
     lptr next;
};
struct mlnode
{
    int mldata;
    struct node * dlink;
    struct mlnode *mlnext;
};
void addEndSingLL(lptr &L, int n)
{
    lptr P = L, T;
    T = new(node);
    T->data = n, T->next = NULL;

    if(L==NULL)
    L = T;
    else
    {
            while(P->next!=NULL)
            P = P->next;
            P->next =T;
    }
    
}
lptr construct_singll()
{
    lptr L = NULL;
    // L = new(node);
    int n;
    // cin>>n;
    // L->data =n, L->next = NULL;
    cin>>n;
    while(n!=-1)
    {
        addEndSingLL(L,n);
        cin>>n;
    }
    return L;
}
void linkSinllToMl(mlptr ML, lptr P)
{
    while(ML->mlnext!=NULL)
    ML = ML->mlnext;

    ML->dlink = P;
}
void addEndMultiLL(mlptr ML, int n)
{
    mlptr TML;
    TML = new(mlnode);
    TML->mldata = n, TML->dlink = NULL, TML->mlnext = NULL;
    while (ML->mlnext!=NULL)
    ML = ML->mlnext;
    ML->mlnext = TML;
}
mlptr construct_multi_level_ll()
{
    mlptr ML;
    lptr BranchL;
    ML = new(mlnode);
    int n;
    cin>>n;
    ML ->mldata = n;ML->dlink=NULL;ML->mlnext = NULL;
    cin>>n;
    while(n!=-2)
    {
        if(n==1)
        {
           BranchL = construct_singll();
           linkSinllToMl(ML, BranchL);
        }
        else if(n==0)
        {

        }
        else
        {
            addEndMultiLL(ML, n);
        }
        cin>>n;
    }
    return ML;
}
void print_single_llist(lptr P, lptr L)
{
   
    if(P!=NULL)
    {
        addEndSingLL(L, P->data);
        int x = P->data;
        P = P->next;
        print_single_llist(P, L);
    }
    
}
void printMlList(mlptr ML, lptr &L)
{
    if(ML!=NULL)
    {
        addEndSingLL(L, ML->mldata);
        if(ML->dlink!=NULL)
        {
            print_single_llist(ML->dlink, L);
        }
        ML = ML->mlnext;
        printMlList(ML, L);
    }
}
int main()
{
    mlptr ML;
    ML = construct_multi_level_ll();
    lptr singLL = NULL;
    printMlList(ML, singLL);
    lptr P = singLL;
    while(P!=NULL)
    {
        cout<<P->data<<" ";
        P = P->next;
    }
}
