#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    int data;
    struct node *next;
} * LL;
void insert(LL START)
{
    LL END,CUR;
    END=START;
    int k;
    char n,ch;

    cin>>n;
    if(n=='#')
    {
        return;
    }
    else if(n=='0')
    {
        cin>>ch;
    }
    else
    {
        cin>>k;
    }
    
    while(n!='#')
    {

        CUR=new(struct node);
        CUR->data=n-48;
        CUR->next=NULL;
        END->next=CUR;
        END=CUR;


        CUR=new(struct node);

        if(n=='0')
        {
            CUR->data=(int)ch;
        }
        else
        {
            CUR->data=k;
        }
        
        CUR->next=NULL;
        END->next=CUR;
        END=CUR;
        
        
        cin>>n;
        if(n=='#')
        {
            return;
        }
        else if(n=='0')
        {
            cin>>ch;
        }
        else
        {
            cin>>k;
        }
    }
}
void displayAll(LL S)
{
    if(S!=NULL)
    {
        
        cout<<S->data<<" ";
        displayAll(S->next);
    }
}
void deleteEnd(LL C)
{
    while(C!=NULL)
    {
        if((C->next->next)==NULL)
        {
            C->next=NULL;
            break;
        }
        C=C->next;
    }
}
struct node *createList()
{
    int n;
    LL L1;

    L1=new(struct node);
    L1->data=-1;
    L1->next=NULL;
    insert(L1);

    return L1;
}
void arrangeF(LL C)
{
    LL R=new(struct node);
    LL END,CUR;
    END=R;
    CUR=R;

    LL PER=C;

    while(C->next!=NULL)
    {
        
        if(C->data==0)
        {
            
            cout<<(char)C->next->data<<" ";
        }
        C=C->next;
    }
    C=PER;
    while(C->next!=NULL)
    {
        if(C->data==1)
        {
            cout<<C->next->data<<" ";
        }
        C=C->next;
    }
}
void removeFirst(LL (&S))
{
    S=S->next;
}
int main()
{
    
    LL C,D;
    C=createList();
    removeFirst(C);
    arrangeF(C);
}
//changes