#include <bits/stdc++.h>
using namespace std;
const int m=4;
typedef struct mstnode
{
    int cnt;
    int keys[m-1];
    struct mstnode *cptr[m];

} *mstptr;
struct retfind
{
    struct mstnode *parentPtr;
    int index;
};
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
// void constructV2(mstptr &MT, int k)
// {
//     if(MT==NULL)
//     {
//         MT = new(mstnode);
//         MT->cnt = 0;
//         MT->keys[MT->cnt] = k;
//         for(int i=0;i<m;i++)
//         MT->cptr[i] = NULL;
//     }
//     else
//     {
//         if(MT->cnt<m-2)
//         {
//             MT->keys[++MT->cnt] =k;
//             sort(MT->keys, MT->keys+(MT->cnt)+1);
//         }
//         else if(k>MT->keys[MT->cnt]&&MT->cnt>=m-2)
//         constructV2(MT->cptr[m-1], k);
//         else if(k<MT->keys[0])
//         constructV2(MT->cptr[0], k);
//         else
//         {
//             constructV2(MT->cptr[GivePosition(MT->keys, k, MT->cnt)], k);
//         }
//     }

// }
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

void printLev(queue<mstptr> &Q, queue<int> &levQ)
{
    if(!Q.empty())
    {
        if(Q.front()->keys[0]==-1)
        {
            mstptr changeptr = Q.front();
            Q.pop();
            levQ.push(-1);
            if(!Q.empty())
            Q.push(changeptr);
            printLev(Q, levQ);
        }
        else
        {
            mstptr temp = Q.front();
            Q.pop();
            for(int i=0;i<=temp->cnt;i++)
            // cout<<temp->keys[i]<<" ";
            levQ.push(temp->keys[i]);
            for(int i=0;i<m;i++)
            {
                if(temp->cptr[i]!=NULL)
                Q.push(temp->cptr[i]);
            }
             printLev(Q, levQ);
        }
    }
}
void printLeft(queue<int> levQ)
{
    int lastEle=levQ.front();
    levQ.pop();

    while(!levQ.empty())
    {
        if(lastEle==-1)
        cout<<levQ.front()<<" ";
        lastEle=levQ.front();
        levQ.pop();
    }
}
void printRight(queue<int> levQ)
{
    int be = levQ.front();
    levQ.pop();
    while (!levQ.empty())
    {
        if(levQ.front()==-1)
        {
            cout<<be<<" ";
        }
        be = levQ.front();
        levQ.pop();
    }
    
}
void LevelOrderPrint(mstptr MT)
{
    mstptr temp;
    temp = new(mstnode);
    temp->cnt = 0;
    temp->keys[temp->cnt] = -1;
    for(int i=0;i<m;i++)
    temp->cptr[i] = NULL;
    queue <mstptr> Q;
    queue<int> levQ;
    Q.push(MT);
    Q.push(temp);
    levQ.push(-1);
    printLev(Q, levQ);
    printLeft(levQ);
    cout<<endl;
    printRight(levQ);

}
int main()
{
    mstptr MT = NULL;
    int n;
    cin>>n;
    while(n!=-0)
    {
        constructV1(MT, n);
        cin>>n;
    }
    LevelOrderPrint(MT);
}