#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

bool isBST(Node* root,Node* min=NULL,Node* max =NULL){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }

    bool leftvalid = isBST(root->left , min, root);
    bool rightvalid = isBST(root->right , root,max);

    return leftvalid and rightvalid;
}
int main()
{
    struct Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    /*
       5
      / \
     1   7
      \
       3
      / \
     2   4
    */
    if(isBST(root,NULL,NULL))
        cout<<"VALID";
    else
        cout<<"INVALID";
    return 0;
}