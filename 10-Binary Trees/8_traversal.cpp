#include "00BinaryTree.h"

void preorder_print(BinaryTreeNode<int>* root)
{
    cout<< root->data<<" ";
    if(root->left != NULL)
    {
        preorder_print(root->left);
    }
    if(root->right != NULL)
    {
        preorder_print(root->right);
    }
}


void postorder_print(BinaryTreeNode<int>* root)
{
    if(root->left != NULL){postorder_print(root->left);}
    if(root->right != NULL){postorder_print(root->right);}
    cout<< root->data <<" ";

}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout<< "Pre-order answer : ";
    preorder_print(root);
    cout <<endl;
    cout<< "Post-order answer : ";
    postorder_print(root);
    return 0;
}