#include<iostream>
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
//	cout<<"enter lc for "<<k<<endl;
	char ch;
	cin>>ch;
	if(ch != '.'){
		insert(T->lc,ch);
	}
//	cout<<"enter rl for "<<k<<endl;
	cin>>ch;
	if(ch != '.'){
		insert(T->rc,ch);
	}
}
int height(btptr T)
{
	if(T==NULL)
	return -1;
	else 
	return max(height(T->lc), height(T->rc))+1;
}
void preorder(btptr T){ //DLR
	if(!T) return;
	cout<<T->data<<" ";
	preorder(T->lc);
	preorder(T->rc);
}

void inorder(btptr T){ //LDR
	if(!T) return;
	inorder(T->lc);
	cout<<T->data<<" ";
	inorder(T->rc);
}
void postorder(btptr T){ //LRD
	if(!T) return;
	postorder(T->lc);
	postorder(T->rc);
	cout<<T->data<<" ";
}
void find_no_of_node(btptr T,int &ln,int &nln,int &tn){
	//ln = leaf node;
	//nln = non-leaf node;
	//tn = total node;
	if(!T) return;
	tn++;
	if(!T->lc && !T->rc) ln++;
	else nln++;
	if(T->lc) find_no_of_node(T->lc,ln,nln,tn);
	if(T->rc) find_no_of_node(T->rc,ln,nln,tn);
}
void iterative_preorder(btptr T){//DlR
	stack<btptr> S;
	S.push(T);
	while(!S.empty()){
		btptr temp = S.top();
		S.pop();
		cout<<temp->data<<" ";
		if(temp->rc){
			S.push(temp->rc);
		}
		if(temp->lc){
			S.push(temp->lc);
		}
	}
	cout<<endl;
}
void iterative_inorder(btptr T){
	stack<btptr> S;
	btptr temp = T;
	while(1){
		while(temp){
			S.push(temp);
			temp = temp->lc;
		}
		temp = S.top();
		S.pop();
		cout<<temp->data<<" ";
		temp = temp->rc;
		if(!temp && S.empty()){
			break;
		}
	}
	cout<<endl;
}
void iterative_postorder(btptr T){
	stack<btptr> S;
	btptr temp = T;
	while(1){
		while(temp){
			if(temp->rc){
				S.push(temp->rc);
			}
			S.push(temp);
			temp = temp->lc;
		}
		temp = S.top();
		S.pop();
		if(temp->rc && S.top() == temp->rc){
			S.pop();
			S.push(temp);
			temp = temp->rc;
		}
		else{
			cout<<temp->data<<" ";
			if(S.size() != 1)
				temp = NULL;
			else{
				temp = S.top();
				S.pop();
				cout<<temp->data;
				break;
			}
		}
	}
}
//AMB..DF...J.RH..K..
int main(){
	btptr T = NULL;
	char ch;
	cin>>ch;
	insert(T,ch);
	preorder(T);
	cout<<endl;
	inorder(T);
	cout<<endl;
	postorder(T);
	cout<<endl;
	int ln,nln,tn;
	ln = nln = tn = 0;
	find_no_of_node(T,ln,nln,tn);
	cout<<"non leaf node "<<nln<<endl;
	cout<<"leaf node "<<ln;
	cout<<"\ntotal node "<<tn<<endl;
	iterative_preorder(T);
	iterative_inorder(T);
	iterative_postorder(T);
}
