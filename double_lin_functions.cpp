#include<bits/stdc++.h>
using namespace std;
typedef struct dlnode *dlptr;
struct dlnode{
    struct dlnode *left;
    int data;
    struct dlnode *right;
};
void create(dlptr &D)
{
    int n;
    cin>>n;
    dlptr temp, T;
    while(n>0)
    {
        if(D==NULL)
        {
            D = new(dlnode);
            D->left = NULL;
            D->data = n;
            D->right = NULL;
        }
        else
        {
            temp = D;
            while(temp->right!=NULL)
            {
                temp = temp->right;
            }
            T = new(dlnode);
            T->left = NULL;
            T->data = n;
            T->right = NULL;
            T->left = temp;
            temp->right = T;

        }
        
        cin>>n;
    }
}
void print(dlptr D)
{
    if(D!=NULL)
    {
        cout<<D->data<<" ";
        print(D->right);
    }
}
void addFront(dlptr &D, int k)
{
    dlptr T;
    T = new(dlnode);
    T->left = NULL;
    T->data = k;
    T->right = NULL;
    T->right = D;
    D = T;
    D->right->left = D;
}
void addEnd(dlptr D, int k)
{
    dlptr T;
    T = new(dlnode);
    T->left = NULL;
    T->data = k;
    T->right = NULL;
    while(D->right!=NULL)
    D= D->right;
    D->right = T;
    T->left = D;
}
void addBefore(dlptr D , int x, int y)
{
    while(D->data!=y)
    D = D->right;
    dlptr T;
    T = new(dlnode);
    T->left = NULL;
    T->data = x;
    T->right = NULL;
    T->left = D->left;
    T->right = D;
    D->left->right = T;
    D->left = T;
}
void addAfter(dlptr D , int x, int y)
{
    while(D->data!=y)
    D = D->right;
    dlptr T;
    T = new(dlnode);
    T->left = NULL;
    T->data = x;
    T->right = NULL;
    T->left = D;
    T->right = D->right;
    D->right ->left = T;
    D->right = T;
}
void delFront(dlptr &D)
{
    D = D->right;
    D->left->right = NULL;
    D->left = NULL;
}
void delEnd(dlptr D)
{
    while (D->right!=NULL)
    D = D->right;
    D->left->right = NULL;
    D->left = NULL;
    
}
void delK(dlptr D, int k)
{
    while(D->data!=k)
    D = D->right;
    D->left->right = D->right;
    D->right->left = D->left;
}
int nodeCount(dlptr D)
{
    if(D!=NULL)
    {
        return nodeCount(D->right) +1;
        D = D->right;
    }
    return 0;
}
dlptr partition(dlptr lower, dlptr higher)
{
    dlptr D = lower;
    int pi = lower->data;
    lower = lower->right;
    while(lower!=higher)
    {
        if(lower->data>pi)
        {
            if(higher->data<pi)
            {
                swap(lower->data, higher->data);
                if(lower->right==higher)
                {
                    lower = lower->right;
                    higher = higher->left;
                    break;
                }
                else
                {
                   lower = lower->right;
                   higher = higher->left;
                }
                
            }
            else
            {
                higher = higher->left;
            }
            
        }
        else
        {
            lower = lower->right;
        }
        
    }
    if(higher->data>pi)
    higher = higher->left;
    swap(D->data, higher->data);
    return higher;
}
void sorting(dlptr D,dlptr lower, dlptr higher)
{
    dlptr i;
    if(lower!=higher&&higher!=NULL&&lower!=higher->right)
    {
        i = partition(lower, higher);
        sorting(D,lower, i->left);
        sorting(D,i->right, higher);
    }
}
int main()
{
    dlptr D = NULL;
    create(D);
    dlptr T = D;
    while(T->right!=NULL)
    T = T->right;
    sorting(D,D,T);
    print(D);
}