// Construct Binary Search Tree from the given "inorder" traversal,  (Like the previous question)

// NOTE: THE CODE BELOW CAN BE USED TO SOLVE A VARIETY OF PROBLEMS SUCH AS : 

// Example-1 > CONVERT A (normal) BST into a BALANCED-BST,     SOLUTION: (FIRST THINK URSELF(EASY) , )........answer--->STORE THE INORDER TRAVERSAL IN AN ARRAY, CONSTRUCT BST FROM THAT :)

// Example-2 > Merge 2 "Balanced BSTs having 'n' and 'm' elements respectively", (brute force approach : take elements from one bst and start inserting it to another, but that will take "log(n)" time for first insertion, and "log(n+m-1)" time for last insertion, net Time-complexity--> m*log(n) to m*(log(n+m-1) )) ..... NOW the best approach : STORE INORDER TRAVERSAL OF BOTH IN ARRAYS, AND THEN MERGE THOSE 2 SORTED ARRAYS, THEN CREATE BST FROM THAT ARRAY :)...TIME COMPLEXITY: O(m+n)

// Note:(probably...) there is only one "unique" ' Balanced-BST' possible for a given inorder traversal...and you have to write a function to create that function from a given array having "inorder" traversal of the binary tree....

// Do it urself, I was able to do it the first time,

// Nothing new, have done this in file "5" of this folder,

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include "0.0BinaryTree.h"
using namespace std;

BinaryTreeNode<int>* construct(int in[], int si, int ei)
{
    if(si>ei) return NULL;
    int mid = (si+ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(in[mid]);

    root->left= construct(in, si, mid-1);
    root->right= construct(in, mid+1, ei);
    return root;
}

int main(){

    int in[] = {9,12,14,17,19,23,50,54,67, 72, 76};
    // cout<< sizeof(in) <<endl;
    
    BinaryTreeNode<int>* root = construct(in, 0, (sizeof(in)/4) -1 );

    print_lvl_Wise(root);

    return 0;
}
