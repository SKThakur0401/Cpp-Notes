#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};


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

BinaryTreeNode<int>* takeakeInput_lvl_Wise()
{
    int rootData; cin>>rootData;
    if(rootData== -1){return NULL;}

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        cout<< "left of "<<front->data<<" is : ";
        int leftData; cin>>leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int>* left= new BinaryTreeNode<int>(leftData);
            pendingNodes.push(left);
            front->left= left;
        }
        else{front->left= NULL;}


        cout<< "right of "<<front->data<<" is : ";
        int rightData; cin>>rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int>* right= new BinaryTreeNode<int>(rightData);
            pendingNodes.push(right);
            front->right=right;
        }
        else{front->right=NULL;}
    }
    return root;
};

int main(){
    BinaryTreeNode<int>* root= takeakeInput_lvl_Wise();
    cout <<endl;
    cout <<endl;
    print_lvl_Wise(root); 
    return 0;
}