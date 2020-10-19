#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
struct bstnode
{
    struct bstnode *lchild;
    int data;
    struct bstnode *rchild;
};
void create(bstptr &T, int k)
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
        if(k>T->data)
        {
            create(T->rchild, k);
        }
        else
        {
            create(T->lchild, k);
        } 
    }
}
void levelPrint(queue <bstptr> &Q)
{
    if(!Q.empty())
    {
        if(Q.front()->data==-1)
        {
            bstptr changeptr = Q.front();
            Q.pop();
            cout<<endl;
            if(!Q.empty())
            Q.push(changeptr);
            levelPrint(Q);
            
        }
        else
        {
            bstptr temp = Q.front();
            Q.pop();
            cout<<temp->data<<" ";
            if(temp->lchild!=NULL)
            Q.push(temp->lchild);
            if(temp->rchild!=NULL)
            Q.push(temp->rchild);
            levelPrint(Q);
        }
    }
}
int main()
{
    int n;
    stack <int> s;
    cin>>n;
    while(n>0)
    {
        s.push(n);
        cin>>n;
    }
    bstptr T = NULL;
    while(!s.empty())
    {
        create(T, s.top());
        s.pop();
    }
    queue <bstptr> Q;
    Q.push(T);
    bstptr temp;
    temp = new bstnode;
    temp->data = -1;
    temp->rchild=NULL;
    temp->lchild = NULL;
    Q.push(temp);
    levelPrint(Q);
    cout<<endl;
    
}