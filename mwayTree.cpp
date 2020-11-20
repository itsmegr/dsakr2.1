#include <bits/stdc++.h>
using namespace std;
const int m=4;
typedef struct mstnode
{
    int cnt;
    int keys[m-1];
    struct mstnode *cptr[m];

} *mstptr;
int GivePosition(int A[],  int k,int max)
{
    int i;
    for(i=1;i<=max;i++) 
    {
        if(k>A[i-1]&&k<A[i])
        {
            break;
        }
    }
    return i;
}
void constructV1(mstptr &MT, int k)
{
    if(MT==NULL)
    {
        MT = new(mstnode);
        MT->cnt = 0;
        MT->keys[MT->cnt] = k;
        for(int i=0;i<m;i++)
        MT->cptr[i] = NULL;
    }
    else
    {
        if(k>MT->keys[MT->cnt]&&MT->cnt<m-2)
        MT->keys[++MT->cnt]=k;
        else if(k>MT->keys[MT->cnt]&&MT->cnt>=m-2)
        constructV1(MT->cptr[m-1], k);
        else if(k<MT->keys[0])
        constructV1(MT->cptr[0], k);
        else
        {
            constructV1(MT->cptr[GivePosition(MT->keys, k, MT->cnt)], k);
        }
    }
} 
void constructV2(mstptr &MT, int k)
{
    if(MT==NULL)
    {
        MT = new(mstnode);
        MT->cnt = 0;
        MT->keys[MT->cnt] = k;
        for(int i=0;i<m;i++)
        MT->cptr[i] = NULL;
    }
    else
    {
        if(MT->cnt<m-2)
        {
            MT->keys[++MT->cnt] =k;
            sort(MT->keys, MT->keys+(MT->cnt)+1);
        }
        else if(k>MT->keys[MT->cnt]&&MT->cnt>=m-2)
        constructV2(MT->cptr[m-1], k);
        else if(k<MT->keys[0])
        constructV2(MT->cptr[0], k);
        else
        {
            constructV2(MT->cptr[GivePosition(MT->keys, k, MT->cnt)], k);
        }
    }

}
void printPre(mstptr MT)
{
    if(MT!=NULL)
    {
        for(int i=0;i<=MT->cnt;i++)
        {
            printPre(MT->cptr[i]);
            cout<<MT->keys[i]<<" ";
        }
        printPre(MT->cptr[MT->cnt+1]);
    }
}
int main()
{
    mstptr MT1 = NULL, MT2=NULL;
    for(int i=1;i<=2;i++)
    {
        int N;
        cin>>N;
        int n;
        cin>>n;
        while(n!=0)
        {
            if(i==1)
            constructV1(MT1, n);
            else
            constructV2(MT2, n);
            cin>>n;
        }
        if(i==1)
        printPre(MT1);
        else
        printPre(MT2);
        cout<<endl;
    }
}