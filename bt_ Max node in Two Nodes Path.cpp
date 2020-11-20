#include<bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode{
	int data;
	btptr lc;
	btptr rc;
};
void insert(btptr &T,int k){
	if(!T){
		T = new btnode;
		T->data = k;
		T->lc = NULL;
		T->rc = NULL;
	}
	int i;
	cin>>i;
	if(i != 0){
		insert(T->lc,i);
	}
	cin>>i;
	if(i != 0){
		insert(T->rc,i);
	}
}/*
void find_path(btptr T,vector<btptr> temp,vector<btptr> &P,int n){
	if(!T) return;
	temp.push_back(T);
	if(T->data == n){
		P = temp;
	}
	if(T->lc) find_path(T->lc,temp,P,n);
	if(T->rc) find_path(T->rc,temp,P,n);
	temp.pop_back();
}
int find_max(vector<btptr> P1,vector<btptr> P2){
	btptr t;
	int max = INT_MIN;
	int l = min(P1.size(),P2.size());
	int i;
	for(i = 0;i<l;i++){
		if(P1[i] != P2[i]){
			break;
		}
	}
	for(int j = i-1;j<P1.size()-1;j++){
		t = P1[j];
		if(max<t->data){
			max = t->data;
		}
	}
	for(int j = i-1;j<P2.size()-1;j++){
		t = P2[j];
		if(max<t->data){
			max = t->data;
		}
	}
	return max;
}
void max_in_path(btptr T,int start,int end){
	int max;
	vector<btptr> P1,P2,temp;
	find_path(T,temp,P1,start);
	find_path(T,temp,P2,end);
	max = find_max(P1,P2);
	cout<<max<<endl;
}*/
void max_in_path(btptr T,int start,int end,stack<btptr> &S){
	if(!T) return;
	if(T->data == end) return;
	if(T->data == start || !S.empty()){
		cout<<"+";
		if(T->lc) max_in_path(T->lc,start,end,S);
		if(T->rc) max_in_path(T->rc,start,end,S);
		S.push(T);
		cout<<"-";
		//S.pop();
	}
	if(S.empty()){
		cout<<"0";
		if(T->lc) max_in_path(T->lc,start,end,S);
		if(T->rc) max_in_path(T->rc,start,end,S);
	}
}
//5 2 7 0 0 4 9 0 0 6 0 0 8 3 0 15 0 0 1 0 12 0 0
int main(){
	btptr T = NULL;
	int n;
	cin>>n;
	insert(T,n);
	int start;
	int end;
	int l = 3;
/*	while(l--){
		cin>>start>>end;
		max_in_path(T,start,end);
	}*/
	stack<btptr> S;
	cin>>start>>end;
	max_in_path(T,start,end,S);
	while(!S.empty()){
		cout<<"enter";
		btptr t = S.top();
		S.pop();
		cout<<t->data<<" ";
	}
}
