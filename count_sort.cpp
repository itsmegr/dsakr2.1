#include <iostream>
using namespace std;
void count_sort(int A[],int n)
{
    int max = -9999;
    for(int i=0;i<n;i++)
    {
        if(A[i]>max)
          max = A[i];
    }
    int fr[max+1], j=0;
  
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
        if(fr[i]!=0)
        {
            while(fr[i]!=0)
            {
                A[j] = i;
                fr[i]--, j++;
            }
        }
    }
    // for(int i=1;i<=max;i++)
    // {
    //    fr[i] = fr[i]+fr[i-1];
    // }
    // int index;
    // for(int i=0;i<n;i++)
    // {
    //    index = fr[A[i]] -1;
    //    B[index] = A[i];
    //    fr[A[i]]--;

    // }
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    count_sort(A,n);
    for(int i=0;i<n;i++)
    {
       cout<<A[i]<<" ";
    }
    cout<<endl;

}
