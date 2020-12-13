#include <bits/stdc++.h>
using namespace std;
int v;
void addUG(int **G,int v1, int v2, int v)
{
    G[v1][v2] = 1;
    G[v2][v1] =1;
}
void addDG(int **G,int v1, int v2, int v)
{
    G[v1][v2] = 1;
}
void BFT(int **G,int s, int v)
{
    int visit[v+1],cnt=0;
    for(int i=0;i<=v;i++)
    visit[i]=0;
    queue<int> st;
    st.push(s);
    cnt++;
    visit[s]=1;
    while(!st.empty())
    {
        int temp = st.front();
        cout<<temp<<" ";
        st.pop();
        for(int i=1;i<=v;i++)
        {
            if(G[temp][i]==1)
            {
                if(visit[i]==0)
                {
                    cnt++;
                    st.push(i);
                    visit[i]=1;
                }
            }
        }
        if(st.empty()&&cnt<v)
        {
            for(int i=1;i<=v;i++)
            {
                if(visit[i]==0)
                {
                    visit[i]=1;
                   st.push(i);
                   break;
                }
            }
        }   
    }
}
void DFS(int **G,int u, bool visited[])
{
    visited[u] =true;
    cout<<u<<" ";
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




    int v1, v2;
    cin>>v1>>v2;
    // while(v1>0)
    // {
    //     addUG(G,v1,v2,v);
    //     cin>>v1>>v2;
    // }
    while(v1>0)
    {
        addDG(G,v1,v2,v);
        cin>>v1>>v2;
    }


    // for(int i=1;i<=v;i++)
    // {
    //     BFT(G,i,v);
    //     cout<<endl;
    // }
    bool visited[v+1];
    for(int i=0;i<=v;i++)
    visited[i]=false;
    for(int i=1;i<=v;i++)
    {
        DFS(G,i,visited);
        for(int i=0;i<=v;i++)
        visited[i]=false;
        cout<<endl;
    }
}
//1 2 1 4 2 3 2 5 3 1 3 4 4 5 directed
//1 2 1 3 1 4 2 3 2 5 3 4 4 5 undirected