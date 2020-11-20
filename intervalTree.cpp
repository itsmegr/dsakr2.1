#include <bits/stdc++.h>
using namespace std;
typedef struct itnode *itptr;
struct itnode{
    int low;
    int high;
    int max;
    itptr lc;
    itptr rc;
};
int insert(itptr &T, int l, int h, int m)
{
    if(T==NULL)
    {
        T = new(itnode);
        T->low = l;
        T->high =h;
        T->max = m;
        T->lc=NULL,T->rc=NULL;
        return T->max;
    }
    else
    {
        if(l<T->low)
        {
            int childMax;
            childMax = insert(T->lc, l,h,m);
            T->max = max(childMax, T->max);
            return T->max;
        }
        else
        {
            int childMax;
            childMax = insert(T->rc, l,h,m);
            T->max = max(childMax, T->max);
            return T->max;
        }
    }
    
}

void overlap(itptr T, int ql,int qh)
{
    if(T!=NULL)
    {
        if(ql>=T->low&&qh<=T->high)
        cout<<T->low<<" "<<T->high<<endl;
        overlap(T->lc,ql,qh);
        overlap(T->rc,ql,qh);

    }
}
int main()
{
    itptr T=NULL;
    int i=1,i1,i2,i3,i4;
    while(i<=8)
    {
        cin>>i1;
        if(i1==1)
        {
            cin>>i2>>i3>>i4;
            insert(T,i2,i3,i4);
        }
        else if(i1==2)
        {
            cin>>i2>>i3;
            overlap(T, i2,i3);
        }
        i++;
    }
}