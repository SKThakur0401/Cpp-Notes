// Creating BST CLASS

#include "0.0BinaryTree.h"
using namespace std;

class BST
{
    public:
    BinaryTreeNode<int>* root;

    BST() {}

    BST(BinaryTreeNode<int>* root)
    {
        this->root= root;
    }

    private:

    bool hasData(BinaryTreeNode<int>* root, int data)
    {
        if(root == NULL) return false;
        if(root->data == data) return true;

        if(root->data < data) return hasData(root->right , data);
        if(root->data > data) return hasData(root->left, data);
        return true;
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int data)
    {
        if(root == NULL)
        {
            root= new BinaryTreeNode<int>(data);
            return root;
        }

        if(root->data <= data)
        {
            root->right = insert(root->right, data);
        }
        if(root->data > data)
        {
            root->left = insert(root->left, data);
        }
        return root;
    }

    BinaryTreeNode<int>* del(BinaryTreeNode<int>* root, int data )
    {
        if(root == NULL) return root;

        if(root->data == data)
        {
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }

            if(root->left && root->right)
            {
                BinaryTreeNode<int>* min = minBTN(root->right);
                root->data = min->data;

                root->right = del(root->right ,min->data);
                return root;
            }

            if(!root->right)
            {
                BinaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }

            if(!root->left)
            {
                BinaryTreeNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
        }

        if(data < root->data)
        {
            root->left = del(root->left, data);
        }

        if(data > root->data)
        {
            root->right = del(root->right, data);
        }
        return root;
    }

    public:
    bool hasData(int data)
    {
        return hasData(root, data);
    }

    BinaryTreeNode<int>* insert(int data)
    {
        return insert(root, data);
    }

    BinaryTreeNode<int>* minBTN(BinaryTreeNode<int>* root)
    {
        if(root->left) return minBTN(root->left);
        return root;
    }

    BinaryTreeNode<int>* del(int data)
    {
        return del(root, data);
    }
};


BinaryTreeNode<int>* leftCopy(BinaryTreeNode<int>* root)
{
    if(!root) return NULL;
    BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* rl = root->left;
    root->left= temp;
    temp->left = rl;
    
    // root->left = leftCopy(root);
    root->right = leftCopy(root->right);
    rl = leftCopy(rl);

    return root;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    // BST meriTree(root);
    cout <<endl;
    cout <<endl;
    // meriTree.insert(31);
    // cout<< meriTree.hasData(31) <<endl;
    // meriTree.insert(88);
    // cout<< meriTree.hasData(88) <<endl;

    // root=meriTree.insert(4);
    // root=meriTree.insert(9);
    // root=meriTree.insert(8);
    // root=meriTree.insert(5);
    // root=meriTree.del(4);
    // root=meriTree.del(9);
    // root=meriTree.del(8);
    // root=meriTree.del(5);
    root= leftCopy(root);

    print_lvl_Wise(root);
}

