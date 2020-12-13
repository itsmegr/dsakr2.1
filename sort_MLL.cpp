#include <bits/stdc++.h>
using namespace std;
typedef struct node *lptr; 
typedef struct mlnode *mlptr;

//I am using linked list only for construction of MLL, not for sorting MLL;
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
void printMlList(mlptr ML, int &min, int &tag, mlptr &minPtrML, lptr &minPtrLL)
{
    if(ML!=NULL)
    {
        if (ML->mldata!=-1)
        {
            if(ML->mldata<min)
            {
                min = ML->mldata;
                tag = 1;
                minPtrML = ML;
            }
        }
        if(ML->dlink!=NULL)
        {
            lptr P =ML->dlink;
            while(P!=NULL)
            {
                if(P->data!=-1)
                {
                    if(P->data<min)
                    {
                        min = P->data;
                        tag = 2;
                        minPtrLL = P;
                    }
                }
                P = P->next;
            }
        }
        ML = ML->mlnext;
        printMlList(ML, min, tag , minPtrML, minPtrLL);
    }
}
int main()
{
    mlptr ML, minPtrML = NULL;
    lptr minPtrLL = NULL;
    int min = 9999, tag,i=1;
    ML = construct_multi_level_ll();
    while(i<=10)
    {
        min = 9999;
        printMlList(ML, min, tag, minPtrML, minPtrLL);
        if(tag == 1) 
        {
            cout<<min<<" ";
            minPtrML->mldata =-1;
        }
        else 
        {
            cout<<min<<" ";
            minPtrLL->data = -1;
        }
        i++;
    }

}
