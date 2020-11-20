#include <bits/stdc++.h>
using namespace std;

void construct(set<char> *S, string A, int l, int h, int i)
{
    if(l==h)
    {
        S[i].insert(A[l]);
        return;
    }
    int mid = (l+h)/2;
    construct(S, A, l, mid, 2*i+1);
    construct(S, A, mid+1, h, 2*i+2);
    S[i].insert(S[2*i+1].begin(), S[2*i+1].end());
    S[i].insert(S[2*i+2].begin(), S[2*i+2].end());

}
void Distinct(set<char> *S,  set<char> &finSet, int l, int h, int sl, int sh, int i)
{
    if(l>=sl&&h<=sh)
    {
        finSet.insert(S[i].begin(), S[i].end());
    }
    else if(h<sl||l>sh)
    {
        
    }
    else
    {
        int mid = (l+h)/2;
        Distinct(S, finSet, l, mid, sl, sh, 2*i+1);
        Distinct(S, finSet, mid+1, h, sl, sh, 2*i+2);
    }  
}
void update(set<char>*S, int chanIn, char newCh, int l, int h, int i)
{
    if(chanIn>=l&&chanIn<=h)
    {
        if(chanIn==l&&chanIn==h)
        {
            S[i].clear();
            S[i].insert(newCh);
        }
        if(l<h)
        {
            int mid = (l+h)/2;
            update(S, chanIn, newCh,l, mid, 2*i+1);
            update(S, chanIn, newCh, mid+1, h, 2*i+2);
            S[i].clear();
            S[i].insert(S[2*i+1].begin(), S[2*i+1].end());
            S[i].insert(S[2*i+2].begin(), S[2*i+2].end());
        }
    }
}
int main()
{
    string A;
    cin>>A;
    A.erase(A.length()-1, 1);
    int i=0,x;

    int  n = A.length();
    //find the size of segment tree
    x = int(ceil(log2(n)));

    //find the max size of segment array
    int max_size = 2*(int(pow(2,x)))-1;
    set<char> *S = new set<char>[max_size];
    construct(S,A,0,n-1,0);
    set<char> finSe;
    int test, par1,par2, par3i;
    char par3c;
    cin>>test;
    while(test>0)
    {
        cin>>par1;
        switch (par1)
        {
        case 1:
            cin>>par2>>par3c;
            A[par2]=par3c;
            update(S, par2, par3c, 0, n-1,0);
            break;
        case 2:
            cin>>par2>>par3i;
            Distinct(S,finSe,0,n-1,par2,par3i,0);
            cout<<finSe.size()<<endl;;
            finSe.clear();
            break;
        
        default:
            break;
        }
        test--;
    }

}