#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct bstnode* bstptr;
struct bstnode{
	int data;
	bstptr lc;
	bstptr rc;
};
void insert(bstptr &T,int n){
	if(!T){
		T = new bstnode;
		T->data = n;
		T->lc = NULL;
		T->rc = NULL;
	}
	else {
		if(T->data > n){
			insert(T->lc,n);
		}
		else{
			insert(T->rc,n);
		}
	}
}
bstptr find_max(bstptr T){
	while(T && T->rc){
		T = T->rc;
	}
	return T;
}
bstptr deletion(bstptr T,int n){
	if(!T) return T;
	if(n < T->data){
		T->lc =  deletion(T->lc,n);
	}
	else if(n>T->data){
		T->rc = deletion(T->rc,n);
	}
	else{
		if(!T->lc){
			bstptr t = T->rc;
			delete(T);
			return t;
		}
		if(!T->rc){
			bstptr t = T->lc;
			delete(T);
			return t;
		}
		bstptr t = find_max(T->lc);
		T->data = t->data;
		T->lc =  deletion(T->lc,t->data);
	}
	return T;
}

void print_LDR(bstptr T){
    if(T != NULL){
        print_LDR(T->lc);
        cout<<T->data<<" ";
        print_LDR(T->rc);
    }
}
//5 8 3 4 1 9 6 7 2 -1
int main(){
	bstptr T = NULL;
	int n;
	cin>>n;
	while(n != -1){
		insert(T,n);
		cin>>n;
	}
	cin>>n;
	T =deletion(T,n);
	print_LDR(T);
}
