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

Node *constructBST(int preorderarr[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = constructBST(preorderarr, preorderIdx, preorderarr[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = constructBST(preorderarr, preorderIdx, preorderarr[*preorderIdx], key, max, n);
        }
    }
    return root;
}
void preorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    int preorderarr[] = {10, 2, 1, 13, 11};
    int preorderIdx = 0;
    int n = 5;
    Node *root = constructBST(preorderarr, &preorderIdx, preorderarr[0], INT_MIN, INT_MAX, n);
    preorderPrint(root);
    return 0;
}