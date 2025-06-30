#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right= NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput(){
    cout<< "Enter input : ";
    int rootData; cin>>rootData;
    BinaryTreeNode<int>* root;
    queue<BinaryTreeNode<int>*> pendingNodes;
    if(rootData != -1){
        root = new BinaryTreeNode<int>(rootData);
        pendingNodes.push(root);
    }

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        int lData; cin>>lData;
        if(lData != -1) {
            front->left = new BinaryTreeNode<int>(lData);
            pendingNodes.push(front->left);
        }
        
        int rData; cin>>rData;
        if(rData != -1) {
            front->right = new BinaryTreeNode<int>(rData);
            pendingNodes.push(front->right);
        }
    }

    return root;
}

void printBT(BinaryTreeNode<int>* root){
    if(!root) return;
    cout<< root->data << " : ";
    if(root->left  ) cout<<root->left->data<<"  |  ";
    if(root->right) cout<<root->right->data;
    cout <<endl;

    printBT(root->left);
    printBT(root->right);
}

void printLvlWise(BinaryTreeNode<int>* root){

    if(!root) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL && pendingNodes.front() == NULL) break;

        if(front == NULL && pendingNodes.front() != NULL){
            pendingNodes.push(NULL);
            cout <<endl;
            continue;
        }

        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);

        cout<< front->data <<"  ";
    }
}

int countLeaf(BinaryTreeNode<int>* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

bool isPresent(BinaryTreeNode<int>* root, int n){
    if(!root) return false;
    return root->data == n || isPresent(root->left, n) || isPresent(root->right, n);
}

int main(){

    BinaryTreeNode<int>* root = takeInput();

    printLvlWise(root);
    cout <<endl;
    cout<< "Leaf count - "<< countLeaf(root) <<endl;
}

