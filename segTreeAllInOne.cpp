#include <bits/stdc++.h>
using namespace std;
typedef struct node *nptr;
struct node{
    int min;
    int max;
    int sum;
    float average; 
};
struct node consST(int i, int l, int h, nptr S, int A[])
{
    if(l==h)
    {
        S[i].min = A[l],S[i].max = A[l],S[i].sum = A[l],S[i].average = float(A[l]); 
        return S[i];
    }
    else
    {
        int mid = (l+h)/2;
        struct node t1, t2;
        t1 =consST(2*i+1, l, mid, S, A);
        t2 = consST(2*i+2, mid+1, h, S, A);
        S[i].sum = t1.sum+t2.sum;
        S[i].min = min(t1.min, t2.min);
        S[i].max = max(t1.max, t2.max);
        S[i].average = (t1.average+t2.average)/2;
        return S[i];
    }
}
int sumRange(nptr S, int A[], int sl, int sh, int l, int h, int i)
{
    if(l>=sl&&h<=sh)
    {
        return S[i].sum;
    }
    else if(h<sl||l>sh)
    {
        return 0;
    }
    else
    {
        int mid = (l+h)/2;
        return sumRange(S, A, sl, sh, l, mid, 2*i+1)+sumRange(S, A, sl, sh,mid+1, h, 2*i+2);
    }  
}
int minInRange(nptr S, int A[], int sl, int sh, int l, int h, int i)
{
    if(l>=sl&&h<=sh)
    {
        return S[i].min;
    }
    else if(h<sl||l>sh)
    {
        return 9999999;
    }
    else
    {
        int mid = (l+h)/2;
        return min(minInRange(S, A, sl, sh, l, mid, 2*i+1), minInRange(S, A, sl, sh,mid+1, h, 2*i+2));
    }  
}
int maxInRange(nptr S, int A[], int sl, int sh, int l, int h, int i)
{
    if(l>=sl&&h<=sh)
    {
        return S[i].max;
    }
    else if(h<sl||l>sh)
    {
        return -9999999;
    }
    else
    {
        int mid = (l+h)/2;
        return max(maxInRange(S, A, sl, sh, l, mid, 2*i+1), maxInRange(S, A, sl, sh,mid+1, h, 2*i+2));
    }
}
void updateSumInRange(nptr S, int l, int h, int i, int diff, int cind)
{
        if(cind>=l&&cind<=h)
        S[i].sum = S[i].sum+diff;
        if(l<h)
        {
        int mid = (l+h)/2;
        updateSumInRange(S, l, mid, 2*i+1, diff, cind); 
        updateSumInRange(S, mid+1, h, 2*i+2, diff, cind); 
        } 
}

void updateMinInRange(nptr S, int l, int h, int i, int newel, int cind)
{
        if(cind>=l&&cind<=h)
        {
            if(l==cind&&h==cind)S[i].min=newel;
            else if(l<h)
            {
                int mid = (l+h)/2;
                updateMinInRange(S, l, mid, 2*i+1, newel, cind); 
                updateMinInRange(S, mid+1, h, 2*i+2, newel, cind); 
                S[i].min = min(S[2*i+1].min, S[2*i+2].min);
            }
        }
}
void updateMaxInRange(nptr S, int l, int h, int i, int newel, int cind)
{
        if(cind>=l&&cind<=h)
        {
            if(l==cind&&h==cind)S[i].max=newel;
            else if(l<h)
            {
                int mid = (l+h)/2;
                updateMaxInRange(S, l, mid, 2*i+1, newel, cind); 
                updateMaxInRange(S, mid+1, h, 2*i+2, newel, cind); 
                S[i].max = max(S[2*i+1].max, S[2*i+2].max);
            }
        }
}
int main()
{
    int n,i,x;
    cin>>n;
    i=0;
    int A[n];
    while(i<n)
    {
        cin>>A[i];
        i++;
    }
    //find the size of segment tree
    x = int(ceil(log2(n)));

    //find the max size of segment array
    int max_size = 2*(int(pow(2,x)))-1;

    nptr S = new node[max_size];
    consST(0, 0, n-1, S, A);
    int queryNum,par1, par2, par3;
    cin>>queryNum;
    while(queryNum>0)
    {
        cin>>par1>>par2>>par3;
        int oldVal = A[par2];
        switch (par1)
        {
        case 0:
            //to change the segment tree
            A[par2] = par3;
            updateSumInRange(S, 0,n-1, 0,A[par2]-oldVal, par2);
            updateMinInRange(S, 0,n-1,0,par3,par2);
            updateMaxInRange(S, 0,n-1,0,par3,par2);
            break;
        case 1:
            cout<<minInRange(S,A,par2, par3,0, n-1, 0)<<endl;
            break;
        case 2:
            cout<<maxInRange(S,A,par2, par3,0, n-1, 0)<<endl;
            break;
        case 3:
            cout<<sumRange(S,A,par2, par3,0,n-1,0)<<endl;
            break;

        case 4:
            cout<<float(sumRange(S,A,par2, par3,0,n-1,0))/float((par3-par2+1))<<endl;
            break;
        default:
            break;
        }
        queryNum--;
    }
}