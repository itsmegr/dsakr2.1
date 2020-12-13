#include <bits/stdc++.h>
using namespace std;
int v;
void addDG(int **G,int v1, int v2, int weight)
{
    G[v1][v2] = weight;
}
void shorted_distance(int **G, int curr, bool visited[], int distance[], int pre_ver[], int g)
{
    int newdist;
    if(curr==g) return;
    //updateing all its unvisited adjacent vertex;
    for(int i=1;i<=v;i++)
    {
        if(G[curr][i]>0)
        {
            if(visited[i]==false)
            {
                newdist = distance[curr]+G[curr][i];
                if(newdist<distance[i])
                {
                    distance[i]=newdist;
                    pre_ver[i]=curr;
                }
            }
        }
    }
    // cout<<curr<<" and distance ";
    distance[curr]=INT_MAX;
    visited[curr]=true;
    int new_curr, min = INT_MAX;
    //finding the unvisited vertex with min distance
    for(int i=0;i<=v;i++)
    {
        if(visited[i]==false)
        {
            if(distance[i]<min)
            {
                min = distance[i];
                new_curr=i;
            }
        }
    }
    shorted_distance(G,new_curr,visited, distance, pre_ver,g);
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
    int v1, v2, weight;
    cin>>v1>>v2>>weight;
    while(v1>0)
    {
        addDG(G,v1,v2, weight);
        cin>>v1>>v2>>weight;
    }
    bool visited[v+1];
    int distance[v+1], pre_ver[v+1];
    for(int i=0;i<=v;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
        pre_ver[i] = -1;
    }
    int s,g, curr;
    cin>>s>>g;
    curr = s;
    visited[s]=true;
    distance[s]=0;
    pre_ver[s]=s;
    shorted_distance(G,curr,visited, distance,pre_ver,g);
    // 1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 3 2 4 5 2 4 6 8 4 7 4 5 7 6 7 6 1 -1 -1 -1
    //printing answer
    int temp=pre_ver[g];
    stack<int> path;
    path.push(g);
    while(temp!=s)
    {
        path.push(temp);
        temp = pre_ver[temp];
    }
    path.push(s);
    while(!path.empty())
    {
        cout<<path.top()<<" ";
        path.pop();
    }

}