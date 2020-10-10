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
void levelPrint(queue <bstptr> &Q)
{
    if(!Q.empty())
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
void revRevPrint(queue <bstptr> &Q)
{
    if(!Q.empty())
    {
        bstptr temp = Q.front();
        Q.pop();
        if(temp->lchild!=NULL)
        Q.push(temp->lchild);
        if(temp->rchild!=NULL)
        Q.push(temp->rchild);
        revRevPrint(Q);
        cout<<temp->data<<" ";
    }
}
void revPrint(queue <bstptr> &Q)
{
    if(!Q.empty())
    {
        bstptr temp = Q.front();
        Q.pop();
        if(temp->rchild!=NULL)
        Q.push(temp->rchild);
        if(temp->lchild!=NULL)
        Q.push(temp->lchild);
        revPrint(Q);
        cout<<temp->data<<" ";
    }
}
void level_order_queue(queue <bstptr> &Q,queue <int> &leve_orde)
{
    if(!Q.empty())
    {
        bstptr temp = Q.front();
        Q.pop();
        leve_orde.push(temp->data);
        if(temp->lchild!=NULL)
        Q.push(temp->lchild);
        if(temp->rchild!=NULL)
        Q.push(temp->rchild);
        level_order_queue(Q, leve_orde);
    }
}
void squi_leve_p(queue <int> leve_orde)
{
    int i=1,j=1;
    stack <int> for_rev;

    while(!leve_orde.empty())
    {
        if(i%2==1)
        {
            for(int k=1;k<=j&&(!leve_orde.empty());k++)
            {
                cout<<leve_orde.front()<<" ";
                leve_orde.pop();
            }
        }
        else
        {
           for(int k=1;k<=j&&(!leve_orde.empty());k++)
            {
                for_rev.push(leve_orde.front());
                leve_orde.pop();
            }
            while(!for_rev.empty())
            {
                cout<<for_rev.top()<<" ";
                for_rev.pop();
            }
        }
        j=j*2;
        i++;
    }
}
void rev_squi_leve_p(queue <int> leve_orde)
{
    int i=1,j=1;
    stack <int> for_rev;

    while(!leve_orde.empty())
    {
        if(i%2==0)
        {
            for(int k=1;k<=j&&(!leve_orde.empty());k++)
            {
                cout<<leve_orde.front()<<" ";
                leve_orde.pop();
            }
        }
        else
        {
           for(int k=1;k<=j&&(!leve_orde.empty());k++)
            {
                for_rev.push(leve_orde.front());
                leve_orde.pop();
            }
            while(!for_rev.empty())
            {
                cout<<for_rev.top()<<" ";
                for_rev.pop();
            }
        }
        j=j*2;
        i++;
    }
}
int main()
{
    int n;
    queue <bstptr> Q;
    queue <bstptr> Q1;
    bstptr T = NULL;
    cin>>n;
    while(n>=0)
    {
       insert(T, n);
       cin>>n;
    }
    Q.push(T);
    Q1 = Q;
    levelPrint(Q);
    cout<<endl;
    Q = Q1;
    revRevPrint(Q);
    cout<<endl;
    Q = Q1;
    revPrint(Q);
    cout<<endl;
    queue <int> leve_orde;
    Q = Q1;
    level_order_queue(Q, leve_orde);

    squi_leve_p(leve_orde);
    cout<<endl;
    rev_squi_leve_p(leve_orde);
    cout<<endl;
    squi_leve_p(leve_orde);
    cout<<endl;
    rev_squi_leve_p(leve_orde);
    cout<<endl;

}
