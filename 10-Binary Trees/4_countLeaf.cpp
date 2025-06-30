#include "00BinaryTree.h"

int countLeaf(BinaryTreeNode<int>* root)
{
    int count=0;
    if(root->left != NULL)
    {
        count+= countLeaf(root->left);
    }
    if(root->left != NULL)
    {
        count+= countLeaf(root->left);
    }

    else if(root->left == NULL  &&  root->right==NULL)
    {
        return 1;
    }
    return count;
}

// int countLeaf(binaryTreeNode<int>* root) // Smaller code
// {
//     if(root==NULL) return 0;
//     if(root->left== NULL && root->right== NULL) return 1;

//     return countLeaf(root->left) + countLeaf(root->right);
// }

int countNode(BinaryTreeNode<int>*root)
{
    if(root== NULL){return 0;}
    return 1+ countNode(root->left) + countNode(root->right);
}

int main(){
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout<< "Total number of leaves : "<<countLeaf(root) <<endl;
    cout<< "Total number of Nodes : "<<countNode(root) <<endl;
    return 0;
}