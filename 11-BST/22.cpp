// Replace every element with the least greater element on its right.
// Hard question for first time,... otherwise easy-medium lvl quest

// Input:  [8,  58, 71, 18, 31, 32, 63, 92, 43,  3, 91, 93, 25, 80, 28]
// Output: [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]

#include<iostream>
#include<vector>
#include "0.0BinaryTree.h"
using namespace std;

void insert(BinaryTreeNode<int>* &root, int val, BinaryTreeNode<int>* &suc)
{
    if(!root)
    {
        root = new BinaryTreeNode<int>(val);
        return;
    }

    if(root->data > val)
    {
        suc = root;
        if(!root->left)
        {
            root->left= new BinaryTreeNode<int>(val);
        }
        else {insert(root->left , val, suc);}
        return;
    }

    if(root->data <= val)
    {
        if(!root->right) root->right = new BinaryTreeNode<int>(val);

        else {insert(root->right , val, suc);}
        return;
    }
}


int main(){

    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    
    BinaryTreeNode<int>* root = NULL;
    int n  = sizeof(arr)/ sizeof(arr[0]);
    vector<int> ans;
    for (int i = n-1; i >=0; i--)
    {
        BinaryTreeNode<int>* suc=NULL;
        insert(root, arr[i], suc);
        if(suc) ans.push_back(suc->data);
        else {ans.push_back(-1); }
    }
    
    for (int i = ans.size() -1 ; i>= 0; i--)
    {
        cout<< ans[i] <<" ";
    }
    cout <<endl;
    return 0;
}

