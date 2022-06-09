
/*Diameter of Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
*/

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left , *right;

    Node(int val){
        data = val;
        left =NULL;
        right =NULL;
    }
};

int solve(Node* root , int &res){
    if(root == nullptr)
        return 0;
    
    int l = solve(root->left,res);
    int r = solve(root->right,res);

    int temp = 1+max(l,r);
    int ans = max(temp,(1+l+r));
    res = max(res,ans);

    return temp;
}
int main(){
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    int res = INT_MIN;
    cout<<solve(root,res);
    return 0;
}