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
void root_leaf_all(btptr T, stack<btptr> &st, int lastTur, int turns)
{
    int x = turns;
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        st.push(T);
        if(lastTur==1) x++;
        root_leaf_all(T->lchild, st, 0, x);
        if(lastTur==0) turns++;
        root_leaf_all(T->rchild, st, 1, turns);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        st.push(T);
        if(lastTur==0) turns++;
        root_leaf_all(T->rchild, st, 1, turns);
        st.pop();
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        st.push(T);
        if(lastTur==1) turns++;
        root_leaf_all(T->lchild, st, 0, turns);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        cout<<turns<<" ";
        st.push(T);
        printStackRe(st);
        cout<<endl;
        st.pop();
    }
}
int main()
{
    stack<btptr> st;
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    root_leaf_all(T, st, 0, 0);

}