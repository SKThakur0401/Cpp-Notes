// CONSTRUCTING A TREE USING POST-ORDER AND INORDER .... (IF YOU UNDERSTAND THE WORKING OF TREE CONSTRUCTION USING PRE-ORDER AND INORDER... THEN MAKING THIS IS EASY :)
#include "00BinaryTree.h"

int search(int inorder[],int si,int ei,int curr)
{
    for (int i = si; i <= ei; i++)
    {
        if(inorder[i] == curr) return i;
    }
    return -1;
}


BinaryTreeNode<int>* buildTree(int postorder[], int inorder[], int si, int ei)
{
    if(si>ei) return NULL;
    static int index=ei;
    int curr= postorder[index];
    index--;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(curr);
    if(si==ei) return root;

    int pos = search(inorder,si,ei,curr);
    root->right=buildTree(postorder,inorder,pos+1,ei);
    root->left= buildTree(postorder,inorder,si,pos-1);
    return root;
}


int main()
{
    int postorder[]= {2,9,3,6,10,5};
    int inorder[] =  {2,6,3,9,5,10};

    int endingIndex = (sizeof(inorder) /4)-1;       // endingIndex= (total no of elements) -1

    BinaryTreeNode<int>* root = buildTree(postorder,inorder,0,endingIndex); 
    cout <<endl;
    cout <<endl;
    print_lvl_Wise(root);

    return 0;
}




//                                           -|-
//                                           -|-
//                                           -|-
//                                      -o |- o -| o-
//                                           -|-
//                                           -|-
//                                           -|-

