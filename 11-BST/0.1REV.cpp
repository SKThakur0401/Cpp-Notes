#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {       
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput_lvl_Wise()
{
    int rootData; cin>>rootData;
    if(rootData== -1)return NULL;

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        int leftData; cin>> leftData;
        if(leftData != -1)
        {
            front->left= new BinaryTreeNode<int>(leftData);
            pendingNodes.push(front->left);
        }

        int rightData; cin>> rightData;
        if(rightData != -1)
        {
            front->right= new BinaryTreeNode<int>(rightData);
            pendingNodes.push(front->right);
        }
    }
    return root;
}

void print_lvl_Wise(BinaryTreeNode<int>* root)
{
    if(root== NULL){return;}

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data <<": ";
        if (front->left != NULL)
        {
            cout<< "L-"<<front->left->data <<",";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout<< "R-"<<front->right->data <<",";
            pendingNodes.push(front->right);
        }
        cout <<endl;
    }
}

class BST
{
    public:
    BinaryTreeNode<int>* root;

    BST(BinaryTreeNode<int>* root)
    {
        this->root=root;
    }

    bool hasData(int data)
    {
        return hasData(data,root);
    }
    BinaryTreeNode<int>* insert(int data)
    {
        return insert(data,root);
    }
    BinaryTreeNode<int>* del(int data)
    {
        return del(data,root);
    }

    BinaryTreeNode<int>* minNode(BinaryTreeNode<int>* root)
    {
        if(root->left == NULL) return root;
        return minNode(root->left);
    }
    private:
    bool hasData(int data, BinaryTreeNode<int>* root)
    {
        if(data== root->data) return true;
        if(root==NULL) return false;
        if(data > root->data)
        {
            return hasData(data,root->right);
        }

        if(data < root->data)
        {
            return hasData(data,root->left);
        }
    }

    BinaryTreeNode<int>* insert(int data , BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            root= new BinaryTreeNode<int>(data);
            return root;
        }

        else if(root->data > data)
        {
            root->left= insert(data,root->left);
        }

        else if(root->data < data)
        {
            root->right= insert(data,root->right);
        }
        return root;
    }

    BinaryTreeNode<int>* del(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL) return NULL;

        if(root->data== data)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }

            else if(root->left!=NULL && root->right!=NULL)
            {
                BinaryTreeNode<int>* min= minNode(root->right);
                root->data= min->data;

                // delete min;  // This gives "inaccurate results"... the line below gives correct result

            //  root->left= del(min->data,root->left); // this is not required  since we know that "min->data" is present in "root-right" its useless/stupid to call this function on the left half...
                root->right= del(min->data,root->right);
                return root;
            }

            else if(root->left != NULL)
            {
                return root->left;
            }
            else
            {
                return root->right;
            }
        }

        else if(root->data > data)
        {
            root->left= del(data,root->left);
        }
        else
        {
            root->right= del(data,root->right);
        }
        return root;
    }

};

int main(){
    BinaryTreeNode<int>* root= takeInput_lvl_Wise();
    BST s(root);
    root= s.insert(1);
    root= s.insert(3);
    root= s.insert(5);
    root= s.insert(7);
    root= s.insert(14);
    root= s.insert(21);
    root= s.insert(28);
    root= s.insert(35);
    root= s.insert(42);
    root= s.insert(49);
    root=s.del(16);
    root=s.del(64);
    cout <<endl;
    cout <<endl;
    cout <<endl;
    print_lvl_Wise(root);

    return 0;
}

// 16 4 64 2 8 32 128 -1 -1 -1 -1 -1 -1 -1 -1