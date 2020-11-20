#include<bits/stdc++.h>
using namespace std;
//Huffmann's coding tree
typedef struct hfnode *hfptr;
struct hfnode{
	hfptr lc;
	pair<char,int> data;
	hfptr rc;
};
bool comp(hfptr h1,hfptr h2){
	if(h1->data.second<=h2->data.second){
		return 1;
	}
	else{
		return 0;
	}
}
void create_huffmann(vector<hfptr> &v){
	char ch = 'A';
	while(v.size() != 1){
		hfptr h1,h2,H;
		h1 = h2 = H = new hfnode;
		int i = 0;
		int min;
		sort(v.begin(),v.end(),comp);
		h1 = v[0];
		h2 = v[1];
		H->data = make_pair(ch,h1->data.second+h2->data.second);
		H->lc = h2;
		H->rc = h1;
		vector<hfptr> :: iterator it;
		it = v.begin();
		v.erase(it);
		it = v.begin();
		v.erase(it);
		v.push_back(H);
		ch++; 
	}
}
void huffmann(hfptr H,char ch,string sh,string &str){
	if(!H) return;
	if(H->data.first == ch){
		str += sh;
		return;
	}
	if(H->lc) huffmann(H->lc,ch,sh+'0',str);
	if(H->rc) huffmann(H->rc,ch,sh+'1',str);
}
void find_huffmann_code(hfptr H,string s,string &str){
	static int i = 0;
	if(i == s.size()) return;
	char ch = s[i];
	string sh = "";
	huffmann(H,ch,sh,str);
	i++;
	find_huffmann_code(H,s,str);
}
void huffmann_code(hfptr H,hfptr T,string str,string &s,int &i){
	if(!T) return;
	if(!T->lc && !T->rc){
		s += T->data.first;
		i+1;
		huffmann_code(H,H,str,s,i);
	}
	if(str[i] == '0'){
		i++;
		if(T->lc) huffmann_code(H,T->lc,str,s,i);
	}
	if(str[i] == '1'){
		i++;
		if(T->rc) huffmann_code(H,T->rc,str,s,i);
	}
}
void find_code(hfptr H,string str,string &s){
	static int i = 0;
	if(i >= str.size()) return;
	hfptr T = H;
	huffmann_code(H,T,str,s,i);
}
// a 10 e 15 i 12 s 3 t 4 p 13 n 1
int main(){
	vector<hfptr> v;
	hfptr H = new hfnode;
	int l = 7;
	int n;
	char ch;
	while(l--){
		cin>>ch>>n;
		H = new hfnode;
		H->data = make_pair(ch,n);
		H->lc = NULL;
		H->rc = NULL;
		v.push_back(H);
	}
	create_huffmann(v);
	H = v[0];
	string s,str = "";
	cin>>s;
	find_huffmann_code(H,s,str);
	cout<<str<<endl;
	s = "";
	find_code(H,str,s);
	cout<<s;
}