#include <bits/stdc++.h>
using namespace std;
int v;
void addDG(int **G,int v1, int v2)
{
    G[v1][v2] = 1;
}
void find_indegree(int **G, int indegree[])
{
    int indg;
    for(int i=1;i<=v;i++)
    {
        indg=0;
        for(int j=1;j<=v;j++)
        {
            if(G[j][i]==1)indg++;
        }
        indegree[i]=indg;
    }
}
int element_with_no_indegree(int indegree[], int v)
{
    int i;
    for(i=1;i<=v;i++)
    {
        if(indegree[i]==0)
        break;
    }
    return i;
}
void topological_sort(int **G, int indegree[], int cnt, int v)
{
    if(cnt>v) return;
    int s = element_with_no_indegree(indegree,v);
    indegree[s]=INT_MAX;
    for(int i=1;i<=v;i++)
    {
        if(G[s][i]==1) indegree[i]--;
    }
    cout<<char(96+1);
    topological_sort(G, indegree, cnt+1,v);
}
// 1 2 1 3 1 5 2 4 2 3 3 6 4 6 5 7 6 7 -1 -1

int main()
{
    v= 26;;
    int **G = new int*[v+1];
    for(int i=0;i<=v;i++)
    G[i] = new int[v+1];

    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
        G[i][j]=0;
    }
    string s1, s2;
    int total_strings;
    cin>>total_strings;
    while(total_strings>0)
    {
        cin>>s1>>s2;
        int i;
        for(i=0;i<min(s1.length(), s2.length());i++)
        {
            if(s1[i]!=s2[i])
            break;
        }
        addDG(G,s1[i]-'a'+1, s2[i]-'a'+1);
        total_strings--;
    }


    int indegree[v+1];
    find_indegree(G,indegree);
    topological_sort(G,indegree, 1,v);
}