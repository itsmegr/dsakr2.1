#include<bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode{
	char data;
	btptr lc;
	btptr rc;
};/*
btptr create_BT(string s,int i){
	btptr T = new btnode;
	queue<btptr> Q;
	T->data=s[i];
    T->lc=NULL;
    T->rc=NULL;
    btptr T1=T;
    Q.push(T);
    i++;
    while(s[i]!='$')
    {
        T=Q.front();
        Q.pop();
        if(s[i]!='#')
        {
            T->lc=new(btnode);
            T->lc->data=s[i];
            T->lc->lc=NULL;
            T->lc->rc=NULL;
            Q.push(T->lc);
        }
        else
            T->lc=NULL;
        i++;
        if(s[i]=='$')
            break;
        if(s[i]!='#')
        {
            T->rc=new(btnode);
            T->rc->data=s[i];
            T->rc->lc=NULL;
            T->rc->rc=NULL;
            Q.push(T->rc);
        }
        else
            T->rc==NULL;
        i++;
    }
    return T1;
}
*/

void insert(btptr &T,char n){
	T = new btnode;
    T->data = n;
    T->lc = NULL;
    T->rc = NULL;
    char i;
    cin>>i;
    if(i != '#'){
        insert(T->lc,i);
    }
    cin>>i;
    if( i != '#'){
        insert(T->rc,i);
    }
}
void push_left(btptr T,queue<btptr> &Q){
	if(!T) return;
	if(T->lc){
		T = T->lc;
		if(T->rc && T->lc){
			Q.push(T->rc);
		}
		push_left(T,Q);
	}
}
void push_right(btptr T,queue<btptr> &Q){
	if(!T) return;
	if(T->rc){
		T = T->rc;
		if(T->lc && T->rc){
			Q.push(T->lc);
		}
		push_right(T,Q);
	}
}
void print_node(queue<btptr> Q){
	if(Q.empty()) return;
	btptr T=Q.front();
    Q.pop();
    if(T->lc||T->rc)
        cout<<T->data<<" ";
    if(T->rc)
        Q.push(T->rc);
    if(T->lc)
        Q.push(T->lc);
    print_node(Q);
}
void hidden_nodes(btptr T)
{
    queue<btptr> Q;
    push_left(T,Q);
    push_right(T,Q);
    print_node(Q);
}
int main(){
	char ch;
	cin>>ch;
	btptr T = new btnode;
	insert(T,ch);
	hidden_nodes(T);
}

