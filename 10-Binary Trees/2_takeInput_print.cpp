#include<iostream>
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

BinaryTreeNode<int>* takeInput()     // Note: instead of for "int" we could have used a template..
{                                    // I have written the code for template "takeInput" below...
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

// template <typename T>             // Does the same thing as above...but for all data-types :)
// BinaryTreeNode<T>* takeInput()
// {
//     int rootData; cin>>rootData;
//     if (rootData == -1)
//     {
//         return NULL;
//     }
//     BinaryTreeNode<T>* root= new BinaryTreeNode<T>(rootData);
//     root->left= takeInput<T>();
//     root->right= takeInput<T>();
//     return root;
// }

int main(){
    BinaryTreeNode<int>* root= takeInput();
    print(root); 
    return 0;
}

