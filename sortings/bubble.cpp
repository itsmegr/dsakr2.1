#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    int size;
    cin>>size;
    int A[size];
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<size-1;i++)
    {
        for(int j=i;j<size-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
            }
        }

    }
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }

}