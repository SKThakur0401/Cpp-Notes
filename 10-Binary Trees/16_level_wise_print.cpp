#include "00BinaryTree.h"


void Lvl_separate_Line_printer(BinaryTreeNode<int>*root)
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

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    Lvl_separate_Line_printer(root);
}

