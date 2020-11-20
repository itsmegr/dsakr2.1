#include <iostream>
#include <queue>
using namespace std;
typedef struct node *lptr;

struct node
{
     queue <int> *data;
     lptr next;
};
void insert(lptr &P, queue <int> *n)
{
    if(P==NULL)
    {
        lptr P;
        P = new(node);
        P->data = n, P->next = NULL;
    }
    else
    {
        lptr T, P1=P;
        T = new(node);
        T->data = n, T->next = NULL;
        while(P1->next!=NULL)
        P1 = P1->next;
        P1->next =T;
    }
}
queue <int>* getKthQueue(lptr P,int k)
{
    if(P!=NULL)
    {
        int i=1;
        while(i<k)
        {
            P=P->next;
            i++;
        }
        return P->data;
    }
    else return NULL;
}
int main()
{
    lptr LL=NULL;
    int n;
    cin>>n;
    while(n>0)
    {
       insert(LL,new queue<int>); 
    }
    int p,q;
    queue<int> *Q;
    cin>>p>>q;
    while(p>0)
    {
        Q = getKthQueue(LL,p);
        cout<<Q<<endl;
        Q->push(q);
        cin>>p>>q;
    }
    p = -1*p;
    q=-1*q;
    Q = getKthQueue(LL,p);
    Q->pop();
    Q = getKthQueue(LL,q);
    Q->pop();
    lptr P=LL;
    while(P!=NULL)
    {
        while(!P->data->empty())
        {
            cout<<P->data->front()<<" ";
            P->data->pop();
        }
        cout<<endl;
        P=P->next;
    }
}