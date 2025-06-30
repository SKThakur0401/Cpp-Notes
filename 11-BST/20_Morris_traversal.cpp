// So far the traversal techniques we discussed (recursive and iterative(using stack)               in/pre/post-Order traversals requires extra space, so "space-complexity = O(n) ")

// Morris Traversal does not require any extra space, " O(1) "
// Morris traversal uses the concept of "threaded binary tree"


// SOLUTION : 
// Self notes: (JUST REMEMBER THESE 3 STEPS!!!)
// In-order Morris Traversal:
// 🌳 1st case: if left is null, print current node and go right
// 🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
// 🌳 3rd case: if thread is already pointed to current node, then remove the thread


#include "0.0BinaryTree.h"
using namespace std;


void inorder(BinaryTreeNode<int>* root, BinaryTreeNode<int>* pre, BinaryTreeNode<int>* suc)
{
    if(!root) return;

    BinaryTreeNode<int>* cur = root;

    while(cur)
    {
        if(cur->left == NULL)
        {
            cout<<cur->data<<" ";
            cur= cur->right;
        }
        
        else
        {
            BinaryTreeNode<int>* prev= cur->left;
            while(prev->right && prev->right != cur)
            {
                prev=prev->right;
            }

            if(prev->right == NULL)
            {
                prev->right = cur;
                cur= cur->left;
            }
            else if(prev->right == cur)
            {
                prev->right = NULL;
                cout<< cur->data <<" ";
                cur= cur->right;
            }
        }
    }

}

int main(){

    BinaryTreeNode<int>* root = takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    inorder(root, NULL, NULL);
    

    return 0;
}

