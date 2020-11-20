#include <iostream>
using namespace std;
typedef struct node *lptr;
typedef struct Nnode *nlptr;
typedef struct Cnode *clptr;

union gene{
    int i;
    char c;
};

struct node
{
     int tag;
     gene data;
     lptr next;
     
};
struct Nnode
{
    lptr Ndata;
    nlptr Nnext;
};
struct Cnode
{
    lptr Cdata;
    clptr Cnext;
};
void insert(lptr &P, gene n, int tagf)
{
    if(P==NULL)
    {
        P=new(node);
        P->data = n, P->next = NULL, P->tag=tagf;
    }
    else
    {
        lptr T, L=P;
        T = new(node);
        T->data = n, T->next = NULL, T->tag=tagf;
        while(L->next!=NULL)
        L=L->next;
        L->next =T;
    }
}
void Ninsert(nlptr &P, lptr n)
{
    if(P==NULL)
    {
        P=new(Nnode);
        P->Ndata = n, P->Nnext = NULL;
    }
    else
    {
        nlptr T, L=P;
        T = new(Nnode);
        T->Ndata = n, T->Nnext = NULL;
        while(L->Nnext!=NULL)
        L=L->Nnext;
        L->Nnext =T;
    }   
}
void Cinsert(clptr &P, lptr n)
{
    if(P==NULL)
    {
        P=new(Cnode);
        P->Cdata = n, P->Cnext = NULL;
    }
    else
    {
        clptr T, L=P;
        T = new(Cnode);
        T->Cdata = n, T->Cnext = NULL;
        while(L->Cnext!=NULL)
        L=L->Cnext;
        L->Cnext =T;
    }   
}
void linking(lptr L, clptr &C, nlptr &N)
{
    if(L!=NULL)
    {
        if(L->tag==1&&L!=NULL)
        {
            Ninsert(N, L);
            while(L->tag==1&&L!=NULL)
            L=L->next;
        }
        if(L->tag==0&&L!=NULL)
        {
            Cinsert(C, L);
            while(L->tag==0&&L!=NULL)
            L=L->next;
        }
        linking(L, C,N);
    }
}
void printingC(clptr C)
{
    if(C!=NULL)
    {
        lptr T=C->Cdata;
        while(T->tag==0)
        {
            cout<<T->data.c<<" ";
            T=T->next;
        }
        printingC(C->Cnext);
    }
}
void printingN(nlptr N)
{
    if(N!=NULL)
    {
        lptr T=N->Ndata;
        while(T->tag==1)
        {
            cout<<T->data.i<<" ";
            T=T->next;
        }
        printingN(N->Nnext);
    }
}
int main()
{
    lptr L=NULL;
    gene dat;
    int tag, in;
    char ch;
    cin>>tag;
    while(tag>=0)
    {
        if(tag==0)
        {
            cin>>ch;
            dat.c = ch;
            insert(L, dat, tag);
        }
        else if(tag==1)
        {
            cin>>in;
            dat.i=in;
            insert(L, dat, tag);//1 5 1 7 1 2 0 C 0 S 0 E 0 A 1 8 1 6 0 N 0 W 0 T 1 9 0 B 1 4 1 5 -1
        }
        cin>>tag;
    }
    clptr C=NULL;
    nlptr N=NULL;
    linking(L, C, N);
    printingN(N);
    cout<<endl;
    printingC(C);
}