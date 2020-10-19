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
void insert(btptr &T, char k, int space)
{
    if(T==NULL)
    {
        T = new btnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
        T->space = space;
    }
    char ch;
    cin>>ch;
    if(ch!='#')
    insert(T->lchild, ch, space-1);
    cin>>ch;
    if(ch!='#')
    insert(T->rchild, ch, space+1);
}
void lee_order_qu(queue <btptr> &Q, int lastSpace)
{
    if(!Q.empty())
    {
        if(Q.front()->data==-1)
        {
            btptr changeptr = Q.front();
            Q.pop();
            cout<<endl;
            lastSpace = 0;
            if(!Q.empty())
            Q.push(changeptr);
            lee_order_qu(Q, lastSpace);
        }
        else
        {
            btptr temp = Q.front();
            Q.pop();
            if(lastSpace==0)
            for(int i=0;i<=temp->space-lastSpace-1;i++) cout<<" ";
            else
            for(int i=0;i<=temp->space-lastSpace-3;i++) cout<<" ";
            cout<<temp->data<<" ";
            if(temp->lchild!=NULL)
            Q.push(temp->lchild);
            if(temp->rchild!=NULL)
            Q.push(temp->rchild);
            lee_order_qu(Q, temp->space);
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
    lee_order_qu(Q, 0);
}
int main()
{
    btptr T = NULL;
    char n;
    cin>>n;
    insert(T, n, 10);
    solution(T);
}