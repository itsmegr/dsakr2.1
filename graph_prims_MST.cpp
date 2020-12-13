#include<bits/stdc++.h>
using namespace std;
int v;
int giving_min_key(int key_value[])
{
    int min = INT_MAX, index= -1;
    for(int i=0;i<v;i++)
    {
        if(key_value[i]<min)
        min = key_value[i],index=i; 
    }
    return index;
}
void prim_MST(vector<vector<int>> G)
{
    int key_value[v], pre[v], curr;
    bool mst_included[v];
    for(int i=0;i<v;i++)
    key_value[i]=INT_MAX, mst_included[i]=false;
    key_value[0] = 0, pre[0] = -1;
    int count=0;
    while(count<v)
    {
        curr = giving_min_key(key_value);

        if(count!=0)
        cout<<pre[curr]<<" - "<<curr<<"   "<<key_value[curr]<<endl;

        mst_included[curr]=true;
        key_value[curr] = INT_MAX;
        for(int i=0;i<v;i++)
        {
            if(G[curr][i]!=0&&mst_included[i]==false)
            {
                if(G[curr][i]<key_value[i])
                key_value[i]=G[curr][i], pre[i]=curr;
            }
        }
        count++;
    }
}
int main(){
    v=7;
    vector<vector<int>>G;
    G ={
        {0,2,4,1,0,0,0},
        {2,0,0,3,10,0,0},
        {4,0,0,2,0,5,0},
        {1,2,2,0,7,8,4},
        {0,10,0,7,0,0,6},
        {0,0,5,8,0,0,1},
        {0,0,0,4,6,1,0}
        };  
        prim_MST(G);
}