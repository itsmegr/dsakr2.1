#include <bits/stdc++.h>
using namespace std;
typedef struct gtnode *gtptr;
struct gtnode{
	char data;
	gtptr fc;
	gtptr ns;
    int childN;
};
void insert(gtptr &GT, char data, int number)
{
	if(!GT){
		GT = new gtnode;
		GT->data = data;
		GT->fc = NULL;
		GT->ns = NULL;
        GT->childN=number;
	}//A 3 B 3 C 0 D 0 E 0 F 2 G 0 H 0 J 4 K 0 L 0 M 2 P 0 Q 0 N 0
    char ch;int child;
    gtptr tempGT=GT;
    for(int i=1;i<=number;i++)
    {
        cin>>ch;
        cin>>child;
        if(i==1)
        {
            insert(tempGT->fc,ch, child);
            tempGT=tempGT->fc;
        }
        else
        {
            insert(tempGT->ns, ch, child);
            tempGT=tempGT->ns;
        }
    }
}
void print(gtptr G)
{
    if(G!=NULL)
    {
        cout<<G->data;
        print(G->fc);
        print(G->ns);
    }
    else
    cout<<".";
}
int main()
{
    gtptr GT = NULL;
    char c;int n;
    cin>>c>>n;
    insert(GT,c,n);
    print(GT);
}