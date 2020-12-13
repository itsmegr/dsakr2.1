#include <bits/stdc++.h>
using namespace std;
typedef struct bknode *bkptr;
struct bknode
{
    string data;
    struct bknode *ptr[10];
};
int min(int a, int b, int c)
{
    int min = INT_MAX;
    min = a<min ?a:min;
    min = b<min ?b:min;
    min = c<min ?c:min;
    return min;
}
int distance1(string s1, string s2)
{
    int m= s1.length(), n=s2.length();
    int A[m+1][n+1];
    for(int i=0;i<=n;i++)
    A[0][i]=i;
    for(int i=0;i<=m;i++)
    A[i][0]=i;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            A[i][j]=A[i-1][j-1];
            else
            A[i][j]=min(A[i-1][j],A[i][j-1],A[i-1][j-1])+1;
        }
    }
    return A[m][n];
}
void construct(bkptr &T, string s)
{
    if(T==NULL)
    {
        T = new(bknode);
        T->data = s;
        for(int i=0;i<10;i++)
        T->ptr[i]=NULL;
        return;
    }
    int n = distance1(T->data, s);
    construct(T->ptr[n],s);
}
void print(bkptr T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        for(int i=0;i<10;i++)
        print(T->ptr[i]);
    }
}
void finding(bkptr T, string wrd, int N)
{
    int D = distance1(T->data, wrd);
    int l = D-N, h = D+N, ParentchildDist, wrdChildDis;
    for(int i=0;i<10;i++)
    {
        if(T->ptr[i]!=NULL)
        {
            ParentchildDist = distance1(T->data, T->ptr[i]->data);
            if(ParentchildDist>=l&&ParentchildDist<=h)
            {
               wrdChildDis =  distance1(T->ptr[i]->data, wrd);
               if(wrdChildDis<=N) 
               {
                   cout<<wrdChildDis<<" "<<T->ptr[i]->data<<" ";
               }
            }
        finding(T->ptr[i], wrd, N);
        }
    }
}
int main()
{
    bkptr BK=NULL;
    string s;
    cin>>s;
    while(s!="#")
    {
        construct(BK, s);
        cin>>s;
    }
    // print(BK);
    string wrd;
    int N, distFromRoot;
    cin>>wrd>>N;
    distFromRoot = distance1(BK->data, wrd);
    if(distFromRoot<=N)
    {
        cout<<distFromRoot<<" "<<BK->data<<" ";
    }

    finding(BK,wrd, N);

}