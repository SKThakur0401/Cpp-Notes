#include<iostream>
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
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

template <typename T>
BinaryTreeNode<T>* takeInput()
{
    int rootData; cin>>rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    

    BinaryTreeNode<T>* root= new BinaryTreeNode<T>(rootData);
    root->left= takeInput<T>();
    root->right= takeInput<T>();

    return root;
}


template <typename T>
void print(BinaryTreeNode<T>* root)
{
    if (root== NULL)
    {
        return;
    }
    
    cout<<root->data<<": ";
    if(root->left != NULL) cout<<"L-"<<root->left->data<<",";
    if(root->right != NULL) cout<<"R-"<<root->right->data;
    cout <<endl;
    print(root->left);
    print(root->right);
}

template <typename T>
BinaryTreeNode<T>* takeInput_lvl_Wise()
{
    T rootData; cin>>rootData;

    if(rootData == -1) return NULL;

    BinaryTreeNode<T>* root= new BinaryTreeNode<T>(rootData);

    queue<BinaryTreeNode<T>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<T>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "Left of "<<front->data<<" is : ";
        T l; cin>>l;
        if(l != -1)
        {
            front->left= new BinaryTreeNode<T>(l);
            pendingNodes.push(front->left);
        }

        cout<< "Right of "<<front->data<<" is : ";
        T r; cin>>r;
        if(r != -1)
        {
            front->right= new BinaryTreeNode<T>(r);
            pendingNodes.push(front->right);
        }
    }
    return root;
}


int main(){
    BinaryTreeNode<int>* root= takeInput_lvl_Wise<int>();
    cout <<endl;
    cout <<endl;
    print<int>(root); 
    return 0;
}
