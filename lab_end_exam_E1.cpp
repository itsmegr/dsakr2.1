#include <bits/stdc++.h>
using namespace std;
int v;
void addUG(int **G,int v1, int v2)
{
    G[v1][v2] = 1;
    G[v2][v1] =1;
}
void DFS(int **G,int u, bool visited[])
{
    visited[u] =true;
    for(int i=1;i<=v;i++)
    {
        if(G[u][i]==1)
        {
            if(!visited[i])
            DFS(G,i,visited);
        }
    }
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

    //making a complete graph

    for(int i=1;i<=v;i++)
    {
        for(int j=i+1;j<=v;j++)
        addUG(G,i,j);
    }

    int number_of_edges_update, v1, v2, number_of_connected_comp=0;
    cin>>number_of_edges_update;

    while(number_of_edges_update>0)
    {
        cin>>v1>>v2;
        G[v1][v2] = 0;
        G[v2][v1] =0;
        number_of_edges_update--;
    }

    bool visited[v+1];
    for(int i=0;i<=v;i++)
    visited[i]=false;
    for(int i=1;i<=v;i++)
    {
        if(visited[i]==false)
        {
            number_of_connected_comp++;
            DFS(G,i,visited);
        }
        
    }
    cout<<"weight of the MST is "<<number_of_connected_comp-1<<endl;
}
// 6
// 11
// 1 3
// 1 4
// 1 5
// 1 6
// 2 3
// 2 4
// 2 5
// 2 6
// 3 4
// 3 5
// 3 6