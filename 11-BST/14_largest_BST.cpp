// Chapter Assignment
// Problem Statement: Largest BST
// Problem Level: HARD
// Problem Description:
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

// Output format:
// The first and only line of output contains the height of the largest BST.

// Constraints:
// Time Limit: 1 second

// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1:
// 2



// HINT: (IF NOT ABLE TO DO YOURSELF) --> FOR THE MOST OPTIMISED SOLUTION...REMEMBER HOW U MADE "isBST" using "trinity class" .... think along those lines...


#include "0.0BinaryTree.h"

class quadruple
{
    public:
    int max;
    int min;
    int height;
    bool ans;
    quadruple()
    {
        max= INT_MIN;
        min= INT_MAX;
        height=0;
        ans= true;
    }
};


quadruple largest_BST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        quadruple q;
        return q;
    }

    quadruple leftAns= largest_BST(root->left);
    quadruple rightAns= largest_BST(root->right);

    quadruple q;
    if(leftAns.ans==false && rightAns.ans==false)
    {
        q.height=max(leftAns.height,rightAns.height);
        q.ans= false;
    }

    else if(leftAns.ans==false)
    {
        q.height=max(leftAns.height, rightAns.height);
        q.ans=false;
        return q;
    }

    else if(rightAns.ans==false)
    {
        q.height=max(rightAns.height, leftAns.height);
        q.ans=false;
        return q;
    }
    if(leftAns.max> root->data || rightAns.min< root->data)
    {
        q.ans=false;
        q.height= max(leftAns.height,rightAns.height);
        return q;
    }
    q.height= 1+ max(leftAns.height, rightAns.height);
    q.min=min(root->data, leftAns.min );
    q.max=max(root->data, rightAns.max);
    return q;
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    cout<< largest_BST(root).height <<endl;
}



// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

// 10 6 14 2 8 11 18 -1 -1 -1 -1 -1 -1 -1 -1

// 16 4 64 2 8 32 128 -1 -1 7 9 -1 -1 -1 -1 -1 -1 -1 -1
