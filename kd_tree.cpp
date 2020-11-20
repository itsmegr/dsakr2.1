#include <bits/stdc++.h>
using namespace std;
typedef struct kdtnode *kdtptr;
struct kdtnode
{
    struct kdtnode *lchild;
    int data[2];
    struct kdtnode *rchild;
};
void insert(kdtptr &T, int nodeData[], int i)
{
    if(T==NULL)
    {
        T = new(kdtnode);
        T->lchild = NULL;
        T->rchild = NULL;
        for(int i=0;i<2;i++)
        T->data[i] = nodeData[i];
    }
    else
    {
        if(nodeData[i]<T->data[i])
        insert(T->lchild, nodeData, (i+1)%2);
        else
        insert(T->rchild, nodeData, (i+1)%2);
    }
    
}
void print(kdtptr T)
{
    if(T!=NULL)
    {
        cout<<"(";
        for(int i=0;i<2;i++)
        cout<<T->data[i]<<" ";
        cout<<")";
        print(T->lchild);
        print(T->rchild);
    }
}
int main()
{
    int n, d;
    kdtptr T = NULL;
    int nodeDataArr[2], p;
    cin>>p;
    while(p!=0)
    {
        for(int i=0;i<2;i++)
        cin>>nodeDataArr[i];
        insert(T, nodeDataArr, 0);
        cin>>p;
    }
    print(T);
}