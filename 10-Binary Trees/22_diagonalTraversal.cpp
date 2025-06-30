#include "00BinaryTree.h"
using namespace std;

void leveling(BinaryTreeNode<int>* root, int d, vector<vector<int> > &vice)
{
    if(!root) return;
    else if(vice.size() == d)
    {
        vector<int> a;
        vice.push_back(a);
        vice[d].push_back(root->data);
    }

    else
    {
        vice[d].push_back(root->data);
    }
    leveling(root->right, d, vice);
    leveling(root->left,d+1, vice);
}

void diagonalTraversal(BinaryTreeNode<int>* root)
{
    int d=0;
    vector<vector<int> > vice;
    leveling(root, d, vice);

    for (int i = 0; i < vice.size(); i++)
    {
        for (int j = 0; j < vice[i].size(); j++)
        {
            cout<< vice[i][j] <<" ";
        }
        cout <<endl;
    }
    
}


int main(){

    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    diagonalTraversal(root);

    return 0;
}

