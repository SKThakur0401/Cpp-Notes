#include "0.0BinaryTree.h"

class BST
{
    public:
    BinaryTreeNode<int>* root;
    BST(BinaryTreeNode<int>* root)
    {
        this->root = root;
    }
    ~BST() { delete root; }

    bool hasData(int data)
    {
        return hasData(root,data);
    }

    BinaryTreeNode<int>* insert(int data)
    {
        return insert(root,data);
    }

    BinaryTreeNode<int>* del(int data)
    {
        return del(root,data);
    }

    BinaryTreeNode<int>* minNode(BinaryTreeNode<int>* root)
    {
        if(root->left==NULL) return root;
        return minNode(root->left);
    }

    private:

    bool hasData(BinaryTreeNode<int>*root,int data)
    {
        if(root==NULL) return false;
        if(root->data == data) return true;

        else if(root->data > data)
        {
            return hasData(root->left,data);
        }

        else
        {
            return hasData(root->right,data);
        }
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root,int data)
    {
        if(root==NULL)
        {
            root= new BinaryTreeNode<int>(data);
            return root;
        }

        else if(root->data > data)
        {
            root->left= insert(root->left,data);
        }

        else
        {
            root->right= insert(root->right,data);
        }

        return root;
    }

    BinaryTreeNode<int>* del(BinaryTreeNode<int>* root,int data)
    {
        if(root->data== data)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                BinaryTreeNode<int>* temp= root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                BinaryTreeNode<int>* temp= root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int>* mint= minNode(root->right);
                root->data= mint->data;
                // delete mint;       // This gives "inaccurate results"... the line below gives correct result
                root->right= del(root->right, mint->data);
                return root;
            }
        }

        else if(root->data > data)
        {
            root->left= del(root->left,data);
        }

        else if(root->data < data)
        {
            root->right= del(root->right,data);
        }
        return root;
    }
};

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    BST meriTree(root);
    cout <<endl;
    cout <<endl;
    // meriTree.insert(31);
    cout<< meriTree.hasData(31) <<endl;
    // meriTree.insert(88);
    cout<< meriTree.hasData(88) <<endl;

    root=meriTree.insert(4);
    root=meriTree.insert(9);
    root=meriTree.insert(8);
    root=meriTree.insert(5);
    root=meriTree.del(4);
    root=meriTree.del(9);
    root=meriTree.del(8);
    root=meriTree.del(5);


    print_lvl_Wise(root);
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

// 10 6 14 2 8 11 18 -1 -1 -1 -1 -1 -1 -1 -1
