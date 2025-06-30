#include "0.0BinaryTree.h"

void printAtDepth(BinaryTreeNode<int>* root, int k)
{
    if(k<0 || root==NULL) return;
    else if(k==0) { cout<< root->data <<" "; return; }
    else
    {
        printAtDepth(root->left, k-1);
        printAtDepth(root->right,k-1);
    }
}

BinaryTreeNode<int>* returnNode(BinaryTreeNode<int>* root,int data)
{
    if(root->data == data) return root;
    if(root->left != NULL) returnNode(root->left,data);
    if(root->right!= NULL) returnNode(root->right,data);
}

void printNodes(BinaryTreeNode<int>* root, int start, int k)
{
    BinaryTreeNode<int>* node= returnNode(root,start);
    printAtDepth(node,k);
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    printNodes(root,int start, int k, int distance);
}

