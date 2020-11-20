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
void findEle(bstptr T, bool &found, int k, bstptr &ele, bstptr &par)
{
    if(T!=NULL)
    {
        if(k==T->data)
        {
            found = true;
            ele = T;
        }
        else
        {
            if(!found)
            {
                par = T;
                findEle(T->lchild, found, k, ele, par);
            }
            if(!found)
            {
                par = T;
                findEle(T->rchild, found, k, ele, par);
            }
        }
        
    }
}
void print(bstptr T)
{
    if(T!=NULL)
    {
        print(T->lchild);
        cout<<T->data<<" ";
        print(T->rchild);
    }
}
void solution(bstptr &T)
{
    //need to change the solution as per as which is to add right min or left max
    bool found = false;
    int k;
    cin>>k;
    bstptr ele=NULL, par = NULL;
    findEle(T, found, k, ele, par);
    cout<<par->data<<" "<<endl;
    if(ele->lchild==NULL&&ele->rchild==NULL)
    {
        if(par->lchild==ele) par->lchild=NULL;
        if(par->rchild==ele) par->rchild=NULL;
    }
    else{
    bstptr temp = ele->lchild, above = ele;
    while(temp->rchild!=NULL)
    {
        above = temp;
        temp = temp->rchild;
    }
    above->rchild=NULL;
    ele->data=temp->data;
    }
    print(T);

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