#include "0.0BinaryTree.h"

bool isBST_aDifferent_way(BinaryTreeNode<int>* root,int min= INT_MIN , int max= INT_MAX)
{
    if(root==NULL) return true;
    if(root->data < min || root->data > max) return false;
    bool isLeftOk= isBST_aDifferent_way(root->left,min,root->data -1);
    bool isRightOk= isBST_aDifferent_way(root->right,root->data,max);

    return isLeftOk && isRightOk;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout<< isBST_aDifferent_way(root) <<endl;
}

