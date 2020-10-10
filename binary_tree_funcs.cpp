#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
    
};
void insert(btptr &T, char k)
{
    if(T==NULL)
    {
        T = new btnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    char ch;
    cin>>ch;
    if(ch!='.')
    insert(T->lchild, ch);
    cin>>ch;
    if(ch!='.')
    insert(T->rchild, ch);
}
void printPreOrder(btptr T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        printPreOrder(T->lchild);
        printPreOrder(T->rchild);
    }
}
void serialization(btptr T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        serialization(T->lchild);
        serialization(T->rchild);
    }
    else
    cout<<". ";
}
void iterativeDLR(btptr T)
{
    stack <btptr> s;
    if(T->rchild!=NULL)
    s.push(T->rchild);
    cout<<T->data;
    T = T->lchild;
    while(!s.empty())
    {
        cout<<T->data;
        if(T->rchild!=NULL)
        s.push(T->rchild);
        if(T->lchild!=NULL)
        T = T->lchild;
        else 
        T = s.top();
    }
}
int main()
{
    btptr T = NULL;
    char n;
    cin>>n;
    insert(T, n);
    printPreOrder(T);
    serialization(T);
}