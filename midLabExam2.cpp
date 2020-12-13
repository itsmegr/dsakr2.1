#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    struct btnode *lchild;
    int data;
    struct btnode *rchild;
    
};
void insert(btptr &T, int k, int nl, int nr)
{
    if(T==NULL)
    {
        T = new btnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    int n;
    // cout<<"enter lc for "<<k<<endl;
    // cout<<"nl and nr is "<<nl<<" "<<nr<<endl;
    if(nl>0)
    {
        cin>>n;
        insert(T->lchild, n, nl/2, nl-(nl/2)-1);
    }
    // cout<<"enter rc for "<<k<<endl;
    // cout<<"nl and nr is "<<nl<<" "<<nr<<endl;
    if(nr>0)
    {
        
        cin>>n;
        insert(T->rchild, n, nr/2, nr-(nr/2)-1); 
    }

}
//printing binary tree in 2d dimension
// void printBinaryTree(btptr root, int space = 0, int height = 10)
// {
//     if (root == nullptr)
//         return;

//     space += height;

//     printBinaryTree(root->rchild, space);
//     cout << endl;

//     for (int i = height; i < space; i++)
//         cout << ' ';
//     cout << root->data;

//     cout << endl;
//     printBinaryTree(root->lchild, space);
// }
void preorder(btptr T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
int main()
{
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n, 10, 10);
    // cout<<"tree is "<<endl;
    // printBinaryTree(T);
    cout<<endl<<"preorder traversal is "<<endl;
    preorder(T);
}