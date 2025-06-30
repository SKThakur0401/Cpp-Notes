// HERE WE WROTE A SIMPLE FUNCTION : "countLeaf" .... a "leaf" is the ending of a node or a branch or a chain..... "when there are no further branches/children"

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode*> children;
    treenode(T data){this->data=data;}
};

treenode<int>* takeInput_levelWise()
{
    cout<< "Enter root data :";
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);

    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        treenode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< "How many children does "<<front->data<<" have : ";
        int numChild; cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout<< "Enter "<<i+1<<"th child of "<<front->data<<" : " <<endl;
            int childData; cin>>childData;
            treenode<int>*child= new treenode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

int countLeaf(treenode<int>* root)
{
    int count=0;
    if(root->children.size() == 0){return 1;}
    
    for (int i = 0; i < root->children.size(); i++)
    {
        count+= countLeaf(root->children[i]);
    }
    return count;
}

int main(){

    treenode<int>* root = takeInput_levelWise();

    cout<< "Total no. of leaves = "<<countLeaf(root) <<endl;
    return 0;
}
