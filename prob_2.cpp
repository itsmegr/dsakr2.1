#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i = 0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k =j;k<n;k++)
            {
                if(A[i]<A[j]&&A[j]<A[k]&&A[i]<A[k])
                {
                    cout<<A[i]<<" "<<A[j]<<" "<<A[k]<<endl;
                }
            }
        }
    }
    return 0;
}