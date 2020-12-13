// #include <bits/stdc++.h>
// #include <vector>
// using namespace std;

// void minHeap(vector <int> &H, int i)
// {
//     if(i>0)
//     {
//         if(H[i]<H[(i-1)/4])
//         {
//             swap(H[i],H[(i-1)/4]);
//             minHeap(H, (i-1)/4);
//         }
//     }
// }

// int main()
// {
//     vector <int> A, H;
//     int n,k;
//     cin>>n;
//     while(n!=-1)
//     {
//         A.push_back(n);
//         cin>>n;
//     }
//     H.push_back(A[0]);
//     for(int i=1;i<A.size();i++)
//     {
//         H.push_back(A[i]);
//         minHeap(H, i);
//     }
//     int count=1,count2=0;;
//     for(auto it=H.begin();it!=H.end();it++)
//     {
//         cout<<*it<<" ";
//         count2++;
//         if(count2==count)
//         {
//             cout<<endl;
//             count=count*4;
//             count2=0;
//         }
//     }
// }



#include <bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;
struct btnode
{
    int data;
    struct btnode *cptrs[4] = {NULL};
    
};
btptr newnode(int k)
{
    btptr T;
    T = new btnode;
    T->data = k;
    return T;
}
void insert(btptr &T, int k, queue <btptr> all, int i, int nthchild)
{

}
void solution(btptr &T)
{

}
int main()
{
    btptr T = NULL, temp;
    int n, i=0, nthchild;
    cin>>n;
    T=newnode(n);
    vector<btptr> all;
    all.push_back(T);
    cin>>n;
    while(n!=-1)
    {
        
        insert()
    }
}