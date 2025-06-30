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

void inorder(binaryTreeNode<int>* root, vector<int> &arr)
{
    if(root==NULL) return;

    inorder(root->right,arr);

    arr.push_back(root->data);

    inorder(root->left,arr);

}

void customise(binaryTreeNode<int>* &root, vector<int> &arr)
{
    if(root==NULL) return;
    root->data=arr[arr.size()-1];
    arr.pop_back();
    customise(root->left, arr);
    customise(root->right, arr);
}



int main(){

    vector<int> arr;
    binaryTreeNode<int> * root= takeInput();

    inorder(root,arr);      // Inserts all element of "binary tree" in the vector-"arr" in inorder 

    customise(root, arr);

    print(root);
    return 0;
}
