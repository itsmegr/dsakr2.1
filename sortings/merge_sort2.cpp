#include <bits/stdc++.h>
#include <string>
using namespace std;
void merge(int *A, int l, int mid, int h)
{
   int B[h-mid],n1 = mid+1,j;
   for(int i = mid+1;i<=h;i++)
   {
       B[i-mid+1] = A[i];
   }
    for(int i=0;i<h-mid;i++)
    {
        for( j=0;j<n1;j++)
        {
            if(B[i]<A[j])
            {
                break;
            }
        }
        n1++;
        for(int k =mid+1-1;k>j;k--)
        {
            A[k]=A[k-1];
        }
        A[j]=B[i];
    }
}
void mergeSort(int *A, int l,int h)
{
    int mid = (l+h)/2;
    if(l<h)
    {
        
        mergeSort(A, l,mid);
        mergeSort(A, mid+1, h);
        merge(A, l, mid, h);
        
    }
    else
    {
        merge(A, l, mid, h);
    }
    

}
int main()
{
    int size;
    cin>>size;
    int A[size];
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    mergeSort(A,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
    
}