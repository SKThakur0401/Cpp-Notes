// CONSTRUCTING A TREE USING PRE-ORDER AND IN-ORDER

#include "00BinaryTree.h"

int search(int inorder[],int si, int ei, int curr)
{
    for (int i = si; i <= ei; i++)
    {
        if(inorder[i] == curr){return i;}
    }
    return -1;      // This line will never be executed (it does not mean anything)..coz we know inorder[i]==curr will be true for 1 case...... but we wrote it to avoid the warning "non-void function does not return a value in all control paths" :)
}

BinaryTreeNode<int>* buildTree(int preorder[], int inorder[], int si, int ei)
{
    if(si > ei) return NULL;
    static int index=0;
    int curr= preorder[index];
    index++;

    BinaryTreeNode<int>*root= new BinaryTreeNode<int>(curr);
    if(si== ei) return root;

    int pos = search(inorder,si, ei,curr);

    root->left =buildTree(preorder, inorder, si, pos-1);
    root->right=buildTree(preorder, inorder, pos+1, ei);
    return root;
}

int main()
{
    // int preorder[]= {1,2,4,5,3,6,7};
    // int inorder[] = {4,2,5,1,6,3,7};

    int n; cin>>n;
    int preorder[n];
    int inorder[n];
    for (int i = 0; i < n; i++)
    {
        cin>>preorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>inorder[i];
    }
    
    cout <<endl;
    cout <<endl;
    BinaryTreeNode<int>* root = buildTree(preorder,inorder,0,n-1);
    print_lvl_Wise(root);

    return 0;
}

