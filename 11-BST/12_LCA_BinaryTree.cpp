// LCA: lowest common ancestor  ... (2 nodes of a tree are given... their LCA is a node which is a common grandParent/parent to both... a common ancestor/"family-relative" to both)
// for example... mera aur "kuku-bhaiya" ka common ancestor hue "dadaji" ... mera aur "sahaj" mae hue "papa"

// If amongst 2 given node...one itself is parent/grandparent of the other...then obviously we will return that node only....
// If one of the given node does not exist in tree we'll return the one present in tree
// IF BOTH NOT PRESENT, RETURN NULL


// A simple and interesting code...(couldn't think the first time...so try urself)


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


int LCA(BinaryTreeNode<int>* root, int n1, int n2)
{
    if(root==NULL) return INT_MIN;              // I am using "INT_MIN" as a sign.... that the 
    if(root->data==n1 || root->data==n2)        // number is not present
    {
        return root->data;
    }

    int a= LCA(root->left,n1,n2);
    int b= LCA(root->right,n1,n2);

    if(a==INT_MIN && b==INT_MIN) return INT_MIN;
    if(a!=INT_MIN && b!=INT_MIN) return root->data;
    if(a!= INT_MIN) return a;
    return b;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvl_Wise();
    cout <<endl;

    cout<<LCA(root,12,78)<<endl;

    return 0;
}

