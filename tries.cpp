#include <bits/stdc++.h>
using namespace std;
typedef struct tnode *Tptr;
struct tnode
{
    bool wrd;
    struct tnode* ptr[52];
};
void insert(Tptr &T, string S, int i)
{
    if(T==NULL)
    {
        T=new(tnode);
        for(int i=0;i<51;i++)
        T->ptr[i]=NULL; 
        T->wrd = false;
    }
    if(i>=S.length())
    {
        T->wrd = true;
        return;
    }
    // if(S[i]-'a'<0)//capital letter
    // {
    //     insert(T->ptr[S[i]-'A'],S,i+1);
    // }
    // else//small letters
    // {
    //     insert(T->ptr[S[i]-'a'+26],S,i+1);
    // }
    if(S[i]-'a'<0)//intergers
    {
        insert(T->ptr[S[i]-'0'],S,i+1);
    }
    else//small letters
    {
        insert(T->ptr[S[i]-'a'+10],S,i+1);
    }
     
}
void printing_in_sorted(Tptr T, queue<char> Q)
{
    for(int i=0;i<51;i++)
    {
        if(T->ptr[i]!=NULL)
        {

            if(i<10)
            {
                cout<<char(i+48);
            }
            else
            {
                cout<<char(i+87);
            }
            printing_in_sorted(T->ptr[i],Q);
            Q.pop();
        }
    }
    if(T->wrd)
    {
        cout<<" ";
    }
}
int main()
{
    Tptr T=NULL;
    string S;
    queue<char> Q;
    for(int i=0;i<5;i++)
    {
        cin>>S;
        insert(T,S,0);
    }
    printing_in_sorted(T,Q);
}