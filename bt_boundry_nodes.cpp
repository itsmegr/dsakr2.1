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
void printStackRe(stack<btptr> S)
{
    if(!S.empty())
    {
        btptr T = S.top();
        S.pop();
        printStackRe(S);
        cout<<T->data<<" ";
    }
}
void leftMostPath(btptr T)
{
    if(T->lchild!=NULL)
    {
        cout<<T->data<<" ";
        leftMostPath(T->lchild);
    }
    else if(T->rchild!=NULL)
    {
        cout<<T->data<<" ";
        leftMostPath(T->rchild); 
    }
    else 
    {
       
    }
}
void rightMostPath(btptr T)
{
    if(T->rchild!=NULL)
    {
        rightMostPath(T->rchild); 
        cout<<T->data<<" ";
    }
    else if(T->lchild!=NULL)
    {
        rightMostPath(T->lchild);
        cout<<T->data<<" ";
    }

    else 
    {
        
    }
}
void root_leaf_all(btptr T)
{
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        root_leaf_all(T->lchild);
        root_leaf_all(T->rchild);
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        root_leaf_all(T->rchild);
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        root_leaf_all(T->lchild);
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        cout<<T->data<<" ";
    }
}
int main()
{
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    leftMostPath(T);
    root_leaf_all(T);
    rightMostPath(T);
}