// Create a function "sumPair" which returns pair of nodes... having sum = an user given int "k"
// We used "sumPair" and "isPresent" function in this approach

#include "0.0BinaryTree.h"

BinaryTreeNode<int>* isPresent(BinaryTreeNode<int>*root,int k)  // I created this function to support my "sumPair function" ...returns "NULL" if there is no node corresponding to integer "k"... elsewise : returns the node whose data is equal to integer "k"
{
    if(root->data==k) return root;
    if(root->left!= NULL)
    {
        BinaryTreeNode<int>* kite= isPresent(root->left,k);
        if(kite != NULL) return kite;
    }
    if(root->right!= NULL)
    {
        BinaryTreeNode<int>* kite= isPresent(root->right,k);
        if(kite != NULL) return kite;
    }
    return NULL;
}


void sumPair(BinaryTreeNode<int>*root,int sum, BinaryTreeNode<int>* realRoot)
{
    if(root==NULL) return;

    if(root->data != INT_MIN)
    {
        BinaryTreeNode<int>* sec= isPresent(realRoot,sum- root->data);  // Note: we r going to use  
                                        // "realRoot" here... bcoz we need to 'encompass' the entire tree... and not just the nodes below the node which is now acting as root..... that's why we kept "realRoot" ... the actual root of the entire "BinaryTree".
        if(sec != NULL && sec != root) 
        {
            cout<<root->data<<" "<<sum- root->data <<endl;
            sec->data= INT_MIN;
        }
    }
    sumPair(root->left ,sum,realRoot);
    sumPair(root->right,sum,realRoot);
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvl_Wise();
    cout <<endl;
    cout <<endl;
    cout <<endl;

    sumPair(root,7,root);

    return 0;
}

// NOTE: calc time comlexity in this quest......HERE TIME COMPLEXITY ==  O(n^2) ....which is quite high.

// There is a better approach than this....(try a sec to think) 

// Approach : store all the Tree elements in an array.... sort the array.... then using 2 variables.... one travelling left to right from start to end other right to left from end-to-start.... use them to find all pairs....(we have used this 2 variable method a lot)

// In this new approach... Time complexity = "n"<for storing each element in array>+ "n*log(n)" <merge sort array> + "n"<2 variable method> ==> "  n*log(n)  " which is "way better" than O(n^2)   ..... however here we are using auxilary space...(the array) ... so space complexity was earlier "constant" (or nothing) ... and now its O(n)

// new approach is solved in next file


