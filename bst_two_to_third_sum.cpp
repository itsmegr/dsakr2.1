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
int max(bstptr T)
{
    while(T->rchild!=NULL)
    T = T->rchild;
    return T->data;
}
void traverse(bstptr T, int arr[])
{
    if(T!=NULL)
    {
        traverse(T->lchild, arr);
        arr[T->data] =1;
        traverse(T->rchild, arr);
    }
}
void printSum(int n, int arrt1[], int arrt2[])
{
    for(int i=n-1, j=1;i>j;i--,j++)
    {
        if(arrt1[i]==1&&arrt2[j]==1)
        cout<<"( "<<i<<", "<<j<<", "<<n<<") ";
        else
        if(arrt2[i]==1&&arrt1[j]==1)
        cout<<"( "<<j<<", "<<i<<", "<<n<<") ";
    }
}
void goingByele(bstptr T, int arrt1[], int arrt2[])
{
    if(T!=NULL)
    {
        goingByele(T->lchild, arrt1, arrt2);
        printSum(T->data, arrt1, arrt2);
        goingByele(T->rchild, arrt1, arrt2);
    }
}
int main()
{
    bstptr T1= NULL, T2 = NULL;
    int n;
    cin>>n;
    while(n>0)
    {
        insert(T1, n);
        cin>>n;
    }
    cin>>n;
    while(n>0)
    {
        insert(T2, n);
        cin>>n;
    }
    int t1max = max(T1), t2max=max(T2);
    int arrt1[t1max+1], arrt2[t2max+1];
    for(int i=0;i<=t1max;i++)
    arrt1[i]=0;
    for(int i=0;i<=t2max;i++)
    arrt2[i]=0;
    traverse(T1, arrt1);
    traverse(T2, arrt2);
    goingByele(T1, arrt1, arrt2);
    goingByele(T2, arrt1, arrt2);

}