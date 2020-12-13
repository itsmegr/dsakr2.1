#include <bits/stdc++.h>
using namespace std;
int partition(int *A, int lower, int higher)
{
    int pi = A[lower], i = lower+1, j=higher;
    while(i<j)
    {
        if(A[i]>pi)
        {
            if(A[j]<pi)
            {
                swap(A[i], A[j]);
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
    if(A[j]>pi)
    {
        i--;
        swap(pi, A[i]);

    }
    else
    {
        swap(pi, A[i]);
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
    quick_sort(A,0, n-1);
}
