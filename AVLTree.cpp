#include <bits/stdc++.h>
using namespace std;
typedef struct avlnode *avlptr;
struct avlnode
{
    struct avlnode *lchild;
    int data;
    struct avlnode *rchild;
    int height;
};
int height(avlptr N)  
{  
    if (N == NULL)  
        return -1;  
    return N->height;  
}
avlptr newNode(int key)  
{  
    avlptr node = new avlnode(); 
    node->data = key;  
    node->lchild = NULL;  
    node->rchild = NULL;  
    node->height = 0;
    return(node);  
}
avlptr rightRotate(avlptr y)  
{  
    avlptr x = y->lchild;  
    avlptr T2 = x->rchild;  
  
    // Perform rotation  
    x->rchild = y;  
    y->lchild = T2;  
  
    // Update heights  
    y->height = max(height(y->lchild), 
                    height(y->rchild)) + 1;  
    x->height = max(height(x->lchild), 
                    height(x->rchild)) + 1;  
  
    // Return new root  
    return x;  
}
avlptr leftRotate(avlptr x)  
{  
    avlptr y = x->rchild;  
    avlptr T2 = y->lchild;  
  
    // Perform rotation  
    y->lchild = x;  
    x->rchild = T2;  
  
    // Update heights  
    x->height = max(height(x->lchild),     
                    height(x->rchild)) + 1;  
    y->height = max(height(y->lchild),  
                    height(y->rchild)) + 1;  
  
    // Return new root  
    return y;  
}
int getBalance(avlptr N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->lchild) - height(N->rchild);  
}
void preOrder(avlptr root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->lchild);  
        preOrder(root->rchild);  
    }  
}
avlptr insert(avlptr node, int data)  
{  
    /* 1. Perform the normal BST insertion */
    if (node == NULL)  
        return(newNode(data));  
  
    if (data < node->data)  
        node->lchild = insert(node->lchild, data);  
    else if (data > node->data)  
        node->rchild = insert(node->rchild, data);  
    else // Equal datas are not allowed in BST  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->lchild),  
                        height(node->rchild));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // lchild lchild Case  
    if (balance > 1 && data < node->lchild->data)  
        return rightRotate(node);  
  
    // rchild rchild Case  
    if (balance < -1 && data > node->rchild->data)  
        return leftRotate(node);  
  
    // lchild rchild Case  
    if (balance > 1 && data > node->lchild->data)  
    {  
        node->lchild = leftRotate(node->lchild);  
        return rightRotate(node);
    }  
  
    // rchild lchild Case  
    if (balance < -1 && data < node->rchild->data)  
    {  
        node->rchild = rightRotate(node->rchild);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}
int main()
{
    avlptr AV=NULL;
    AV = insert(AV, 10);  
    AV = insert(AV, 20);  
    AV = insert(AV, 30);  
    AV = insert(AV, 40);  
    AV = insert(AV, 50);  
    AV = insert(AV, 25);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(AV);
    
    return 0;  

}