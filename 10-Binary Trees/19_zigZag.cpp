// Chapter Assignment
// Problem Statement: ZigZag tree
// Problem Level: HARD
// Problem Description:
// Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
// Input format :
// Elements in level order form (separated by space)
// (If any node does not have left or right child, take -1 in its place)
// Output Format :
// Elements are printed level wise, each level in new line (separated by space).

// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output :
// 5
// 10 6
// 2 3
// 9


#include "00BinaryTree.h"


void print_zigZag(BinaryTreeNode<int>* root)        // My Solution To The Question Above :)
{
    queue <BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    vector<int> OneLevel;
    int i=0;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        if(front== NULL)
        {
            if(!pendingNodes.empty()) {pendingNodes.push(NULL);}
            if (i%2 == 0)
            {
                for (int j = 0; j < OneLevel.size(); j++)
                {
                    cout<<OneLevel[j]<<" ";
                }
                cout <<endl;
            }
            else if (i%2 == 1)
            {
                for (int j = OneLevel.size() -1; j >=0; j--)
                {
                    cout<<OneLevel[j]<<" ";
                }
                cout <<endl;
            }
            while(OneLevel.size() != 0)
            {
                OneLevel.pop_back();
            }
            i++;
        }

        else
        {
            if(front->left != NULL) {pendingNodes.push(front->left);}
            if(front->right !=NULL) {pendingNodes.push(front->right);}

            OneLevel.push_back(front->data);
        }
    }
}

void zigzag(BinaryTreeNode<int>* root)      // Using 2 stacks mechanism, As given by CODING NINJAS
{
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;

    s1.push(root);
    while(!s1.empty() ||  !s2.empty())
    {
        while(!s1.empty())
        {
            if(s1.top()->left != NULL) s2.push(s1.top()->left);
            if(s1.top()->right != NULL) s2.push(s1.top()->right);

            cout<<s1.top()->data<<" ";
            s1.pop();
        }

        cout <<endl;

        while(!s2.empty())
        {
            if(s2.top()->right != NULL) s1.push(s2.top()->right);
            if(s2.top()->left != NULL) s1.push(s2.top()->left);

            cout<<s2.top()->data<<" ";
            s2.pop();
        }
        cout <<endl;
    }
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout <<endl;
    zigzag(root);
    cout <<endl;
    cout <<endl;
    cout <<endl;
    print_zigZag(root);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1