// Not an easy question!!!  U are given a BST .... U have to convert it to a sorted linked list.... we also call it "Flatten the BST problem"

#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void printNodes(node* head)
{
    while(head != NULL)
    {
        cout<< head->data <<" ";
        head=head->next;
    }
}


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


pair<node*,node*> BST_to_LL(BinaryTreeNode<int>* root)
{
    if(root->left == NULL && root->right==NULL)
    {
        node* rootNode= new node(root->data);
        pair<node*,node*> p;
        p.first=rootNode;
        p.second=rootNode;
        return p;
    }

    else if(root->left == NULL)
    {
        pair<node*,node*> rP= BST_to_LL(root->right);
        node* rootNode= new node(root->data);
        rootNode->next=rP.first;
        rP.first= rootNode;
        return rP;
    }

    else if(root->right == NULL)
    {
        pair<node*,node*> lP= BST_to_LL(root->left);
        node* rootNode= new node(root->data);

        lP.second->next= rootNode;
        lP.second=rootNode;
        return lP;
    }


    else if(root->left != NULL && root->right !=NULL)
    {
        pair<node*,node*> lP= BST_to_LL(root->left);
        pair<node*,node*> rP= BST_to_LL(root->right);

        node* rootNode= new node(root->data);
        lP.second->next= rootNode;
        rootNode->next= rP.first;
        lP.second= rP.second;

        return lP;
    }
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    node* head= BST_to_LL(root).first;
    printNodes(head);
}

