#include <bits/stdc++.h>
using namespace std;
int v;
struct ATDT
{
    int AT;
    int DT;
};
void addDG(int **G,int v1, int v2)
{
    G[v1][v2]=1;
}
void DFS(int **G,int u, bool visited[], struct ATDT atdtContainer[],int &time)
{
    visited[u] =true;
    atdtContainer[u].AT=time;
    time++;
    for(int i=0;i<v;i++)
    {
        if(G[u][i]==1)
        {
            if(!visited[i])
            DFS(G,i,visited, atdtContainer, time);
        }
    }
    atdtContainer[u].DT=time;
    time++;
}
int main()
{
    cin>>v>>v;
    int **G = new int*[v];
    for(int i=0;i<v;i++)
    G[i] = new int[v];

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        G[i][j]=0;
    }
    int v1, v2;
    cin>>v1>>v2;
    while(v1!=-1)
    {
        addDG(G,v1,v2);
        cin>>v1>>v2;
    }
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i]=false;

    struct ATDT atdtContainer[v];
    int time =0, cnt=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        DFS(G,i,visited, atdtContainer, time);
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<" "<<atdtContainer[i].AT<<" "<<atdtContainer[i].DT<<endl;
    }

}
//1 2 1 4 2 3 2 5 3 1 3 4 4 5 -1 -1

// 0 1 0 2 2 3 2 4 3 1 3 5 4 5 6 7 -1 -1 