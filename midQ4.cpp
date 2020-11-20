#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    struct btnode *lchild;
    int data;
    struct btnode *rchild;
    
};
void insert(btptr &T, int k)
{
    if(T==NULL)
    {
        T = new btnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    int ch;
    cin>>ch;
    if(ch!=0)
    insert(T->lchild, ch);
    cin>>ch;
    if(ch!=0)
    insert(T->rchild, ch);
}
void printmiddle(btptr sp, btptr fp)
{
    if(sp==NULL||fp==NULL)
    return;
    if(fp->lchild==NULL&&fp->rchild==NULL)
    {
        cout<<sp->data<<" ";
        return;
    }
    printmiddle(sp->lchild, fp->lchild->lchild);
    printmiddle(sp->rchild, fp->lchild->lchild);
}
int main()
{
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    printmiddle(T, T);
}