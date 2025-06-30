// Apart from "pre-order" and "post-order" ..binary trees also have "in-order"
// here, we print    "leftNode" "root" "rightNode"
// here, "leftNode" in a sense...first (left node will be printed in the same way)

#include "00BinaryTree.h"



void inorder_print(BinaryTreeNode<int>* root)
{
    if(root == NULL) {return;}
    inorder_print(root->left);
    cout<< root->data <<  " ";
    inorder_print(root->right);
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    inorder_print(root);
    return 0;
}

