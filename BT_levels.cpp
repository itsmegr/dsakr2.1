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
void lee_order_qu(queue <btptr> &Q, queue<int> &lev_or)
{
    if(!Q.empty())
    {
        if(Q.front()->data==-1)
        {
            btptr changeptr = Q.front();
            Q.pop();
            cout<<endl;
            lev_or.push(-1);
            if(!Q.empty())
            Q.push(changeptr);
            lee_order_qu(Q, lev_or);
        }
        else
        {
            btptr temp = Q.front();
            Q.pop();
            lev_or.push(temp->data);
            cout<<temp->data<<" ";
            if(temp->lchild!=NULL)
            Q.push(temp->lchild);
            if(temp->rchild!=NULL)
            Q.push(temp->rchild);
            lee_order_qu(Q, lev_or);
        }
    }
}
int main()
{
    queue <btptr> Q;
    queue <int> lev_or;
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    Q.push(T);
    btptr temp;
    temp = new(btnode);
    temp->data=-1;
    temp->lchild= NULL;
    temp->rchild = NULL;
    Q.push(temp);
    lee_order_qu(Q, lev_or);
    while(!lev_or.empty())
    {
        cout<<lev_or.front()<<" ";
        lev_or.pop();
    }

}