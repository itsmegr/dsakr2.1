// #include <bits/stdc++.h>
// using namespace std;
// typedef struct gtnode *gtptr;
// struct gtnode{
// 	char data;
// 	gtptr fc;
// 	gtptr ns;
//     bool hasInfo;
// };
// void insert(gtptr &GT,string S, int &i)
// {
// 	if(!GT){
// 		GT = new gtnode;
// 		GT->data = S[i];
// 		GT->fc = NULL;
// 		GT->ns = NULL;
//         GT->hasInfo=false;
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
// int heightFind(gtptr GT)
// {
//     int h=0;
//     while(GT->fc!=NULL)
//     {
//         GT=GT->fc;
//         h++;
//     }
//     return h;
// }
// int genTreeToNode(string S)
// {
//     int n=0;
//     for(int i=0;i<S.length();i++)
//     {
//         if(S[i]!='.')
//         n++;
//     }
//     return n;
// }
// gtptr childWithMaxHeight(gtptr G, vector <gtptr> infoContaoner)
// {
//     int maxH=-1;
//     gtptr child=NULL;
//     while(G!=NULL)
//     {
//         if(G->hasInfo==false)
//         {
//             int hegt = heightFind(G);
//             if(maxH<hegt)
//             {
//                 child = G;
//                 maxH = hegt;
//             }
//         }
//         G=G->ns;
//     }
//     return child;
// }
// int main()
// {
//     gtptr GT = NULL;
//     string S;
//     cin>>S;      
//     int i=0, height=0, totalIte=0;
//     insert(GT, S,i);
//     int totalNodes = genTreeToNode(S);
//     GT->hasInfo=true;
//     //vector contains all the nodes having information
//     vector <gtptr> infoContainer; stack<gtptr> tempToStore;
//     infoContainer.push_back(GT);
//     while(true)
//     {
//         if(infoContainer.size()<totalNodes)
//         {
//             for (auto i = infoContainer.begin(); i != infoContainer.end(); ++i) 
//             {
//                 gtptr ele = *i;
//                 gtptr infoPassedToChild = childWithMaxHeight(ele->fc,infoContainer);
//                 if(infoPassedToChild!=NULL)
//                 {
//                     infoPassedToChild->hasInfo=true;
//                     tempToStore.push(infoPassedToChild);
//                 }
//             }
//             while(!tempToStore.empty())
//             {
//                 infoContainer.push_back(tempToStore.top());
//                 tempToStore.pop();
//             }
//             totalIte++;
//         }
//         else break;
        
//     }
//     cout<<totalIte;
// }
























#include <bits/stdc++.h>
using namespace std;
#define null NULL
typedef struct gtnode *gtptr;
struct gtnode
{
    char data;
    int click;
    int no_of_child;
    gtptr fc;
    gtptr ns;
};

void insert(gtptr &GT, char ch)
{
    if (!GT)
    {
        GT = new gtnode;
        GT->data = ch;
        GT->no_of_child = 0;
        GT->fc = null;
        GT->ns = null;
    }
    char k;
    cin >> k;
    if (k != '.')
    {
        insert(GT->fc, k);
    }
    cin >> k;
    if (k != '.')
    {
        insert(GT->ns, k);
    }
}
int flow_tree(gtptr GT)
{
    if (!GT->fc)
        return 0;

    int A[10];
    int n = 0, m = INT_MIN;
    gtptr T = GT->fc;
    while (T)
    {
        A[n++] = flow_tree(T);
        T = T->ns;
    }
    for(int i = 0;i<n;i++){
    	cout<<A[i]<<" ";
	}
	cout<<endl;
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        A[i] += n - i;
        m = max(m, A[i]);
    }
    return m;
}
int main()
{
    gtptr GT = new gtnode;
    GT = null;
    char ch;
    cin >> ch;
    insert(GT, ch);
    cout << flow_tree(GT);
}