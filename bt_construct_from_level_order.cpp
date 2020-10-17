#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
    
};
void construct(string str, btptr &T)
{
    int i=0;
    queue <btptr> qu;
    T = new(btnode);
    btptr curr, temp;
    T->data = str[i];
    T->lchild = NULL;
    T->rchild = NULL;
    qu.push(T);i++;
    while(str[i]!='$')
    {
        curr = qu.front();
        qu.pop();
        if(str[i]!='#'&&str[i]!='$')
        {
            temp = new(btnode);
            temp->data = str[i];
            temp->lchild = NULL;
            temp->rchild = NULL;
            curr->lchild = temp;
            qu.push(temp);
        }
        else if(str[i]=='$') break;
        i++;
        if(str[i]!='#'&&str[i]!='$')
        {
            temp = new(btnode);
            temp->data = str[i];
            temp->lchild = NULL;
            temp->rchild = NULL;
            curr->rchild = temp;
            qu.push(temp);
        }
        else if(str[i]=='$') break;
        i++;
    }
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
    string str;
    cin>>str;
    btptr T=NULL;
    construct(str, T);
    queue <btptr> Q;
    queue <int> lev_or;
    Q.push(T);
    btptr temp;
    temp = new(btnode);
    temp->data=-1;
    temp->lchild= NULL;
    temp->rchild = NULL;
    Q.push(temp);
    lee_order_qu(Q, lev_or);
}