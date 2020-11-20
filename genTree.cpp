#include <bits/stdc++.h>
using namespace std;
typedef struct gtnode *gtptr;
struct gtnode{
	char data;
	gtptr fc;
	gtptr ns;
};
void insert(gtptr &GT,string S, int &i)
{
	if(!GT){
		GT = new gtnode;
		GT->data = S[i];
		GT->fc = NULL;
		GT->ns = NULL;
	}
    
    char k=S[i];
    i++;
    // cout<<"enter fc for "<<k<<" is "<<S[i]<<endl;
	if(S[i]!= '.'){
		insert(GT->fc, S,i);//ABC..D.E..FG.H..JK.L.MP.Q..N....
	}
    i++;
    // cout<<"enter ns for "<<k<<" is "<<S[i]<<endl;
    if(S[i]!='.')
    insert(GT->ns,S,i);
}
void printLe(queue<gtptr> Q, int &height)
{
   if(!Q.empty())
    {
        if(Q.front()->data=='0')
        {
            gtptr changeptr = Q.front();
            Q.pop();
            cout<<endl;
            height++;
            if(!Q.empty())
            Q.push(changeptr);
            printLe(Q, height);
        }
        else
        {
            gtptr temp = Q.front();
            Q.pop();
            cout<<temp->data<<" ";
            temp = temp->fc;
            while(temp!=NULL)
            {
                Q.push(temp);
                temp=temp->ns;
            }
            printLe(Q, height);
        }
    }
}
int heightFind(gtptr GT)
{
    queue<gtptr> Q;
    gtptr temp = new gtnode;
    temp->data = '0';
    temp->fc=NULL;
    temp->ns=NULL;
    Q.push(GT);
    Q.push(temp);
    int height=0;
    printLe(Q, height);
    return height;
}
int main()
{
    gtptr GT = NULL;
    string S;
    cin>>S;
    int i=0, height=0;
    insert(GT, S,i);
    queue<gtptr> Q;
    gtptr temp = new gtnode, temp2;
    temp->data = '0';
    temp->fc=NULL;
    temp->ns=NULL;
    Q.push(GT);
    Q.push(temp);
    printLe(Q, height);
    cout<<"height is "<<height-1;
}