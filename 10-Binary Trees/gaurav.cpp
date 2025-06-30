// Mirror tree has all the "left & right nodes swapped"

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

void lvl_Wise_printer(BinaryTreeNode<int>*root)
{
    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL)
        {
            cout <<endl;
            if(!pendingNodes.empty()) pendingNodes.push(NULL);      // we set the if condition to prevent the formation of a loop of "nulls" after going thru all the elements and the last null it would continue returning null and pushing another null and then poping null and inserting another null
        }

        else
        {
            cout<< front->data <<" ";
            if(front->left != NULL) pendingNodes.push(front->left);
            if(front->right != NULL) pendingNodes.push(front->right);
        }
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

void mirror(BinaryTreeNode<int>* root)
{
    if(root==NULL) return;
    BinaryTreeNode<int>* temp= root->left;     // even if "root->left" is null... temp can manage it
    root->left= root->right;
    root->right= temp;

    mirror(root->left);
    mirror(root->right);
}

int main(){
    BinaryTreeNode<int>* root= takeakeInput_lvl_Wise();

    cout <<endl;
    cout <<endl;
    mirror(root);
    lvl_Wise_printer(root);
    return 0;
}