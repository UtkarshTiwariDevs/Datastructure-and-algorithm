/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int solve(Node *root, int &res)
{
    if (root == nullptr)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(temp, (l + r + root->data));
    res = max(res, ans);

    return temp;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int res = INT_MIN;
    cout << solve(root, res);
    return 0;
}