#include <iostream>
using namespace std;
struct ArrWithTag
{
    int element;
    int tag;

};
void count_sort(int A[],  struct ArrWithTag B[], int n)
{
    int max = -9999;
    for(int i=0;i<n;i++)
    {
        if(A[i]>max)
          max = A[i];
    }
    int fr[max+1], fr2[max+1];
    for(int i=0;i<=max;i++)
    {
        fr[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        fr[A[i]]++;
    }
    for(int i=0;i<=max;i++)
    {
       fr2[i] = fr[i];
    }
    for(int i=1;i<=max;i++)
    {
       fr[i] = fr[i]+fr[i-1];
    }
    for(int i=0;i<=max;i++)
    {
       fr[i]--;
    }
    int index;
    for(int i=0;i<n;i++)
    {
        if(fr2[A[i]]>1)
        {
            int x = fr[A[i]]-fr2[A[i]]+1;
            index = x;
            B[index].element = A[i];
            B[index].tag = i;
            fr2[A[i]]--;
        }
        else
        {
            index = fr[A[i]];
            B[index].element = A[i];
            B[index].tag = i;
            fr[A[i]]--;
        }
        

    }
}
void radix_sort(int Arr[], int n)
{
    int max = -999999;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]>max)
        max = Arr[i];
    }
    int A[n], div =1,arrB[n]; 
    struct ArrWithTag B[n];
    while(max/div>0)
    {
        for(int i=0;i<n;i++)
        {
            A[i] = (Arr[i]/div)%10;
        }
        count_sort(A,B,n);
        
        for(int i=0;i<n;i++)
        {
            arrB[i] = Arr[B[i].tag];
        }
        for(int i=0;i<n;i++)
        {
            Arr[i] = arrB[i];
        }

        div = div*10;
    }
}
int main()
{
    int n;
    cin>>n;
    int Arr[n], A[n];
    for(int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }
    radix_sort(Arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }

}