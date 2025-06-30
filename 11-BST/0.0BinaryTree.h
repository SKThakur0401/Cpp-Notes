#include<iostream>
#include<climits>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data)
    {
        this->data= data;
        left= NULL;
        right= NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput_lvlWise()
{
    int rootData; cin>>rootData;
    if(rootData== -1) {return NULL;}
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "Enter left of "<<front->data <<" : ";
        int l; cin>>l;
        if(l != -1)
        {
            BinaryTreeNode<int>* nodel= new BinaryTreeNode<int>(l);
            front->left= nodel;
            pendingNodes.push(nodel);
        }

        cout<< "Enter right of "<<front->data <<" : ";
        int r; cin>>r;
        if (r != -1)
        {
            BinaryTreeNode<int>* noder= new BinaryTreeNode<int>(r);
            front->right= noder;
            pendingNodes.push(noder);
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

void print(BinaryTreeNode<int>* root)
{
    if(root == NULL){return;}
    cout<< root->data <<": ";
    if (root->left != NULL)
    {
        cout<< "L-"<<root->left->data  <<",";
    }
    if (root->right != NULL)
    {
        cout<< "R-"<<root->right->data <<" ";
    }
    cout <<endl;

    print(root->left);
    print(root->right);
}

BinaryTreeNode<int>* takeInput()
{
    cout<< "Enter data :" <<endl;
    int rootData;  cin>>rootData;
    if(rootData== -1){return NULL;}

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);

    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild= takeInput();
    root->left= leftChild;
    root->right= rightChild;
    return root;
}
