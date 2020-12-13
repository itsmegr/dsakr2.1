#include <bits/stdc++.h>
#include <string>
using namespace std;
int minIndexFun(int *A, int n,int minIndex)
{
    if(n==0)
    {
        return A[0]<A[minIndex]?0:minIndex;
    }
    else
    {
        return A[n]<A[minIndex]?minIndexFun(A, n-1, n):minIndexFun(A, n-1, minIndex);
    }
    

}

void SelectionSort(int *A, int n, int& subIndex )
{
    int minIndex;
    if(subIndex==n)
    {
        
    }
    else
    {
        minIndex = (minIndexFun( A+subIndex, n-subIndex, n-subIndex))+subIndex;
        swap(A[minIndex], A[subIndex]);
        subIndex++;
        SelectionSort( A, n, subIndex);
    }
    

}
int main()
{
    int size;
    cin>>size;
    int A[size],n=size-1,Subindex=0;
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    SelectionSort(A, n, Subindex);
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }

}