#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,firstunsorted,lastunsorted;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    firstunsorted =0;
    while(firstunsorted<n-1)
    {
        if(A[firstunsorted+1]<A[firstunsorted])
        {
            break;
        }
        else
        {
            firstunsorted++;
        }
        
    }
    lastunsorted = n-1;
    while(n-1<firstunsorted)
    {
        if(A[lastunsorted-1]>A[lastunsorted])
        {
            break;
        }
        else
        {
            lastunsorted--;
        }
        
    }
    cout<<firstunsorted<<" "<<lastunsorted;
    return 0;
}