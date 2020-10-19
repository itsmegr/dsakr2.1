#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
    
};
void insert(btptr &T, char k)
{
    if(T==NULL)
    {
        T = new btnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    char ch;
    cin>>ch;
    if(ch!='#')
    insert(T->lchild, ch);
    cin>>ch;
    if(ch!='#')
    insert(T->rchild, ch);
}
void printStackRe(stack<btptr> S)
{
    if(!S.empty())
    {
        btptr T = S.top();
        S.pop();
        printStackRe(S);
        cout<<T->data<<" ";
    }
}
void leftMostPath(btptr T, string &boundry_nodes)
{
    if(T->lchild!=NULL)
    {
        boundry_nodes = boundry_nodes + T->data;
        leftMostPath(T->lchild,boundry_nodes);
    }
    else if(T->rchild!=NULL)
    {
        boundry_nodes = boundry_nodes + T->data;
        leftMostPath(T->rchild,boundry_nodes); 
    }
    else 
    {
       
    }
}
void rightMostPath(btptr T, string &boundry_nodes)
{
    if(T->rchild!=NULL)
    {
        rightMostPath(T->rchild,boundry_nodes); 
        boundry_nodes = boundry_nodes + T->data;
    }
    else if(T->lchild!=NULL)
    {
        rightMostPath(T->lchild,boundry_nodes);
        boundry_nodes = boundry_nodes + T->data;
    }

    else 
    {
        
    }
}
void root_leaf_all(btptr T, string &boundry_nodes)
{
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        root_leaf_all(T->lchild, boundry_nodes);
        root_leaf_all(T->rchild, boundry_nodes);
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        root_leaf_all(T->rchild, boundry_nodes);
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        root_leaf_all(T->lchild, boundry_nodes);
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        boundry_nodes = boundry_nodes + T->data;
    }
}
void print_hidden_nodes(btptr T, string &boundry_nodes)
{
    if(T!=NULL)
    {
        if(boundry_nodes.find(T->data)==-1)
        cout<<T->data<<" ";
        print_hidden_nodes(T->lchild, boundry_nodes);
        print_hidden_nodes(T->rchild, boundry_nodes);
    }
}
int main()
{
    string bou_nodes;
    btptr T = NULL;
    char n;
    cin>>n;
    insert(T, n);
    leftMostPath(T, bou_nodes);
    root_leaf_all(T, bou_nodes);
    rightMostPath(T, bou_nodes);
    print_hidden_nodes(T, bou_nodes);

}