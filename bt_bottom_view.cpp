#include<bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode{
    btptr lc;
    char data;
    btptr rc;
};
void insert(btptr &T,char n){
	T = new btnode;
    T->data = n;
    T->lc = NULL;
    T->rc = NULL;
    char i;
    cin>>i;
    if(i != '.'){
        insert(T->lc,i);
    }
    cin>>i;
    if( i != '.'){
        insert(T->rc,i);
    }
}
void bottom(btptr T,queue<pair<int,btptr> > Q){
	if(!T) return;
	int hd;
	map<int,char> M;
	while(!Q.empty()){
		pair<int,btptr> p = Q.front();
		Q.pop();
		btptr t = p.second;
		int hd = p.first;
		M[hd] = t->data;
		if(t->lc){
			Q.push({hd-1,t->lc});
		}
		if(t->rc){
			Q.push({hd+1,t->rc});
		}
	}
	map <int,char> :: iterator i;
	for(i = M.begin();i != M.end();i++){
		cout<<i->second<<" ";
	}
}
//MTBD..ES...L..UA.N..Q..
int main(){
	btptr T = NULL;
	char ch;
	cin>>ch;
	insert(T,ch);
	queue<pair<int,btptr> >Q;
	Q.push({0,T});
	bottom(T,Q);
}
