#include <bits/stdc++.h>
using namespace std;
int partition(int *A, int lower, int higher)
{
    int pi = A[lower], i = lower+1, j=higher,temp;
    while(i<j)
    {
        if(A[i]>pi)
        {
            if(A[j]<=pi)
            {
                temp = A[j];
                A[j]=A[i];
                A[i]=temp;
                i++, j--;

            }
            else
            {
                j--;
            }
            
        }
        else
        {
            i++;
        }
        
    }
    if(A[i]>pi)
    {
        i--;
        temp = A[lower];
        A[lower]=A[i];
        A[i]=temp;

    }
    else
    {
        temp = A[lower];
        A[lower]=A[i];
        A[i]=temp;
    }
    return i;
    


}
void quick_sort(int *A, int lower, int higher)
{
    int i;
    if(lower<higher)
    {
        i=partition(A, lower, higher);
        quick_sort(A, lower, i-1);
        quick_sort(A, i+1, higher);
    }
}
int main()
{
    int size;
    cin>>size;
    int A[size], n= size-1;
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    quick_sort(A,0, n);
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
}
