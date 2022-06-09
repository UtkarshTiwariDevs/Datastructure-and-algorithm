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

struct Info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

Info longestBST(Node *root)
{
    if (root == NULL)
    {
        return {1, INT_MAX, INT_MIN, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftinfo = longestBST(root->left);
    Info rightinfo = longestBST(root->right);

    Info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);

    if (leftinfo.isBST && rightinfo.isBST &&
        leftinfo.max < root->data && rightinfo.min > root->data){

            curr.min = min(leftinfo.min , min(rightinfo.min , root->data));
            curr.max = max(leftinfo.max , max(rightinfo.max , root->data));

            curr.ans = curr.size;
            curr.isBST = true;
            return curr;
    }
    curr.ans  = max(leftinfo.ans , rightinfo.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    struct Node *root1 = new Node(12);
    root1->left = new Node(9);
    root1->right = new Node(15);
    root1->left->left = new Node(5);
    root1->left->right = new Node(10);

    /*
       12
      / \
     9   15
    / \
    5  10

    */
    cout<<"Largest bst in bt "<<longestBST(root1).ans<<endl;
    return 0;
}