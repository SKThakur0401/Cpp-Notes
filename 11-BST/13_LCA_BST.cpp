// In previous file we made a "general LCA function" for all "BinaryTrees" .... here we have made a more optimised "custom_made" LCA function for "BSTs"

#include<iostream>
#include "0.0BinaryTree.h"


int LCA_BST(BinaryTreeNode<int>* root, int n1,int n2)
{
    if(root==NULL) return -1;
    if(max(n1,n2) > root->data  &&  min(n1,n2) < root->data) return root->data;
    else if(root->data > max(n1,n2)) return LCA_BST(root->left,n1,n2);
    return LCA_BST(root->right,n1,n2);
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvl_Wise();
    cout <<endl;

    cout<<LCA_BST(root,2,10)<<endl;

    return 0;
}


