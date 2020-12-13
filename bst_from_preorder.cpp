// #include <bits/stdc++.h>
// using namespace std;
// typedef struct bstnode *bstptr;
// struct bstnode
// {
//     struct bstnode *lchild = NULL;
//     int data;
//     int min;
//     int max;
//     struct bstnode *rchild = NULL;

// };
// void insert(bstptr &T, int k)p
// {
//     if(T==NULL)
//     {
//         T = new(bstnode);
//         T->data = k;
//         T->lchild = NULL;
//         T->rchild = NULL;
//     }
//     else
//     {
//         if(k<T->data)
//         insert(T->lchild, k);
//         else 
//         insert(T->rchild, k);
//     }
    
// }
// void constr_from_preorder(bstptr &T, vector<int> pre, int &i, int min, int max)
// {
//     if(T==NULL)
//     {
//         T=new(bstnode);
//         T->data = pre[i];
//         T->min = min;
//         T->max = max;
//     }
//     if(i>=pre.size())
//     return;


//     if(pre[i+1]>=min&&pre[i+1]<=max)
//     {
//         i=i+1;
//         if(pre[i]>=min&&pre[i]<T->data)
//         {
//             constr_from_preorder(T->lchild, pre, i, min, T->data-1);
//             i= i+1;
//             if(pre[i]<=max&&pre[i]>T->data);
//             constr_from_preorder(T->rchild, pre, i,T->data+1, max);
//         }
//         else
//         {
//             constr_from_preorder(T->rchild, pre, i,T->data+1, max);
//         }
        
//     }

// }
// void preorder(bstptr T){ //DLR
// 	if(!T) return;
// 	cout<<T->data<<" ";
// 	preorder(T->lchild);
// 	preorder(T->rchild);
// }
// void left_rotation(bstptr &BT){
//     bstptr r = BT->rchild;
//     BT->rchild = r->lchild;
//     r->lchild = BT;
//     BT = r;
// }

// void right_rotation(bstptr &BT){
//     bstptr l = BT->lchild;
//     BT->lchild = l->rchild;
//     l->rchild = BT;
//     BT = l;
// }

// void shift(bstptr &BT, int a){
//     if(BT==NULL)
//     return;
//     if(BT->data == a)
//         return;
//     if(a<BT->data){
//         if(BT->lchild!=NULL){
//         shift(BT->lchild, a);
//         right_rotation(BT);
//         }
//     }
//     else{ 
//         if(BT->rchild!=NULL)
//         {
//         shift(BT->rchild, a);
//         left_rotation(BT);
//         }
//     }
// }

// void rotate(bstptr &BT1, bstptr &BT2){
//     if(BT1 == NULL || BT2 == NULL)return;
//     if(BT1->data != BT2->data)
//         shift(BT1, BT2->data);
//     rotate(BT1->lchild, BT2->lchild);
//     rotate(BT1->rchild, BT2->rchild);
// }

// int main()
// {
//     bstptr T1 = NULL, T2=NULL;
//     vector <int> pre;
//     int n;
//     cin>>n;
//     while(n>0)
//     {
//         pre.push_back(n);
//         cin>>n;
//     }
//     int i=0;
//     constr_from_preorder(T1, pre,i,INT_MIN, INT_MAX);
//     preorder(T1);
//     cout<<endl;
//     pre.clear();
//     cin>>n;
//     while(n>0)
//     {
//         pre.push_back(n);
//         cin>>n;
//     }
//     i=0;
//     constr_from_preorder(T2, pre,i,INT_MIN, INT_MAX);
//     preorder(T2);
//     cout<<endl;
//     rotate(T1,T2);
//     preorder(T1);

// }

#include<bits/stdc++.h>
using namespace std;

struct bstnode{
    bstnode* lc = NULL;
    int data;
    bstnode* rc = NULL;
};

typedef struct bstnode* bstptr;

void Construct(bstptr &BT, int a){
    if(BT == NULL){
        BT = new(bstnode);
        BT->data =a ;
        return;
    }
    if(a<BT->data)
        Construct(BT->lc, a);
    else 
        Construct(BT->rc, a);
}

void left_rotation(bstptr &BT){
    bstptr r = BT->rc;
    BT->rc = r->lc;
    r->lc = BT;
    BT = r;
}

void right_rotation(bstptr &BT){
    bstptr l = BT->lc;
    BT->lc = l->rc;
    l->rc = BT;
    BT = l;
}

void shift(bstptr &BT, int a){
    if(BT->data == a)
        return;
    if(a<BT->data){
        shift(BT->lc, a);
        right_rotation(BT);
    }
    else{ 
        shift(BT->rc, a);
        left_rotation(BT);
    }
}

void rotate(bstptr &BT1, bstptr &BT2){
    if(BT1 == NULL || BT2 == NULL)return;
    if(BT1->data != BT2->data)
        shift(BT1, BT2->data);
    rotate(BT1->lc, BT2->lc);
    rotate(BT1->rc, BT2->rc);
}

void Print(bstptr BT){
    if(BT == NULL)return;
    cout<<BT->data<<" ";
    Print(BT->lc);
    Print(BT->rc);
}

int main(){
    bstptr BT1 = NULL,BT2 = NULL;
    int n;
    while(cin>>n, n!=-1)
        Construct(BT1, n);
    while(cin>>n, n!=-1)
        Construct(BT2, n);
    rotate(BT1, BT2);
    Print(BT1);
}