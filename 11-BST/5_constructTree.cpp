// We know for "searching" in a "BINARY SEARCH TREE"  TIME-COMPLEXITY= O(height) ... .. so its for the best if we create a shorter tree.... e.g. we can create a tree of height=7 ... for 7 nodes....(most- unbalanced case)  ... and we can alse WRAP-UP 7-NODES IN A TREE OF HEIGHT "3" ...( LVL WISE INPUT --> 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1)  .... SO WE MUST STRIVE TO CREATE SHORTER TREES :)

// HERE WE ARE GOING TO MAKE A FUNCTION... WHICH "CONSTRUCTS A TREE" FROM A GIVEN ARRAY OF ELEMENTS.
// SINCE WE R MAKING A "BST" ....OFCOURSE THE ARRAY HAS NUMBERS IN SORTED FASHION
// AND IT CREATES THE SHORTEST (IN TERMS OF HEIGHT) TREE POSSIBLE :) .... OR U CAN SAY... MOST "BALANCED TREE" POSSIBLE...

#include "0.0BinaryTree.h"

BinaryTreeNode<int>* ConstructTree(int arr[],int si, int ei)
{
    if(si>ei) return NULL;

    int mid= (si+ei)/2;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[mid]);

    root->left= ConstructTree(arr,si,mid-1);
    root->right= ConstructTree(arr,mid+1,ei);

    return root;
}

int main()
{
    int arr[]= {1,2,3,4,5,6,7};

    BinaryTreeNode<int>* root= ConstructTree(arr,0, (sizeof(arr)/4)-1 );
    print_lvl_Wise(root);
}