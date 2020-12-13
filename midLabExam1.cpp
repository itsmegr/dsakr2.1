
// using namespace std;
// typedef struct gtnode *gtptr;
// struct gtnode{
// 	char data;
// 	gtptr fc;
// 	gtptr ns;
// };
// void insert(gtptr &GT,string S, int &i)
// {
// 	if(!GT){
// 		GT = new gtnode;
// 		GT->data = S[i];
// 		GT->fc = NULL;
// 		GT->ns = NULL;
// 	}
    
//     char k=S[i];
//     i++;
//     // cout<<"enter fc for "<<k<<" is "<<S[i]<<endl;
// 	if(S[i]!= '.'){
// 		insert(GT->fc, S,i);//ABC..D.E..FG.H..JK.L.MP.Q..N....
// 	}
//     i++;
//     // cout<<"enter ns for "<<k<<" is "<<S[i]<<endl;
//     if(S[i]!='.')
//     insert(GT->ns,S,i);
// }
// void printLe(queue<gtptr> Q, int &height)
// {
//    if(!Q.empty())
//     {
//         if(Q.front()->data=='0')
//         {
//             gtptr changeptr = Q.front();
//             Q.pop();
//             cout<<endl;
//             height++;
//             if(!Q.empty())
//             Q.push(changeptr);
//             printLe(Q, height);
//         }
//         else
//         {
//             gtptr temp = Q.front();
//             Q.pop();
//             cout<<temp->data<<" ";
//             temp = temp->fc;
//             while(temp!=NULL)
//             {
//                 Q.push(temp);
//                 temp=temp->ns;
//             }
//             printLe(Q, height);
//         }
//     }
// }
// void printBottom(gtptr GT, string &lrbnodes)
// {
//     if(GT!=NULL)
//     {
//         if(GT->fc==NULL)
//         {
//            if(lrbnodes.find(GT->data)==-1) lrbnodes=lrbnodes+GT->data;
//            cout<<GT->data<<" ";
//         }
//         printBottom(GT->fc, lrbnodes);
//         printBottom(GT->ns, lrbnodes);
//     }
// }
// void printleft(gtptr GT, string &lrbnodes)
// {
//     if(GT!=NULL)
//     {
//         if(GT->fc!=NULL)
//         {
//             if(lrbnodes.find(GT->data)==-1) lrbnodes=lrbnodes+GT->data;
//             cout<<GT->data<<" ";
//         }
//         printleft(GT->fc, lrbnodes);
//     }
// }
// void printright(gtptr GT, string &lrbnodes)
// {
//     if(GT!=NULL)
//     {
//         if(GT->ns==NULL&&GT->fc!=NULL)
//         {
//             if(lrbnodes.find(GT->data)==-1) lrbnodes=lrbnodes+GT->data;
//            cout<<GT->data<<" ";
//         }
//         printright(GT->fc, lrbnodes);
//         printright(GT->ns, lrbnodes);
//     }
// }
// void traverse(gtptr GT,string &lrbnodes)
// {
//     if(GT!=NULL)
//     {
//         if(lrbnodes.find(GT->data)==-1) cout<<GT->data<<" ";
//         traverse(GT->fc, lrbnodes);
//         traverse(GT->ns, lrbnodes);
//     }
// }
// int heightFind(gtptr GT)
// {
//     queue<gtptr> Q;
//     gtptr temp = new gtnode;
//     temp->data = '0';
//     temp->fc=NULL;
//     temp->ns=NULL;
//     Q.push(GT);
//     Q.push(temp);
//     int height=0;
//     printLe(Q, height);
//     return height;
// }
// int main()
// {
//     gtptr GT = NULL;
//     string S;
//     cin>>S;
//     int i=0, height=0;
//     insert(GT, S,i);
//     queue<gtptr> Q;
//     gtptr temp = new gtnode, temp2;
//     temp->data = '0';
//     temp->fc=NULL;
//     temp->ns=NULL;
//     Q.push(GT);
//     Q.push(temp);
//     printLe(Q, height);
//     //from here
//     string lrbnodes;
//     cout<<"bottom is ";
//     printBottom(GT, lrbnodes);
//     cout<<endl;
//     cout<<"right is ";
//     printright(GT,lrbnodes);
//     cout<<endl;
//         cout<<"left is ";
//     printleft(GT,lrbnodes);
//     cout<<endl<<lrbnodes<<endl;
//     cout<<"hidden view is ";
//     traverse(GT, lrbnodes);
// }

















#include <bits/stdc++.h>
using namespace std;
typedef struct gtnode *gtptr;
struct gtnode{
	char data;
	gtptr fc;
	gtptr ns;
};
void insert(gtptr &GT,string S, int &i)
{
	if(!GT){
		GT = new gtnode;
		GT->data = S[i];
		GT->fc = NULL;
		GT->ns = NULL;
	}
    
    char k=S[i];
    i++;
    // cout<<"enter fc for "<<k<<" is "<<S[i]<<endl;
	if(S[i]!= '.'){
		insert(GT->fc, S,i);//ABC..D.E..FG.H..JK.L.MP.Q..N....
	}
    i++;
    // cout<<"enter ns for "<<k<<" is "<<S[i]<<endl;
    if(S[i]!='.')
    insert(GT->ns,S,i);
}
void printBottom(gtptr GT, string &lrbnodes)
{
    if(GT!=NULL)
    {
        if(GT->fc==NULL)
        {
           if(lrbnodes.find(GT->data)==-1) lrbnodes=lrbnodes+GT->data;
        }
        printBottom(GT->fc, lrbnodes);
        printBottom(GT->ns, lrbnodes);
    }
}
void printleft(gtptr GT, string &lrbnodes)
{
    if(GT!=NULL)
    {
        if(GT->fc!=NULL)
        {
            if(lrbnodes.find(GT->data)==-1) lrbnodes=lrbnodes+GT->data;
        }
        printleft(GT->fc, lrbnodes);
    }
}
void printright(gtptr GT, string &lrbnodes)
{
    if(GT!=NULL)
    {
        if(GT->ns==NULL&&GT->fc!=NULL)
        {
            if(lrbnodes.find(GT->data)==-1) lrbnodes=lrbnodes+GT->data;
        }
        printright(GT->fc, lrbnodes);
        printright(GT->ns, lrbnodes);
    }
}
void traverse(gtptr GT,string &lrbnodes)
{
    if(GT!=NULL)
    {
        if(lrbnodes.find(GT->data)==-1) cout<<GT->data<<" ";
        traverse(GT->fc, lrbnodes);
        traverse(GT->ns, lrbnodes);
    }
}

int main()
{
    gtptr GT = NULL;
    string S;
    cin>>S;
    int i=0, height=0;
    insert(GT, S,i);
    //from here
    string lrbnodes;

    printBottom(GT, lrbnodes);

    printright(GT,lrbnodes);

    printleft(GT,lrbnodes);

    traverse(GT, lrbnodes);
}