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
void printLev(queue<mstptr> &Q, stack<int> &levQ)
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
void printStack(stack <int> &temp)
{
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
}
void printbottomUp(stack<int> lev)
{
    stack<int> temp;
    int cnt=0;
    while (!lev.empty())
    {
        if(lev.top()==-1)
        {
            printStack(temp);
            cnt++;
            lev.pop();
            continue;
        }
        if(cnt%2==1)
        {
            temp.push(lev.top());
            lev.pop();
        }
        else
        {
            cout<<lev.top()<<" ";
            lev.pop();
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
    stack<int> lev;
    Q.push(MT);
    Q.push(temp);
    lev.push(-1);
    printLev(Q, lev);
    printbottomUp(lev);


}
int main()
{
    mstptr MT = NULL;
    int n,m;
    cin>>m;
    cin>>n;
    while(n!=-0)
    {
        constructV2(MT, n);
        cin>>n;
    }
    LevelOrderPrint(MT);
}