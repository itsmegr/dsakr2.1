#include <bits/stdc++.h>
using namespace std;

int consSTforSumInRange(int i, int l, int h, int *S, int A[])
{
    if(l==h)
    {
        S[i] = A[l]; 
        return S[i];

    }
    else
    {
        int mid = (l+h)/2;
        S[i] = consSTforSumInRange(2*i+1, l, mid, S, A)+consSTforSumInRange(2*i+2, mid+1, h, S, A);
        return S[i];
    }
}
int sumRange(int *S, int A[], int sl, int sh, int l, int h, int i)
{
    if(l>=sl&&h<=sh)
    {
        return S[i];
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
void updateSumInRange(int *S, int l, int h, int i, int diff, int cind)
{
        if(cind>=l&&cind<=h)
        S[i] = S[i]+diff;
        if(l<h)
        {
        int mid = (l+h)/2;
        updateSumInRange(S, l, mid, 2*i+1, diff, cind); 
        updateSumInRange(S, mid+1, h, 2*i+2, diff, cind); 
        } 
}
int consSTminInRange(int i, int l, int h, int *S, int A[])
{
    if(l==h)
    {
        S[i] = A[l]; 
        return S[i];

    }
    else
    {
        int mid = (l+h)/2;
        S[i] = min(consSTminInRange(2*i+1, l, mid, S, A), consSTminInRange(2*i+2, mid+1, h, S, A));
        return S[i];
    }
}
int minInRange(int *S, int A[], int sl, int sh, int l, int h, int i)
{
    if(l>=sl&&h<=sh)
    {
        return S[i];
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
void updateMinInRange(int *S, int l, int h, int i, int newel, int cind)
{
        if(cind>=l&&cind<=h)
        {
            if(l==cind&&h==cind)S[i]=newel;
            else if(l<h)
            {
                int mid = (l+h)/2;
                updateMinInRange(S, l, mid, 2*i+1, newel, cind); 
                updateMinInRange(S, mid+1, h, 2*i+2, newel, cind); 
                S[i] = min(S[2*i+1], S[2*i+2]);
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

    int *S = new int[max_size];
    consSTforSumInRange(0, 0, n-1, S, A);
    int *S1 = new int[max_size];
    consSTminInRange(0, 0, n-1, S1, A);
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
            updateMinInRange(S1, 0,n-1,0,par3,par2);
            break;
        case 1:
            cout<<sumRange(S,A,par2, par3,0,n-1,0)<<endl;
            break;
        case 2:
            cout<<minInRange(S1,A,par2, par3,0, n-1, 0)<<endl;
            break;
        case 3:
            cout<<sumRange(S,A,par2, par3,0,n-1,0)/(par3-par2+1)<<endl;
            break;
        default:
            break;
        }
        queryNum--;
    }
}