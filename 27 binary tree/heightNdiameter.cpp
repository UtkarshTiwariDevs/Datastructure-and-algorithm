#include<iostream>
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
int returnHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = returnHeight(root->left);
    int rheight = returnHeight(root->right);

    return max(lheight,rheight) +1;
}
int returnDia(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = returnHeight(root->left);
    int rheight = returnHeight(root->right);
    int currdia = lheight+rheight+1;

    int ldia=returnDia(root->left);
    int rdia=returnDia(root->right);

    return max(currdia,max(ldia,rdia));
}

int calDiameter(Node* root,int* height){
    if(root==NULL){
        *height =0;
        return 0;
    }

    int lh=0,rh=0;
    
    int lDia = calDiameter(root->left,&lh);
    int rDia = calDiameter(root->right,&rh);
    int currDia = lh + rh + 1;

    *height = max(lh,rh) +1;

    return max(currDia,max(lDia,rDia));
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
   cout<<returnHeight(root)<<endl;
   cout<<returnDia(root)<<endl;
   int height =0;
   cout<<calDiameter(root,&height);
    return 0;
}