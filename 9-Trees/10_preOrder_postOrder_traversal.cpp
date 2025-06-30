// THERE ARE 2 WAYS TO PRINT A TREE...ONE IS GOING TOP TO BOTTOM (that is .. starting from root and then printing children ... this is called "preorder")
// Other is bottom to top ... where we start from the bottom most node...(which does not have any children) and then start going upwards...

// Note: this is printing tree using recursion!!!! (So don't think about "level-wise" or anything...)...this is normal recursion based printing... and 2 ways to do that :)
// the code for pre-order and post-order are very easy...
// revise how the recursion is working in both cases...

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode<T>*> children;
    treenode(T data)
    {
        this->data=data;
    }
};

treenode<int>* takeInput_levelWise()
{
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while (!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"How many Children does "<<front->data<<" have: ";
        int numChild; cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout<< "Enter "<<i+1<<"th child of "<<front->data<<" : ";
            int data; cin>>data;
            treenode<int>* child = new treenode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void preorder(treenode<int>* root)
{
    cout<< root->data<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(treenode<int>* root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout<< root->data<<" ";
}

int main(){

    treenode<int>* root= takeInput_levelWise();

    cout <<endl;
    cout <<endl;
    cout<< "Pre-order :" <<endl;
    preorder(root);
    cout <<endl;
    cout <<endl;

    cout<< "Post-order :" <<endl;
    postorder(root);

    return 0;
}
// 1 2 2 3 2 4 8 2 9 27 0 0 0 0