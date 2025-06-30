// BINARY TREES ARE TREES WHICH "ATMOST HAVE 2 NODES" ... HERE WE CALL 2 NODES AS LEFT ADND RIGHT NODE
// NOTE A BINARY TREE WITH "LEFT NODE=2 AND RIGHT=3"    AND A BINARY TREE HAVING "LEFT=3 AND RIGHT=2" ARE NOT SAME...

// SINCE WE HAVE DONE "GENERIC TREES FIRST" ... TAKING/PRINTING INPUT RECURSIVELY AND LEVEL-WISE WILL EASIER HERE (BCOZ IT IS A SPECIAL CASE WHERE EACH TREE HAS ATMOST 2 NODES :)

#include<iostream>
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
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;                // Note: even if "left is equal to NULL"... delete keyword will 
        delete right;               // ignore it and not give error... same with right...
    }
};

void print(BinaryTreeNode<int>* root)
{
    if(root == NULL){return;}
    cout<< root->data <<": ";

    if(root->left != NULL)
    {
        cout<<"L "<< root->left->data<<" , ";
    }

    if (root->right != NULL)
    {
        cout<<"R "<< root->right->data <<" , ";
    }
    cout <<endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int>* takeInput()
{
    cout<< "Enter data :" <<endl;
    int rootData; cin>>rootData;
    if(rootData != -1)
    {
        BinaryTreeNode<int>* left= takeInput();
        BinaryTreeNode<int>* right= takeInput();
    }
}

int main()
{
    // BinaryTreeNode<int>* root= new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1= new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2= new BinaryTreeNode<int>(3);
    // root->left= node1;
    // root->right= node2;

    BinaryTreeNode<int>* root= takeInput();


    print(root);
}