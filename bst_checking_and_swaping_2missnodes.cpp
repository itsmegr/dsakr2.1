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
bool check_bst(btptr T, int min, int max)
{
    if(T!=NULL)
    {
        if(T->data>=min &&T->data<=max)
        {
           bool x = check_bst(T->lchild, min, T->data-1);
           if(!x) return false;
           else
           {
              x = check_bst(T->rchild, T->data+1, max);
              if(!x) return false;
              else return true;
           }
        }
        else
        return false;
    }
    else
    return true;
}
void minMax(btptr T, int min, int max, stack <btptr> &s)
{
    if(T!=NULL)
    {
        if(T->data>=min &&T->data<=max)
        {
           minMax(T->lchild, min, T->data-1, s);
           minMax(T->rchild, T->data+1, max, s);
        }
        else
        {
            cout<<T->data<<endl;
            s.push(T);
        }
        
    }
}
void solution(btptr &T)
{
    bool x = check_bst(T, -999, 999);
    if(x) cout<<true<<endl;
    else cout<<false<<endl;
    stack <btptr> s;
    minMax(T, -999, 999, s);
    btptr T1 = s.top(), T2;
    s.pop();
    T2 = s.top();
    s.pop();
    swap(T1->data, T2->data);
    x = check_bst(T, -999, 999);
    if(x) cout<<true<<endl;
    else cout<<false<<endl;
}
int main()
{
    btptr T = NULL;
    int n;
    cin>>n;
    insert(T, n);
    solution(T);
}
