#include <bits/stdc++.h>
using namespace std;
int v;
void addDG(int **G,int v1, int v2)
{
    G[v1][v2] = 1;
}
//using color scheme to find cycle
//u = current vertex
//1 = white(Not visited), 2=grey(Processing vertex), 3= black(Completely Visited); 
bool DFS_util(int **G, int currVer, int color[])
{
    color[currVer] = 2;

    for(int i=1;i<=v;i++)
    {
        if(G[currVer][i]==0)
        continue;
        if(color[i]==2)
        return true;
        if(color[i]==1&&DFS_util(G,i,color))
        return true;
    }
    color[currVer]=3;
    return false;
}
void solution(int **G)
{
    int color[v+1];
    for(int i=1;i<=v;i++)
    color[i]=1;
    bool cycle=false;
    for(int i=1;i<=v;i++)
    {
        
        if(color[i]==1&&cycle==false)
        cycle = DFS_util(G,i,color);
    }
    cout<<cycle;
}
int main()
{
    cin>>v;
    int **G = new int*[v+1];
    for(int i=0;i<=v;i++)
    G[i] = new int[v+1];

    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
        G[i][j]=0;
    }
    int n;
    cin>>n;
    int v1, v2;
    while(n>0)
    {
        cin>>v1>>v2;
        addDG(G,v1,v2);
        n--;
    }
    solution(G);
}