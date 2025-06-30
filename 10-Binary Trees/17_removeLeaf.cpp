// "leafCutter" will remove all the leaf node... a leaf node is the one which has no (left  and right) nodes...or is the last element in a trail of nodes...

#include "00BinaryTree.h"


void lvl_Wise_printer(BinaryTreeNode<int>*root) // print each level on a separate line .... also known as "Lvl_separateLine_printer"
{
    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL)
        {
            cout <<endl;
            if(!pendingNodes.empty()) pendingNodes.push(NULL);      // we set the if condition to prevent the formation of a loop of "nulls" after going thru all the elements and the last null it would continue returning null and pushing another null and then poping null and inserting another null
        }

        else
        {
            cout<< front->data <<" ";
            if(front->left != NULL) pendingNodes.push(front->left);
            if(front->right != NULL) pendingNodes.push(front->right);
        }
    }
}


BinaryTreeNode<int>* leafCutter(BinaryTreeNode<int>* root)
{
    if(root->left== NULL && root->right== NULL)
    {
        root=NULL;
    }
    else
    {
        if(root->left != NULL) root->left=leafCutter(root->left);
        if(root->right != NULL) root->right=leafCutter(root->right);
    }
    return root;
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    root=leafCutter(root);

    lvl_Wise_printer(root);
}

