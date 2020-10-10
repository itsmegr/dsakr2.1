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
void printStackRe(stack<bstptr> S)
{
    if(!S.empty())
    {
        bstptr T = S.top();
        S.pop();
        printStackRe(S);
        cout<<T->data<<" ";
    }
}
int sumretu(stack<bstptr> S)
{
    if(!S.empty())
    {
        bstptr T = S.top();
        S.pop();
        return sumretu(S) + T->data;
    }
    else return 0;
}
void leftMostPath(bstptr T, stack<bstptr> &st)
{
    if(T->lchild!=NULL)
    {
        st.push(T);
        leftMostPath(T->lchild, st);
    }
    else if(T->rchild!=NULL)
    {
        st.push(T);
        leftMostPath(T->rchild, st); 
    }
    else 
    {
        st.push(T);
        printStackRe(st);
        cout<<endl;
    }
}
void rightMostPath(bstptr T, stack<bstptr> &st)
{
    if(T->rchild!=NULL)
    {
        st.push(T);
        rightMostPath(T->rchild, st); 
    }
    else if(T->lchild!=NULL)
    {
        st.push(T);
        rightMostPath(T->lchild, st);
    }

    else 
    {
        st.push(T);
        printStackRe(st);
        cout<<endl;
    }
}
void root_leaf_all(bstptr T, stack<bstptr> &st)
{
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        st.push(T);
        root_leaf_all(T->lchild, st);
        root_leaf_all(T->rchild, st);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        st.push(T);
        root_leaf_all(T->rchild, st);
        st.pop();
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        st.push(T);
        root_leaf_all(T->lchild, st);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        st.push(T);
        printStackRe(st);
        cout<<endl;
        st.pop();
    }
}
void copyStack(stack<bstptr> st, stack<bstptr> &maxSum)
{
    if(!st.empty())
    {
        bstptr Temp = st.top();
        st.pop();
        copyStack(st, maxSum);
        maxSum.push(Temp);
    }
}
void max_sum_path(bstptr T, stack<bstptr> &st, stack<bstptr> &maxSum, int &max)
{
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        st.push(T);
        max_sum_path(T->lchild, st, maxSum,max);
        max_sum_path(T->rchild, st, maxSum,max);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        st.push(T);
        max_sum_path(T->rchild, st, maxSum,max);
        st.pop();
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        st.push(T);
        max_sum_path(T->lchild, st, maxSum, max);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        int sumRe;
        st.push(T);
        sumRe = sumretu(st);
        if(max<sumRe)
        {
            max = sumRe;
            while(!maxSum.empty())
            maxSum.pop();
            copyStack(st, maxSum);
        }
        st.pop();
    }
}
void min_sum_path(bstptr T, stack<bstptr> &st, stack<bstptr> &minSum, int &min)
{
    if(T->lchild!=NULL&&T->rchild!=NULL)
    {
        st.push(T);
        min_sum_path(T->lchild, st, minSum,min);
        min_sum_path(T->rchild, st, minSum,min);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild!=NULL)
    {
        st.push(T);
        min_sum_path(T->rchild, st, minSum,min);
        st.pop();
    }
    else if(T->lchild!=NULL&&T->rchild==NULL)
    {
        st.push(T);
        min_sum_path(T->lchild, st, minSum, min);
        st.pop();
    }
    else if(T->lchild==NULL&&T->rchild==NULL)
    {
        int sumRe;
        st.push(T);
        sumRe = sumretu(st);
        if(min>sumRe)
        {
            min = sumRe;
            while(!minSum.empty())
            minSum.pop();
            copyStack(st, minSum);
        }
        st.pop();
    }
}
int main()
{
    int n;
    bstptr T = NULL;
    cin>>n;
    while(n>=0)
    {
       insert(T, n);
       cin>>n;
    }
    stack<bstptr> st,temp,A, max_sum, min_sum;
    int max = -999, min= 999;
    root_leaf_all(T, st);
    leftMostPath(T, st);
    rightMostPath(T, temp);
    max_sum_path(T, A, max_sum, max);
    printStackRe(max_sum);
    cout<<endl;
    min_sum_path(T, A, min_sum, min);
    printStackRe(min_sum);
}