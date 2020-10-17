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
void root_leaf_all(btptr T, stack<btptr> &st, int desf, int desr)
{
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        if(T->data==desf||T->data==desr)
        {
            st.push(T);
            printStackRe(st);
            cout<<endl;
            st.pop();
        }
        else
        {
            st.push(T);
            root_leaf_all(T->lchild, st, desf, desr);
            root_leaf_all(T->rchild, st, desf, desr);
            st.pop();
        }
        
        
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        if(T->data==desf||T->data==desr)
        {
            st.push(T);
            printStackRe(st);
            cout<<endl;
            st.pop();
        }
        else
        {
            st.push(T);
            root_leaf_all(T->rchild, st, desf, desr);
            st.pop();
        }
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        if(T->data==desf||T->data==desr)
        {
            st.push(T);
            printStackRe(st);
            cout<<endl;
            st.pop();
        }
        else
        {
            st.push(T);
            root_leaf_all(T->lchild, st, desf, desr);
            st.pop();
        }
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        if(T->data==desf||T->data==desr)
        {
            st.push(T);
            printStackRe(st);
            cout<<endl;
            st.pop();
        }
    }
}
int main()
{
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    stack<btptr> st;
    int desf, desr;
    cin>>desf>>desr;
    root_leaf_all(T, st, desf, desr);

}