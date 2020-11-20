#include <bits/stdc++.h>
using namespace std;
struct node{
    int fora1;
    int fora2;
};
struct node consSTcommonlyCheck(int i, int l, int h, struct node *S, int A1[], int A2[])
{
    if(l==h)
    {
        S[i].fora1 = A1[l];
        S[i].fora2 = A2[l];
        return S[i];
    }
    else
    {
        int mid = (l+h)/2;
        struct node t1, t2;
        t1 = consSTcommonlyCheck(2*i+1, l, mid, S, A1, A2);
        t2 = consSTcommonlyCheck(2*i+2, mid+1, h, S, A1, A2);
        S[i].fora1 = min(t1.fora1, t2.fora1);
        S[i].fora2 = min(t1.fora2, t2.fora2);
        return S[i];
    }
}
void comapreWithOther(struct node *S, int l1, int h1, int l2, int h2, int i1, int i2)
{
    if(l2 == h1+1)
    {
       if(min(S[i1].fora1, S[i2].fora1)==min(S[i1].fora2, S[i2].fora2))
       cout<<l1<<" "<<h2<<endl;
    }
    if(l2<h2)
    {
        int mid = (l2+h2)/2;
        comapreWithOther(S, l1, h1, l2,mid, i1, 2*i2+1);
        comapreWithOther(S, l1, h1, mid+1,h2, i1, 2*i2+2);
    }
}
void commonlyCheck(struct node *S, int l, int h, int i,int n)
{
    if(l<h)
    {
        comapreWithOther(S,l,h,0,n-1,i,0);
        int mid = (l+h)/2;
        commonlyCheck(S,l,mid,2*i+1,n);
        commonlyCheck(S,mid+1, h, 2*i+2,n);
    }
    if(l==h)
    {
       comapreWithOther(S,l,h,0,n-1,i,0); 
    }
}
int main()
{
    int n1,n2,i,x;
    cin>>n1;
    i=0;
    int A1[n1];
    while(i<n1)
    {
        cin>>A1[i];
        i++;
    }
    cin>>n2;
    i=0;
    int A2[n2];
    while(i<n2)
    {
        cin>>A2[i];
        i++;
    }
    //find the size of segment tree
    x = int(ceil(log2(n1)));

    //find the max size of segment array
    int max_size = 2*(int(pow(2,x)))-1;
    struct node *S = new node[max_size];
    consSTcommonlyCheck(0,0,n1-1,S,A1,A2);
    commonlyCheck(S,0,n1-1,0,n1);
}