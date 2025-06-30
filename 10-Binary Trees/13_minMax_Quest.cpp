// WRITE A FUNCTION WHICH RETURNS THE MAXIMUM AND MINIMUM "DATA" IN A BINARY TREE...

// NOTE: TO REDUCE THE WORST CASE TIME COMPLEXITY BY HALF.... WE SHOULD CREATE A FUNCTION WHICH "SIMULTANEOUSLY" DEALS WITH "MINIMUM" AND "MAXIMUM" ....  i.e. in one traversal it gets us the minimum and maximum :) ... just like we did with height and diameter :)


// Sample Input 1:
// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

// Sample Output 1:
// 1 14

// Sample Input 2:
// 10 20 60 -1 -1 3 50 -1 -1 -1 -1

// Sample Output 2:
// 3 60


#include "00BinaryTree.h"


pair<int,int> minMax(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first= INT_MAX;
        p.second=INT_MIN;
        return p;
    }

    pair<int,int> pleft = minMax(root->left);
    pair<int,int> pright= minMax(root->right);

    int lmin = pleft.first;
    int rmin = pright.first;
    int lmax = pleft.second;
    int rmax = pright.second;

    int smallest = min(root->data, min(lmin,rmin));
    int largest  = max(root->data, max(lmax,rmax));

    pair<int,int> p;
    p.first= smallest;
    p.second=largest;
    return p;
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    pair<int,int> p= minMax(root);

    cout<< "Minimum is : "<<p.first <<endl;
    cout<< "Maximum is : "<<p.second <<endl;
}

