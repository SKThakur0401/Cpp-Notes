// Find median in ---> time-complexity : O(n)       space-complexity : O(1)

// Finding median is easy, but here space complexity should be "O(1)" , which is difficult to have, the normal preorder,inorder, postorder traversals can't be used here due to the space constraint, so yes, the only option available is "Morris Traversal" as it is the only traversal method which consumes no space, we r gonna use MORRIS INORDER TRAVERSAL HERE,

// Cases-
// First : if there are odd no. of elements, the middle one is ans,
// Second : if there are even no. of elements, the average of middle two is answer

#include "0.0BinaryTree.h"
using namespace std;

int countNodes(BinaryTreeNode<int>* root)
{
    if(!root) return 0;
    return 1+ countNodes(root->left) + countNodes(root->right);
}

void Median(BinaryTreeNode<int>* root, int count)
{
    int x = 0;
    BinaryTreeNode<int>* curr = root;

    while(curr)
    {
        if(curr->left == NULL)
        {
            x++;
            if(count %2 == 1 && x == (count+1)/2)
            {
                cout<< curr->data<<endl;
                return;
            }

            if(count %2 == 0 && x == count/2)
            {
                cout<< float(float(curr->data + curr->right->data)/2) <<endl;
            }

            curr=curr->right;
        }

        else
        {
            BinaryTreeNode<int>* prev= curr->left;

            while(prev->right && prev->right != curr)
            {
                prev=prev->right;
            }

            if(prev->right == NULL)
            {
                prev->right = curr;
                curr= curr->left;
            }

            if(prev->right == curr)
            {
                prev->right= NULL;
                x++;
                if(count %2 == 1 && x == (count+1)/2)
                {
                    cout<< curr->data<<endl;
                    return;
                }

                if(count %2 == 0 && x == count/2)
                {
                    cout<< float(float(curr->data + curr->right->data)/2) <<endl;
                }
                curr= curr->right;
            }
        }
    }
}


int main(){

    BinaryTreeNode<int>* root = takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    
    int count = countNodes(root);       // Tells total number of nodes in the BST

    Median(root, count);

    return 0;
}

