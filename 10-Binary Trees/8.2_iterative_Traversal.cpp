// Here we have done the "iterative solution of pre-order, in-order & post-order" traversal

#include "00BinaryTree.h"
#include<stack>
using namespace std;

void inorder(BinaryTreeNode<int>* root)
{
    stack<BinaryTreeNode<int>* > st;
    BinaryTreeNode<int>* curr= root;
    while(!st.empty() || curr != NULL)
    {
        while(curr !=NULL)
        {
            st.push(curr);
            curr= curr->left;
        }

        curr= st.top();
        st.pop();
        cout<< curr->data <<" ";
        curr= curr->right;
    }
}

void preorder(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root;

    stack<BinaryTreeNode<int>* > s;
    s.push(root);

    while(!s.empty())
    {
        BinaryTreeNode<int>* curr= s.top();
        s.pop();
        cout<< curr->data <<" ";
        
        if(curr->right != NULL) s.push(curr->right);

        if(curr->left != NULL) s.push(curr->left);
    }
}

void postorder(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root;
    stack<BinaryTreeNode<int>*> s;
    stack<BinaryTreeNode<int>*> t;
    s.push(root);

    while(!s.empty())
    {
        BinaryTreeNode<int>* curr= s.top();

        // if(curr->left != NULL) s.push(curr->left);
        // if(curr->right != NULL) s.push(curr->right);

        // cout<< s.top() <<" ";

        s.pop();

        t.push(curr);

        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
    }

    while(!t.empty())
    {
        cout<< t.top()->data <<" ";
        t.pop();
    }
}



int main(){

    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    inorder(root);

    cout <<endl;
    preorder(root);

    cout <<endl;
    postorder(root);

    
    return 0;
}

