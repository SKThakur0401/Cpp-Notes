#include "00BinaryTree.h"


bool isPresent(BinaryTreeNode<int>* root, int n) //returns true if "n" is present in tree
{
    if(root->data == n){return true;}
    if(root->left != NULL)
    {
        bool ans= isPresent(root->left, n);
        if(ans== true){return true;}
    }

    if(root->right != NULL)
    {
        bool ans= isPresent(root->right, n);
        if(ans== true){return true;}
    }
    return false;
}

int height(BinaryTreeNode<int>* root)       // tells height or(no. of nodes in longest chain)
{
    int h=0;
    if(root->left== NULL && root->right== NULL){return 1;}

    if(root->left != NULL)
    {
        int testing= 1+ height(root->left);
        if(testing> h){h= testing;}
    }

    if(root->right != NULL)
    {
        int testing= 1+ height(root->right);
        if(testing> h){h= testing;}
    }
    return h;
}

int main(){
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout<< height(root)<<endl;
    return 0;
}