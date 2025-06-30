#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include "0.0BinaryTree.h"
using namespace std;

BinaryTreeNode<int>* construct(int pre[], int si, int ei)
{
    if(si > ei) return NULL;
    if(si== ei) return NULL;
    // if(si+1 == ei) return NULL;
    
    // Node* root = newNode(pre[si]);
    BinaryTreeNode<int>* root; root->data= pre[si];
    root->left=NULL; root->right= NULL;
    // if(si == ei) return root;
    int i= si+1;
    for(i= si+1 ; i<= ei; i++)
    {
        if(pre[i] > pre[si]) break;
    }
    root->left = construct(pre, si+1, i-1);
    root->right= construct(pre, i, ei);

    return root;
}


int main(){

    int pre[] = {40, 30, 35, 80, 100};
    BinaryTreeNode<int>* root= construct(pre, 0, (sizeof(pre)/sizeof(pre[0]) -1));
    cout <<endl;
    cout <<endl;
    print_lvl_Wise(root);

    return 0;
}

