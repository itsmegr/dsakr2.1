#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
struct bstnode
{
    struct bstnode *lchild;
    int data;
    struct bstnode *rchild;
};
void insert(bstptr &T, int k)
{
    if(T==NULL)
    {
        T = new(bstnode);
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else
    {
        if(k<T->data)
        insert(T->lchild, k);
        else 
        insert(T->rchild, k);
    }
    
}
void deadNodes(bstptr T, int min, int max)
{
    if(T!=NULL)
    {
        if(min ==T->data&&T->rchild!=NULL)
        cout<<T->data<<" ";
        if(max==T->data&&T->rchild!=NULL)
        cout<<T->data<<" ";
        if(min==T->data&&max==T->data)
        cout<<T->data<<" ";
        deadNodes(T->lchild, min, T->data-1);
        deadNodes(T->rchild, T->data+1, max);
    }
}
void solution(bstptr &T)
{
    deadNodes(T, -999, 999);
}
int main()
{
    bstptr T = NULL;
    int n;
    cin>>n;
    while(n>0)
    {
        insert(T, n);
        cin>>n;
    }
    solution(T);
}