#include <iostream>
#include <string>
using namespace std;
typedef struct node *lptr;
typedef struct node2 *LLlptr;

struct node
{
    string data;
     lptr next;
};
struct node2{
    lptr dlink;
    struct node2 *nextLL;
};
lptr create()
{
    lptr L = NULL;
    string str;
    cin>>str;
    while(str!="#-1")
    {
        lptr T, P = L;
        T = new(node);
        T->data = str;
        T->next = NULL;
        if(L==NULL)
        {
            L = T;
        }
        else
        {
            while(P->next!=NULL)
            P = P->next;
            P->next = T;
        }
        cin>>str;
    }
    return L;
}
void print(LLlptr ML)
{
    lptr P;
    while(ML!=NULL)
    {
        P = ML->dlink;
        while(P!=NULL)
        {
            cout<<P->data<<" ";
            P = P->next;
        }
        ML = ML->nextLL;
    }
}
void createMLL()
{
    int i=1;
    LLlptr ML = NULL, Temp;
    lptr T;
    T = create();
    Temp = new(node2);
    Temp ->dlink = T;
    Temp->nextLL = NULL;
    ML = Temp;
    T = create();
    Temp = new(node2);
    Temp ->dlink = T;
    Temp->nextLL = NULL;
    ML->nextLL = Temp;
     T = create();
    Temp = new(node2);
    Temp ->dlink = T;
    Temp->nextLL = NULL;
    ML->nextLL->nextLL = Temp;
    print(ML);

}
int main()
{
    createMLL();
}

