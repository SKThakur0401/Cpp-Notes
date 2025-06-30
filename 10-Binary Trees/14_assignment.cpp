#include "00BinaryTree.h"


int sum(BinaryTreeNode<int>* root)      // Returns sum of all nodes in a binary tree
{
    if(root== NULL) return 0;
    int s=0;
    s+= sum(root->left);
    s+= sum(root->right);
    s+= root->data;

    return s;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    cout<< "Sum = "<<sum(root) <<endl;
}

