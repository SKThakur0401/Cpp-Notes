// A binary search Tree is a binary tree... inspired by "binary search"

// Definition : A Binary Tree where for each node "n"
//              the left node is smaller and the right node is bigger than "n" ...thus having 
//              elements in an organised manner


// HERE WE MADE A FUNCTION... "SEARCH" WHICH RETURNS "TRUE" IF "INT K" IS PRESENT ... ELSE FALSE
// The search Function has a time-complexity = O(height) ... so searching in a binary-search tree is easier in a "shorter tree" .... and the shorter tree for the same number of nodes is the one "balanced tree... with all nodes present" searching is easiest in such trees.......and the pain in the arse tree with maximum height is the one "most unbalanced tree...with all nodes having 1 child node..."

// HERE WE MADE A FUNCTION... "rangePrinter" which returns all elements in the range given by the user... it returns all elements in the binary tree...in the range given by the user


#include "0.0BinaryTree.h"

bool search(BinaryTreeNode<int>*root,int k)
{
    if(root->data == k) return true;            // U also need to handle the case e.g. "int k" is less than root->data...but root->left is NULL .... in this case ...obviously the element is not present in our BST...its handled here

    if(k > root->data && root->right != NULL)
    {
        bool fk = search(root->right,k);
        if(fk==true) return true;
    }
    if(k < root->data && root->left != NULL)
    {
        bool fk = search(root->left,k);
        if(fk==true) return true;
    }
    return false;
}

void rangePrinter(int a, int b, BinaryTreeNode<int>* root)
{
    if(root == NULL) return;
    if(root->data >b)
    {
        rangePrinter(a,b,root->left);
    }

    else if(root->data <a)
    {
        rangePrinter(a,b,root->right);
    }
    
    else
    {
        rangePrinter(a,b,root->left);

        cout<< root->data <<" ";
        // rangePrinter(a,b,root->left);        // we commented this out and wrote the same line before printing the root data... to get the result in proper ascending order :)
        rangePrinter(a,b,root->right);
    }
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    // cout<< search(root,11) <<endl;

    rangePrinter(4,10,root);    // prints all elements in the range ...both inclusive
}

// 5 2 8 1 4 6 10 -1 -1 3 -1 -1 -1 9 11 -1 -1 -1 -1 -1 -1

