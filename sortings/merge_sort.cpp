#include <bits/stdc++.h>
#include <string>
using namespace std;
void mergePart(int A[], int B[], int n1, int n2)
{   

    int j;
    cout<<"value of n1 and n2"<<n1<<" "<<n2<<endl;

    for(int i=0;i<n2;i++)
    {
        for( j=0;j<n1;j++)
        {
            if(B[i]<A[j])
            {
                break;
            }
        }
        n1++;
        for(int k =n1-1;k>j;k--)
        {
            A[k]=A[k-1];
        }
        A[j]=B[i];
    }
    cout<<endl<<endl;
    for(int i=0;i<n1;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
}
void mergeSort(int A[], int l, int r, int m)
{

    int B[l+r+1],j=0;
    for(int i=0;i<(l+r+1);i++)
    {
        if(i%2==1)
        {
            B[j]=A[i];
            j++;
        }
    }
    for(int i=0;i<(l+r+1);i++)
    {
        if(i%2==0)
        {
            A[i/2] = A[i];
        }
    }

    for(int i =0;i<=m;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i =0;i<=m;i++)
    {
        cout<<B[i]<<" ";
    }

    cout<<endl;
    if(m==0)
    {
        cout<<"last came";
        mergePart(A, B, 1, 1);

    }
    else
    {
        
        mergeSort(A, l, m, (l+m)/2);
        mergeSort(B, l, m, (l+m)/2);
        mergePart(A,B,l+m+1,l+m+1);
        
    }
    
}
int main()
{
    int size;
    cin>>size;
    int A[size],n=size-1;
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    mergeSort(A, 0, n, n/2);
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
}