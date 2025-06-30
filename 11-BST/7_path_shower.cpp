#include "00BinaryTree.h"

vector<int> pathFinder(BinaryTreeNode<int>* root, int k)
{
    if(root== NULL)
    {
        vector<int> v;
        return v;
    }

    vector<int> leftAns = pathFinder(root->left,k);
    vector<int> rightAns = pathFinder(root->right,k);
    if(root->data == k)
    {
        vector<int> ans;
        ans.push_back(root->data);
        return ans;
    }
    if(leftAns.size() == 0 && rightAns.size() == 0){vector<int>v; return v;}
    else if(leftAns.size() != 0)
    {
        leftAns.push_back(root->data);
        return leftAns;
    }
    else if(rightAns.size() != 0)
    {
        rightAns.push_back(root->data);
        return rightAns;
    }

}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    vector<int> path= pathFinder(root,3);
    cout <<endl;
    cout <<endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout<< path[i] <<" ";
    }

}