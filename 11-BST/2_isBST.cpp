// This code tells us whether a binary tree is a "BST" or not...
// Note: this is not the "optimised solution" .... calculate the time complexity for this code..... ANSWER---> ITS THE SAME CASE AS THE "FIND-DAMETER" QUESTION

// HERE IN THIS QUESTION....(IMAGINE THE TWO CASES... OF A FULLY BALANCED TREE AND A FULL UNBALANCED TREE) .... THE TIME COMPLEXITY (JUST LIKE THE "FIND-DIAMETER QUESTION") WILL COME OUT TO BE O(n* height) .... the next file contains the optimised solution....where both min-max calculation and isBST calculation is taking place simultaneously :) ... SO TC FOR THE NEXT FILE IS : O(n)

#include "0.0BinaryTree.h"

int maximum(BinaryTreeNode<int>* root)
{
    if(root== NULL) return INT_MIN;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root== NULL) return INT_MAX;

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root)
{
    if(root== NULL) return true;

    int lmax= maximum(root->left);
    int rmin= minimum(root->right);

    bool output=(lmax < root->data)&&(rmin > root->data)&& isBST(root->left) && isBST(root->right);

    return output;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout<< isBST(root) <<endl;
}
