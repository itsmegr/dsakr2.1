// #include <bits/stdc++.h>
// using namespace std;
// int v;
// void addDG(int **G,int v1, int v2)
// {
//     G[v1][v2] = 1;
// }
// void print(stack<int> s)
// {
//     if(!s.empty())
//     {
//         int temp = s.top();
//         s.pop();
//         print(s);
//         cout<<temp<<" ";
//     }
// }
// void cycle(int **G, int currVer, int start, stack<int> st, int &cnt)
// {
//     if(currVer==start)
//     {
//         cnt++;
//         print(st);
//         cout<<start<<" "<<endl;
//         return;
//     }
//     for(int i=1;i<=v;i++)
//     {
//         if(G[currVer][i]==1)
//         {
//             st.push(currVer);
//             cycle(G,i,start,st, cnt);
//             st.pop();
//         }
//     }
// }
// // void DFS(int **G,int u, bool visited[])
// // {
// //     visited[u] =true;
// //     // cout<<u<<" ";
// //     stack<int> st;
// //     st.push(u);
// //     // for(int i=1;i<=v;i++)
// //     // {
// //     //     if(G[u][i]==1)
// //     // }
// //     for(int i=1;i<=v;i++)
// //     {
// //         if(G[u][i]==1)
// //         {
// //             cycle(G,i,u,st);
// //             if(!visited[i])
// //             DFS(G,i,visited);
// //         }
// //     }
// // }
// int main()
// {
//     cin>>v;
//     int **G = new int*[v+1];
//     for(int i=0;i<=v;i++)
//     G[i] = new int[v+1];

//     for(int i=0;i<=v;i++)
//     {
//         for(int j=0;j<=v;j++)
//         G[i][j]=0;
//     }
//     int n;
//     cin>>n;
//     int v1, v2;
//     while(n>0)
//     {
//         cin>>v1>>v2;
//         addDG(G,v1,v2);
//         n--;
//     }
//     bool visited[v+1];
//     for(int i=0;i<=v;i++)
//     visited[i]=false;
//     // for(int i=1;i<v;i++)
//     // {
//     //     if(visited[i]==false)
//     //     DFS(G,i,visited);
//     // }
//     int cnt=0;

//     stack<int> st;
//     st.push(1);
//     for(int i=1;i<=v;i++)
//     {
//         if(G[1][i]==1)
//         cycle(G,i,1,st, cnt);
//     }
//     cout<<cnt;
// }
// 6
// 8
// 1 2
// 2 3
// 2 4
// 3 4
// 4 5
// 1 5
// 5 6
// 6 1
// // -1 -1



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
void print(stack<int> s)
{
    if(!s.empty())
    {
        int temp = s.top();
        s.pop();
        print(s);
        cout<<temp<<" ";
    }
}
//in printing only one task is remaining that is printing from the match point
//not from the satrting
void DFS_util(int **G, int currVer, int color[], stack <int> st)
{
    color[currVer] = 2;
    st.push(currVer);
    for(int i=1;i<=v;i++)
    {
        if(G[currVer][i]==0)
        continue;
        if(color[i]==2)
        {
            print(st);
            cout<<endl;
            continue;
        }
        //print the stack
        // if(color[i]==1&&DFS_util(G,i,color))
        // return true;
        DFS_util(G,i,color,st);
    }
    color[currVer]=1;
    st.pop();
    return;
}
void solution(int **G)
{
    int color[v+1];
    for(int i=1;i<=v;i++)
    color[i]=1;
    bool cycle=false;
    stack<int> st;
    // for(int i=1;i<=v;i++)
    // {
        
    //     if(color[i]==1&&cycle==false)
        DFS_util(G,1,color, st);
    // }
    // cout<<cycle;
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