#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template <typename T>
class binaryTreeNode
{
    public:

    T data;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;

    binaryTreeNode(T data)
    {
        this->data= data;
        left=NULL;
        right=NULL;
    }
    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

binaryTreeNode<int>* takeInput()
{
    int rootData; cin>>rootData;
    if(rootData== -1) return NULL;
    binaryTreeNode<int>* root= new binaryTreeNode<int>(rootData);

    root->left= takeInput();
    root->right= takeInput();

    return root;
}

void print(binaryTreeNode<int> * root)
{
    if(root==NULL) return;
    cout<<root->data<<" : ";
    if(root->left !=NULL) cout<< root->left->data<<",";
    if(root->right !=NULL) cout<< root->right->data;
    cout <<endl;
    print(root->left);
    print(root->right);
}

void print_lvlWise(binaryTreeNode<int> * root)
{
    if(root==NULL) return;

    queue<binaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        binaryTreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();

        cout<< front->data <<" :";

        if(front->left!=NULL)
        {
            pendingNodes.push(front->left);
            cout<< front->left->data <<",";
        }

        if(front->right!=NULL)
        {
            pendingNodes.push(front->right);
            cout<< front->right->data;
        }
        cout <<endl;
    }
}

binaryTreeNode<int>* takeInput_lvlWise()
{
    int rootData; cin>>rootData;
    binaryTreeNode<int>* root= new binaryTreeNode<int>(rootData);

    queue<binaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        binaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        int lrd;
        cin>>lrd;
        if(lrd== -1) front->left= NULL;
        else
        {
            front->left= new binaryTreeNode<int>(lrd);
            pendingNodes.push(front->left);
        }
        
        int rrd;
        cin>>rrd;
        if(rrd==-1) front->right=NULL;
        else
        {
            front->right= new binaryTreeNode<int>(rrd);
            pendingNodes.push(front->right);
        }
    }
    return root;
}

int main()
{
    binaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    print(root);
    cout <<endl;
    print_lvlWise(root);

    return 0;
}