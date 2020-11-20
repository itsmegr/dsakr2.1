#include <bits/stdc++.h>
#include <vector>
using namespace std;

void maxHeap(vector <int> &H, int i)
{
    if(i>0)
    {
        if(H[i]>H[(i-1)/2])
        {
            swap(H[i],H[(i-1)/2]);
            maxHeap(H, (i-1)/2);
        }
    }
}
int maxi(int i, vector <int> H)
{
    if(H[(2*i)+1]<H[(2*i)+2])
    return (2*i)+2;
    else 
    return (2*i)+1;
}
void heapsort(vector <int> &H, int i)
{
    if((2*i)+1<H.size()&&(2*i)+2<H.size())
    {
        if(!(H[i]>H[(2*i)+1]&&H[i]>H[(2*i)+2]))
        {
            int k = maxi(i, H);
            swap(H[i], H[k]);
            heapsort(H, k);
        }
    }
    else if ((2*i)+1<H.size()&&(2*i)+2>=H.size())
    {
        if(H[i]<H[(2*i)+1])
        {
            swap(H[i], H[(2*i)+1]);
        }
    }
}
int main()
{
    vector <int> A, H;
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        A.push_back(k);
    }
    H.push_back(A[0]);
    for(int i=1;i<A.size();i++)
    {
        H.push_back(A[i]);
        maxHeap(H, i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<H[0]<<" ";
        H[0]=H[H.size()-1];
        H.pop_back();
        if(H.size()>1)
        heapsort(H, 0);
    }
}