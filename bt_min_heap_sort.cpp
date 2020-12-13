#include <bits/stdc++.h>
#include <vector>
using namespace std;

void minHeap(vector <int> &H, int i)
{
    if(i>0)
    {
        if(H[i]<H[(i-1)/2])
        {
            swap(H[i],H[(i-1)/2]);
            minHeap(H, (i-1)/2);
        }
    }
}
int mini(int i, vector <int> H)
{
    if(H[(2*i)+1]>H[(2*i)+2])
    return (2*i)+2;
    else 
    return (2*i)+1;
}
void heapsort(vector <int> &H, int i)
{
    if((2*i)+1<H.size()&&(2*i)+2<H.size())
    {
        if(!(H[i]<H[(2*i)+1]&&H[i]<H[(2*i)+2]))
        {
            int k = mini(i, H);
            swap(H[i], H[k]);
            heapsort(H, k);
        }
    }
    else if ((2*i)+1<H.size()&&(2*i)+2>=H.size())
    {
        if(H[i]>H[(2*i)+1])
        {
            swap(H[i], H[(2*i)+1]);
        }
    }
}
void arrayHeapOrNot(vector <int> H, int i, bool &heap)
{
    if((2*i)+1<H.size()&&(2*i)+2<H.size())
    {
        if(H[i]<H[(2*i)+1]&&H[i]<H[(2*i)+2])
        {
            if(heap)
            arrayHeapOrNot(H, i+1, heap);
        }
        else
        {
            heap=false;
        }
    }
    else if ((2*i)+1<H.size()&&(2*i)+2>=H.size())
    {
        if(!H[i]<H[(2*i)+1])
        heap = false;
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
    bool heap = true;
    // arrayHeapOrNot(A, 0, heap);
    cout<<heap<<endl;
    H.push_back(A[0]);
    for(int i=1;i<A.size();i++)
    {
        H.push_back(A[i]);
        minHeap(H, i);
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

