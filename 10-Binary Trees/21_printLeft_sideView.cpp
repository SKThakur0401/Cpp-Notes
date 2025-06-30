#include "00BinaryTree.h"

void printLeft_sideView(BinaryTreeNode<int>* root)
{
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    cout<< root->data <<endl;
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL)
        {
            if(!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
                cout<< pendingNodes.front()->data <<endl;
            }
        }
        else
        {
            if(front->left !=NULL) pendingNodes.push(front->left);
            if(front->right !=NULL) pendingNodes.push(front->right);
        }
    }
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    print_lvl_Wise(root);
    cout <<endl;

    printLeft_sideView(root);
    return 0;

}