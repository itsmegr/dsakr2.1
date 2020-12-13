#include <bits/stdc++.h>
using namespace std;
typedef struct bknode *bkptr;
struct bknode
{
    string data;
    struct bknode *ptr[10];
};
void change(string s1, string s2, int l1, int l2)
{
    if(s1.length()>=s1.length())
    {

    }

    for(int i=0;i<s1.length();i++)
    {
        if(s2.find(s1[i])==-1)
        cout<<"D "<<s1[i]<<endl;
        else
        {
            cout<<"N "<<s1[i]<<" "<<s1[i]<<endl;
        } 
    }
    if(s1==s2)
    return;
    for(int i=0;i<s2.length();i++)
    {
        if(s2.find(s1[i])==-1)
        cout<<"D "<<s1[i]<<endl;
        else
        {
            cout<<"N "<<s1[i]<<" "<<s1[i]<<endl;
        } 
    }
}

int main()
{
    bkptr BK=NULL;
    int n;
    string s1,s2;
    cin>>n;
    while(n>0)
    {
        cin>>s1>>s2;
        change(s1,s2,s1.length()-1, s2.length()-1);
        n--;
    }



}