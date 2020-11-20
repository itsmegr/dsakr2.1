#include <bits/stdc++.h>
using namespace std;
typedef
struct btnode
{
	int data;
	btnode *lc;
	btnode *rc;
}*btptr;
void insert(btptr &T,int k)
{
	if(!T)
	{
		T=new(btnode);
		T->data=k;
		T->lc=NULL;
		T->rc=NULL;
	}
	int n;
	cin>>n;
	if(n != 0)
		insert(T->lc,n);
	cin>>n;
	if(n != 0)
		insert(T->rc,n);
}
bool isComplete(btptr T) 
{ 
    if (T == NULL) 
        return true; 
    queue<btptr> Q; 
    Q.push(T); 
    bool f = false;
    while(!Q.empty()) 
    { 
        btptr temp = Q.front(); 
        Q.pop(); 
        if(temp->lc) 
        { 
    	    if (f == true){
        	    return false;
			}
	        Q.push(temp->lc);
        } 
        else{  
        	f = true; 
        }
        if(temp->rc) 
        { 
        	if(f == true) {
            	return false;
			}
  			Q.push(temp->rc);  
        } 
        else{
        	f = true; 
    	}
    } 
    return true;
} 
void isHeap(btptr T,bool &f,int min){
	if(!T) return;
	if(T->data < min){
		f = false;
	}
	isHeap(T->lc,f,T->data+1);
	isHeap(T->rc,f,T->data+1);
}
//1 2 3 21 0 0 5 0 0 10 0 0 7 8 0 0 18 0 0
int main(){
	btptr T = NULL;
	int n;
	cin>>n;
	insert(T,n);
	bool f = true;
	int min = INT_MIN;
	if(isComplete(T)){
		isHeap(T,f,min);
		if(f){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
}

