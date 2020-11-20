#include<bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode{
	char data;
	btptr lc;
	btptr rc;
};
void insert(btptr &T,char k){
	if(!T){
		T = new btnode;
		T->data = k;
		T->lc = NULL;
		T->rc = NULL;
	}
	char i;
	cin>>i;
	if(i != '#'){
		insert(T->lc,i);
	}
	cin>>i;
	if(i != '#'){
		insert(T->rc,i);
	}
}
void find_path(btptr T,vector<btptr> temp,vector<btptr> &P,char n){
	if(!T) return;
	temp.push_back(T);
	if(T->data == n){
		P = temp;
	}
	if(T->lc) find_path(T->lc,temp,P,n);
	if(T->rc) find_path(T->rc,temp,P,n);
	temp.pop_back();
}
void find_max(vector<btptr> P1,vector<btptr> P2){
	btptr t;
	int l = min(P1.size(),P2.size());
	int i;
	for(i = 0;i<l;i++){
		if(P1[i] != P2[i]){
			break;
		}
		cout<<P1[i]->data<<" ";
	}
	btptr T = P1[i-1];
}
void max_in_path(btptr T,char start,char end){
	vector<btptr> P1,P2,temp;
	find_path(T,temp,P1,start);
	find_path(T,temp,P2,end);
	find_max(P1,P2);
}
//MJQ..RS.T...PLE..F..D..
int main(){
	btptr T = NULL;
	char n;
	cin>>n;
	insert(T,n);
	char start;
	char end;
	cin>>start>>end;
	max_in_path(T,start,end);
}
