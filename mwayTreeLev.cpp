#include <bits/stdc++.h>
using namespace std;
const int m=3;
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

void printLev(queue<mstptr> Q)
{
    if(!Q.empty())
    {
        if(Q.front()->keys[0]==-1)
        {
            mstptr changeptr = Q.front();
            Q.pop();
            cout<<endl;
            if(!Q.empty())
            Q.push(changeptr);
            printLev(Q);
        }
        else
        {
            mstptr temp = Q.front();
            Q.pop();
            for(int i=0;i<=temp->cnt;i++)
            cout<<temp->keys[i]<<" ";
            for(int i=0;i<m;i++)
            {
                if(temp->cptr[i]!=NULL)
                Q.push(temp->cptr[i]);
            }
             printLev(Q);
        }
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
    Q.push(MT);
    Q.push(temp);
    printLev(Q);
}
void finding(mstptr MT, int k, struct retfind &pos)
{
    if(MT!=NULL)
    {
        for(int i=0;i<=MT->cnt;i++)
        {
            finding(MT->cptr[i],k, pos);
            if(MT->keys[i]==k)
            {
                pos.parentPtr=MT;
                pos.index=i;
                return;
            }
        }
        finding(MT->cptr[MT->cnt+1],k, pos);
    }
}
int replacing(mstptr MT)
{
    if(MT!=NULL)
    {
        int val = MT->keys[0];
        int newVa = replacing(MT->cptr[1]);
        if(newVa==-1)
        {
            MT->keys[0] = MT->keys[1];
            MT->cnt--;
        }
        else
        {
            MT->keys[0] =newVa;
        }
        
        return val;
    }
    else return -1;
}
void deleting(mstptr MT,  int k)
{
    retfind pos;
    finding(MT, k, pos);
    int newVal = replacing(pos.parentPtr->cptr[pos.index+1]);
    pos.parentPtr->keys[pos.index]=newVal;
}
int main()
{
    mstptr MT = NULL;
    int n;
    cin>>n;
    while(n!=-1)
    {
        constructV2(MT, n);
        cin>>n;
    }
    LevelOrderPrint(MT);
    cin>>n;
    deleting(MT, n);
    cin>>n;
    deleting(MT, n);
    LevelOrderPrint(MT);
}