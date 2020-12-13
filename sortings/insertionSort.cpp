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
    for(int i=1;i<size;i++)
    {
        int sortMe = A[i],j=i-1;
        while(j>=0)
        {
            if(sortMe<A[j])
            {
              j--;
            }
            else
            {
                break;
            }  
        }
        for(int k=i;k>j+1;k--)
        {
            A[k]=A[k-1];
        }
        A[j+1]=sortMe;
        
    }
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
  

}