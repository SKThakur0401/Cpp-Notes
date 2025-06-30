// Print all nodes which do not have a sibling.... or print all the single child in a tree...

#include "00BinaryTree.h"

void singleChild(BinaryTreeNode<int>* root)
{
    if(root== NULL) return;

    if (root->left != NULL  && root->right== NULL)
    {
        cout<< root->left->data <<" ";
    }

    if (root->left == NULL  && root->right != NULL)
    {
        cout<< root->right->data <<" ";
    }

    if(root->left != NULL) singleChild(root->left);
    if(root->right != NULL) singleChild(root->right);
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout <<endl;
    singleChild(root);
}
