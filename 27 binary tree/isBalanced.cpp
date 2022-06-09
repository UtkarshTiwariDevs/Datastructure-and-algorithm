#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left =NULL;
        right =NULL;
    }
};
int calheight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh = calheight(root->left);
    int rh = calheight(root->right);
    return max(lh,rh)+1;
}
//O(n*n)
bool isBalanced(Node* root){
    if(root==NULL)
        return true;

    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    int lh = calheight(root->left);
    int rh = calheight(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}
//O(n)
bool isBalanced2(Node* root,int* height){
    if(root==NULL)
        return true;
    int lh= 0 ,rh=0;
    if(isBalanced2(root->left,&lh)==false){
        return false;
    }
    if(isBalanced2(root->right,&rh)==false){
        return false;
    }

    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

int main(){
    struct Node* root= new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left =new Node(8);

    /*
       1
      / \
     2   3
    / \  /\
   4   5 6 7
   /
   8
    */
    // if(isBalanced(root))
    //     cout<<"Balanced"<<endl;
    // else
    //     cout<<"Unbalanced"<<endl;
    int height = 0;
    if(isBalanced2(root,&height))
        cout<<"Balanced"<<endl;
    else
        cout<<"Unbalanced"<<endl;
    return 0;
}