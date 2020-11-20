#include <bits/stdc++.h>
using namespace std;
typedef
struct btnode
{
	int data;
	int hd;
	btnode *lc;
	btnode *rc;
}*btptr;
void insert(btptr &T,int k,int l)
{
	if(!T)
	{
		T=new(btnode);
		T->data=k;
		//cout<<l<<", ";
		T->hd = l;
		T->lc=NULL;
		T->rc=NULL;
	}
	int n;
	cin>>n;
	if(n != 0)
		insert(T->lc,n,l-1);
	cin>>n;
	if(n != 0)
		insert(T->rc,n,l+1);
}
void vertical_sum(btptr T,map<int,int> &sum){
	if(!T) return;
	sum[T->hd] = sum[T->hd]+T->data;
	if(T->lc) vertical_sum(T->lc,sum);
	if(T->rc) vertical_sum(T->rc,sum);
}
int main(){
	btptr T = NULL;
	int n;
	cin>>n;
	insert(T,n,0);
	map<int,int> sum;
	vertical_sum(T,sum);
	map<int,int> :: iterator it;
	for(it = sum.begin();it != sum.end();it++){
		cout<<it->first<<","<<it->second<<"\t";
	}
}
