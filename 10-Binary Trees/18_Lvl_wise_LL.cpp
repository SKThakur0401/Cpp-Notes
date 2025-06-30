// NOT AN EASY QUESTION.... BUT DID IT MYSELF AFTER SOME BRAIN-STORMING....


// Chapter Assignment
// Problem Statement: Level wise linkedlist
// Problem Level: MEDIUM
// Problem Description:
// Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

// Output format :
// Each level linked list is printed in new line (elements are separated by space).

// Constraints:
// Time Limit: 1 second

// Sample Input 1:
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1:
// 5 
// 6 10 
// 2 3 
// 9



#include "00BinaryTree.h"

#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(){}
    node(int data)
    {
        this->data=data;
        next= NULL;         // REMEMBER TO MAKE IT NULL... 
                            // COZ U WILL SOLVE ASSUMING IT TO BE NULL... AND IT CAN CREATE A BIG FUSS IN SOME QUESTS...
    }
};


vector<node*> LLiser(BinaryTreeNode<int>* root)
{
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    int i=0;

    vector<node*> headList;
    node* head = NULL;
    node* tail = NULL;

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        if(front== NULL)
        {
            if(!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
                i++;
            }
        }

        else
        {
            if(front->left != NULL) pendingNodes.push(front->left);
            if(front->right != NULL) pendingNodes.push(front->right);

            node* newNode= new node(front->data);
            if(i == headList.size())
            {
                headList.push_back(newNode);
                head= newNode;
                tail=newNode;
            }
            
            else
            {
                tail->next= newNode;
                tail= tail->next;
            }
        }
    }
    return headList;
}


vector<node<int> * > LLiser_madeLater_sameComplexity_cleanerCode(BinaryTreeNode<int>* root)
{
    vector<node<int>* > headList;
    if(!root) return headList;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    node<int>* head =NULL;
    node<int>* tail =NULL;

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front== NULL)
        {
            headList.push_back(head);
            head=NULL; tail=NULL;
            if(!pendingNodes.empty()) pendingNodes.push(NULL);
            continue;
        }

        node<int>* newNode = new node<int>(front->data);

        if(head == NULL)
        {
            head= newNode;
            tail= newNode;
        }

        else
        {
            tail->next= newNode;
            tail=tail->next;
        }

        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);
    }

    return headList;
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    vector<node*> headList = LLiser(root);

    for (int i = 0; i < headList.size(); i++)
    {
        node* head= headList[i];
        while(head != NULL)
        {
            cout<< head->data <<" ";
            head=head->next;
        }
        cout <<endl;
    }
}


