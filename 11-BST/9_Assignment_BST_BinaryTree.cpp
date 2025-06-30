// All the following files are related to the "BST and BinaryTree Assignment"

// Question:
// Chapter Assignment
// Problem Statement: Create  Insert Duplicate Node
// Problem Level: EASY
// Problem Description:
// For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
// The root will remain the same. So you just need to insert nodes in the given Binary Tree.
// Example:

// After making the changes to the above-depicted tree, the updated tree will look like this.


// You can see that every node in the input tree has been duplicated and inserted to the left of itself.

// Input format :
// The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

// Output Format :
// The updated tree will be printed in a level order fashion where each level will be printed on a new line. 
// Elements on every level will be printed in a linear fashion. A single space will separate them.

// Note:
// You are not required to print anything explicitly. It has already been taken care of. Just implement the function to achieve the desired structure of the tree.

// Constraints :
// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec

// Sample Input 1:
// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

// Sample Output 1:
// 10 
// 10 30 
// 20 30 60 
// 20 50 60 
// 40 50 
// 40

// Sample Input 2:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

// Sample Output 2:
// 8 
// 8 10 
// 5 10 
// 5 6 
// 2 6 7 
// 2 7


#include "0.0BinaryTree.h"


void print_separate_lines(BinaryTreeNode<int>* root)
{
    if(root==NULL) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        if (front==NULL)
        {
            if(!pendingNodes.empty()) pendingNodes.push(NULL);
            cout <<endl;
        }

        else
        {
            cout<< front->data <<" ";
            if(front->left != NULL) pendingNodes.push(front->left);
            if(front->right != NULL) pendingNodes.push(front->right);
        }
    }
}

BinaryTreeNode<int>* leftCopifier(BinaryTreeNode<int>* root)    // the function that copies all 
                                                                // nodes to its left
{
    if(root==NULL) return NULL;

    BinaryTreeNode<int>* leftCopy= new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* attachment= root->left;
    root->left= leftCopy;
    leftCopy->left= attachment;

    root->right = leftCopifier(root->right);
    leftCopy->left=leftCopifier(leftCopy->left);

    return root;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvl_Wise();
    cout <<endl;
    cout <<endl;
    cout <<endl;

    root= leftCopifier(root);

    print_separate_lines(root);
    return 0;
}
