// Construct Binary Search Tree from the given "preorder" traversal,  
// Note: there is only one "unique" BST possible for a given preorder traversal...and you have to write a function to create that function from a given array having "preorder" traversal of the binary tree....

// Do it urself, I was able to do it the first time,

// #include<iostream>
// #include<cmath>
// #include<vector>
// #include<queue>
// #include<stack>
#include "0.0BinaryTree.h"
using namespace std;

BinaryTreeNode<int>* construct(int pre[], int lower, int upper, int n)
{
    static int i =0;
    if(i==n) return NULL;
    int curr= pre[i];
    // i++;
    if(curr >= lower && curr <= upper)
    {
        i++;
        BinaryTreeNode<int>* node = new BinaryTreeNode<int>(curr);

        node->left = construct(pre, lower, curr, n);
        node->right = construct(pre, curr+1, upper, n);
        return node;
    }
    
    else return NULL;
}

int main(){

    int pre[] = {30,20,10,15,25 , 23,39,35,42};
    // cout<< sizeof(pre) <<endl;
    
    BinaryTreeNode<int>* root = construct(pre, INT_MIN, INT_MAX, sizeof(pre)/4);

    print_lvl_Wise(root);

    return 0;
}

