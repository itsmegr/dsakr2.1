// // #include <bits/stdc++.h>
// // using namespace std;
// // const int d=3;
// // typedef struct btrnode
// // {
// //     int cnt = -1;
// //     int keys[d-1];
// //     struct btrnode *cptr[d];

// // } *btrptr;
// // typedef struct overFlowNode
// // {
// //     int cnt;
// //     int keys[d];
// //     struct btrnode *cptr[d+1];

// // } *overptr;
// // btrptr BTree=NULL;
// // bool leafNodeOrNot(btrptr BT)
// // {
// //     for(int i=0;i<d;i++)
// //     {
// //         if(BT->cptr[i]!=NULL)
// //         {
// //             return false;     
// //         }
// //     }
// //     return true;
// // }
// // //function to find appopriate position in node
// // int GivePositionToFindLeafNode(int A[],  int k, int max)
// // {
// //     int i;
// //     for(i=1;i<=max;i++) 
// //     {
// //         if(k>A[i-1]&&k<A[i])
// //         {
// //             break;
// //         }
// //     }
// //     return i;
// // }
// // //function to give the position node
// // btrptr checkingNodePosition(btrptr BT, int k)
// // {
// //     if(leafNodeOrNot(BT))
// //     {
// //         return BT;
// //     }
// //     else
// //     {
// //         if(k<BT->keys[0])
// //         {
// //             return checkingNodePosition(BT->cptr[0], k);
// //         }
// //         else if(k>BT->keys[BT->cnt])
// //         {
// //             return checkingNodePosition(BT->cptr[d-1], k);
// //         }
// //         else
// //         {
// //             int i=GivePositionToFindLeafNode(BT->keys,k, BT->cnt);
// //             return checkingNodePosition(BT->cptr[i],k);
// //         }
        
// //     }
    
// // }
// // void adjustPointers(btrptr temp, int k)
// // {
// //     int i;
// //     //finding new position of k
// //     for(i=0;i<=temp->cnt;i++)
// //     {
// //         if(temp->keys[i]==k)
// //         break;
// //     }
// //     if(i==0)
// //     {
// //         for(int j=temp->cnt+1;j>0;j--)
// //         temp->cptr[j]=temp->cptr[j-1];

// //         temp->cptr[0]=NULL;
// //     }
// //     else if(i==temp->cnt)
// //     {
// //         temp->cptr[temp->cnt+1]=NULL;
// //     }
// //     else
// //     {
// //         for(int j=temp->cnt+1;j>i+1;j--)
// //         {
// //             temp->cptr[j]=temp->cptr[j-1];
// //         }
// //         temp->cptr[i+1]=NULL;
// //     }
    
// // }
// // void adjustPointersInOverflowNode(overptr temp, int k)
// // {
// //     int i;
// //     //finding new position of k
// //     for(i=0;i<=temp->cnt;i++)
// //     {
// //         if(temp->keys[i]==k)
// //         break;
// //     }
// //     if(i==0)
// //     {
// //         for(int j=temp->cnt+1;j>0;j--)
// //         temp->cptr[j]=temp->cptr[j-1];

// //         temp->cptr[0]=NULL;
// //     }
// //     else if(i==temp->cnt)
// //     {
// //         temp->cptr[temp->cnt+1]=NULL;
// //     }
// //     else
// //     {
// //         for(int j=temp->cnt+1;j>i+1;j--)
// //         {
// //             temp->cptr[j]=temp->cptr[j-1];
// //         }
// //         temp->cptr[i+1]=NULL;
// //     }
    
// // }
// // void ParentNodeFind(btrptr MT, btrptr &ParentNode, btrptr temp)
// // {
// //     if(MT!=NULL)
// //     {
// //         if(MT==temp) return; 
// //         for(int i=0;i<=MT->cnt+1;i++)
// //         {
// //             if(MT->cptr[i]==temp) ParentNode = MT;
// //             ParentNodeFind(MT->cptr[i], ParentNode, temp);
// //         }
// //     }
// // }
// // //function to construct BTree
// // void constructBTree(btrptr &BT, int k, bool &firstTime)
// // {
// //     btrptr temp=NULL, parentNode=NULL;
// //     if(BT==NULL)
// //     {
// //         BT = new(btrnode);
// //         BT->cnt = 0;
// //         BT->keys[BT->cnt] = k;
// //         for(int i=0;i<d;i++)
// //         BT->cptr[i] = NULL;
// //         return;
// //     }
// //     //checking position if it is first Time
// //     if(firstTime)
// //     {
// //         firstTime=false;
// //         temp = checkingNodePosition(BTree, k);
// //         cout<<"temp is "<<temp->keys[0]<<endl;
// //     }
// //     else temp = BT;
// //     //checking for overflow and will be doing all the opertions on temp
// //     if(temp->cnt<d-2)
// //     {
// //         temp->keys[++temp->cnt] = k;
// //         //sorting keys
// //         sort(temp->keys, temp->keys+temp->cnt+1);
// //         //adjusting pointers
// //         adjustPointers(temp, k);
// //     }
// //     else
// //     {
// //         cout<<"overflowed"<<endl;
// //         //copy the complete node in overnode
// //         overFlowNode tempOverNode;
// //         for(int i=0;i<d-1;i++)
// //         {
// //             tempOverNode.keys[i] = temp->keys[i];
// //             tempOverNode.cptr[i] = temp->cptr[i];
// //         }
// //         tempOverNode.cptr[d-1] = temp->cptr[d-1];
// //         //adding k to overflow node

// //         tempOverNode.keys[d-1] = k;
// //         tempOverNode.cptr[d]=NULL;
// //         for(int i=0;i<d;i++)
// //         cout<<tempOverNode.keys[i]<<" ";
// //         sort(tempOverNode.keys, tempOverNode.keys+d);
// //                 for(int i=0;i<d;i++)
// //         cout<<tempOverNode.keys[i]<<" ";

// //         //adjusting the pointers in overflowNode
// //         overptr overFlowNodePtr = &tempOverNode;
// //         adjustPointersInOverflowNode(overFlowNodePtr, k);

// //         //spliting the overflow node in two equal nodes
// //         int mid = d/2;
// //         btrptr lc= new(btrnode),rc= new(btrnode);
// //         for(int i=0;i<d;i++)
// //         {
// //             rc->cptr[i] = NULL;
// //             lc->cptr[i] = NULL;
// //         }
        
// //         for(int i=0;i<=mid-1;i++)
// //         {
// //             lc->keys[++lc->cnt] = tempOverNode.keys[i];
// //             lc->cptr[i] = tempOverNode.cptr[i];
// //         }
// //         lc->cptr[mid] = tempOverNode.cptr[mid];
// //         int j=-1;
// //         for(int i=mid+1;i<d;i++)
// //         {
// //             rc->keys[++rc->cnt] = tempOverNode.keys[i];
// //             rc->cptr[++j] = tempOverNode.cptr[i];
// //         }
// //         rc->cptr[++j] = tempOverNode.cptr[d];
// //         ParentNodeFind(BTree, parentNode, temp);
// //         constructBTree(parentNode, tempOverNode.keys[mid],firstTime);
// //         int i;
// //         for(i=0;i<=parentNode->cnt;i++)
// //         {
// //             if(parentNode->keys[i]==tempOverNode.keys[mid]) break;
// //         }
// //         cout<<"lc is "<<lc->keys[0]<<"rc is "<<rc->keys[0]<<endl;
// //         cout<<"parent node is "<<parentNode->keys[0]<<endl;
// //         parentNode->cptr[i] = lc, parentNode->cptr[i+1]=rc;
// //         BT = parentNode;
// //     }
// // }
// // void printPre(btrptr MT)
// // {
// //     if(MT!=NULL)
// //     {
// //         for(int i=0;i<=MT->cnt;i++)
// //         {
// //             printPre(MT->cptr[i]);
// //             cout<<MT->keys[i]<<" ";
// //         }
// //         printPre(MT->cptr[MT->cnt+1]);
// //     }
// // }
// // int main()
// // {
// //     int n;
// //     cin>>n;
// //     bool first;
// //     while(n>0)
// //     {
// //         first = true;
// //         constructBTree(BTree, n, first);
// //         cout<<"came for printing"<<endl;
// //         printPre(BTree);
// //         cout<<endl;
// //         cin>>n;
// //     }
// //     printPre(BTree);
// // }












// #include<bits/stdc++.h>
// using namespace std;
// const int d = 3;

// struct bnode{
//     int count = 0;
//     int key[d-1];
//     bnode* cptr[d]={NULL};
// };

// void Print(bnode*);

// struct OBV{
//     int key[d];
//     bnode* cptr[d+1] = {NULL};
// };

// void Insert_Sorter(bnode* curr, int _a){
//     if(curr->count!=d-1){
//         if(_a>curr->key[curr->count-1]){
//             curr->key[curr->count] = _a;
//             return;
//         }
//         for(int i=0; i<curr->count; i++){
//             if(_a<curr->key[i]){
//                 for(int j=i+1; j<=curr->count; j++){
//                     curr->key[j] = curr->key[j-1];
//                 }
//                 curr->key[i] = _a;
//                 return;
//             }
//         }
//     }
// }

// void Creatre_OBV(bnode* T, int a, bnode* left, bnode* right, OBV* &ex){
//     OBV* extra = new(OBV);bool flag = 0;
//     for(int i=0; i<T->count; i++){
//         if(T->key[i]<a){
//             extra->key[i] = T->key[i];
//             extra->cptr[i] = T->cptr[i];
//         }else{
//             if(flag == 0){
//                 extra->key[i] = a;
//                 extra->cptr[i] = left;
//                 extra->cptr[i+1] = right;
//                 flag = 1;
//                 i--;
//             }else{
//                 extra->key[i+1] = T->key[i];
//                 extra->cptr[i+2] = T->cptr[i+1];
//             }
//         }
//     }
//     if(flag == 0){
//         extra->key[d-1] = a;
//         extra->cptr[d] = T->cptr[T->count];
//     }
//     /*cout<<"Ikada";
//     for(int i=0; i<d; i++){
//         cout<<extra->key[i]<<" ";
//     }
//     cout<<endl;*/
//     ex = extra;
//     return;
// }

// void Add_Helper(OBV* t, bnode* curr, bnode* &T1, stack<bnode*>s){
//     OBV* temp = new(OBV);
//     bnode* left = new(bnode);
//     bnode* right = new(bnode);
//     for(int i=0; i<d/2 ; i++){
//         left->count++;
//         left->key[i] = t->key[i];
//         left->cptr[i] = t->cptr[i];
//     }
//     left->cptr[d/2] = t->cptr[d/2];
//     int j=0;
//     for(int i=(d/2)+1; i<d; i++,j++){
//         right->count++;
//         right->key[j] = t->key[i];
//         right->cptr[j] = t->cptr[i];
//     }
//     right->cptr[j] = t->cptr[d];
//     if(s.empty()){
//         bnode* T = new(bnode);
//         T->count = 1;
//         T->key[0] = t->key[d/2];
//         T->cptr[0] = left;
//         T->cptr[1] = right;
//         T1 = T;
//     }else{
//         bnode* parent = s.top();s.pop();
//         if(parent->count == d-1){
//             Creatre_OBV(parent, t->key[d/2], left, right, temp);
//             Add_Helper(temp, parent, T1, s);
//             return;
//         }else{
//             //cout<<"Im here"<<endl;
//             int pi = t->key[d/2];
//             int i=0;
//             while(i<parent->count && parent->key[i] < pi){
//                 i++;
//             }
//             for(int j=parent->count ; j>i; j--){
//                 parent->key[j] = parent->key[j-1];
//             }
//             for(int j=parent->count+1 ; j>i+1; j--){
//                 parent->cptr[j] = parent->cptr[j-1];
//             }
//             parent->key[i] = pi;
//             parent->cptr[i] = left;
//             parent->cptr[i+1] = right; 
//             parent->count++;
//         }
//     }
// }

// bnode* Search(bnode* T, int a, stack<bnode*>&s, stack <int>&s2){
//     if(T == NULL){
//         bnode* temp = s.top();
//         s.pop();
//         s2.pop();
//         return temp;
//     }
//     s.push(T);
//     if(a>T->key[T->count-1]){
//         s2.push(T->count);
//         return Search(T->cptr[T->count], a, s, s2);
//     }
//     for(int i=0; i<T->count; i++){
//         if(a == T->key[i]){
//             s.pop();
//             return T;
//         }
//         else if(a<T->key[i]){
//             s2.push(i);
//             return Search(T->cptr[i], a, s, s2);
//         }
//     }
// }

// void Add_(bnode* &T, int _a){
//     if(T == NULL){
//         T = new(bnode);
//         T->count = 1;
//         T->key[0] = _a;
//         return;
//     }
//     stack<bnode*>s1;
//     stack<int>s2;
//     bnode* curr = Search(T, _a, s1, s2);
//     if(curr->count<d-1){
//         Insert_Sorter(curr, _a);
//         curr->count++;
//         return;
//     }
//     OBV* extra;
//     Creatre_OBV(curr, _a, NULL, NULL, extra);
//     Add_Helper(extra, curr, T, s1);
// }

// void Print(bnode* MT){
//     if(MT == NULL)return;
//     //cout<<MT->count<<endl;
//     for(int i=0; i<=MT->count; i++){
//         Print(MT->cptr[i]);
//         if(i<MT->count){
//             cout<<MT->key[i]<<" ";
//         }
//     }
//     return;
// }

// void Level_Printer(queue<bnode*>q){
//     if(q.empty())return;
//     queue<bnode* >q1;
//     while(!q.empty()){
//         bnode* temp = q.front();q.pop();
//         for(int i=0; i<temp->count; i++){
//             cout<<temp->key[i]<<" ";
//             if(temp->cptr[i])q1.push(temp->cptr[i]);
//         }
//         if(temp->cptr[temp->count])q1.push(temp->cptr[temp->count]);
//     }
//     cout<<endl;
//     Level_Printer(q1);
// }

// int main(){
//     bnode* T = NULL;
//     int n;
//     while(cin>>n, n!=0){
//         Add_(T, n);
//     }
//     queue<bnode*>q;q.push(T);
//     Level_Printer(q);
// }