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
void printPreOrder(btptr T, btptr arr[], int &i)
{
    if(T!=NULL)
    {
        printPreOrder(T->lchild, arr, i);
        arr[i] = T;
        i=i+1;
        printPreOrder(T->rchild, arr, i);
    }
}
void printOrder(btptr T)
{
    if(T!=NULL)
    {
        printOrder(T->lchild);
        cout<<T->data<<" ";
        printOrder(T->rchild);
    }
}
void nodeCount(btptr T, int &n)
{
    if(T!=NULL)
    {
        nodeCount(T->lchild, n);
        n++;
        nodeCount(T->rchild, n);
    }
}
int main()
{
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    queue <btptr> qu;
    n =0;
    nodeCount(T, n);
    btptr arr[n]; int j=0;
    printPreOrder(T, arr, j);
    int l=0, h=n-1,i=1;
    while(i<=n)
    {
        if(arr[l]->data<arr[l+1]->data)
        l++;
        if(arr[h]->data>arr[h-1]->data)
        h--;
        i++;
    }
    swap(arr[l]->data, arr[h]->data);
    printOrder(T);


}