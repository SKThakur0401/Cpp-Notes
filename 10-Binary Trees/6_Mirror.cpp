// Mirror tree has all the "left & right nodes swapped"

#include "00BinaryTree.h"

void mirror(BinaryTreeNode<int>* root)
{
    if(root==NULL) return;
    BinaryTreeNode<int>* a= root->left;
    root->left= root->right;
    root->right= a;
    // swap(root->left, root->right)        // Instead of writing the 3 lines above, for swapping,
                                            // we could have just done it with this line :)

    mirror(root->left);
    mirror(root->right);
}

int main(){
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    print_lvl_Wise(root);
    cout <<endl;
    cout <<endl;
    mirror(root);
    print_lvl_Wise(root);


    return 0;
}