#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
    int space = 0;
    
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
void lee_order_qu(queue <btptr> &Q, int space, int initSpace)
{
    if(!Q.empty())
    {
        if(Q.front()->data==-1)
        {
            btptr changeptr = Q.front();
            Q.pop();
            cout<<endl;
            initSpace = initSpace-space/2;
            for(int i=0;i<=initSpace;i++)
            cout<<" ";
            if(!Q.empty())
            Q.push(changeptr);
            lee_order_qu(Q,space/2,initSpace);
        }
        else
        {
            btptr temp = Q.front();
            Q.pop();
            cout<<temp->data<<" ";
            for(int i=0;i<=space;i++)
            cout<<" ";
            if(temp->lchild!=NULL)
            Q.push(temp->lchild);
            if(temp->rchild!=NULL)
            Q.push(temp->rchild);
            lee_order_qu(Q, space, initSpace);
        }
    }
}
void solution(btptr &T)
{
    queue <btptr> Q;
    Q.push(T);
    btptr temp;
    temp = new(btnode);
    temp->data=-1;
    temp->lchild= NULL;
    temp->rchild = NULL;
    Q.push(temp);
    lee_order_qu(Q, 16, 64);
}
int main()
{
    btptr T = NULL;
    char n;
    cin>>n;
    insert(T, n);
    for(int i=0;i<=64;i++) cout<<" ";
    solution(T);
}