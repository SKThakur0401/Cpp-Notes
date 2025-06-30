// HEIGHT OF THE TREE ----> NUMBER OF NODES IN THE LONGEST CHAIN

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

void printTree_levelWise(treenode<int>* root)
{
    if(root==NULL){return;}
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        treenode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data<<": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout<< front->children[i]->data <<",";
            pendingNodes.push(front->children[i]);
        }
        cout <<endl;
    }
}

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

int height(treenode<int>* root)
{
    int max=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int height_of_this_particular_route = 1 + height(root->children[i]);
        if(height_of_this_particular_route > max){max= height_of_this_particular_route;}
    }

    if (root->children.size()==0)
    {
        return 1;           // the case where a node has no further nodes... so its height "1" shld be taken into account
    }
    
    return max;
}

int main(){

    treenode<int>* root = takeInput_levelWise();
    cout<< "Height of the tree is : "<< height(root) <<endl;

    return 0;
}

