// The function "find" takes a tree and an integer as argument... and returns true if that integer is present in the tree, returns false otherwise;

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode*> children;
    treenode(T data){this->data=data;}
    ~treenode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
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

bool find(treenode<int>*root, int n)    // returns true if "n" is present in tree...returns false elsewise
{
    if(root->data == n){return true;}
    for (int i = 0; i < root->children.size(); i++)
    {
        bool b = find(root->children[i],n);
        if(b==true){return true;}
    }
    return false;
}

int biggerNodes(treenode<int>*root,int x)       // THIS COUNTS HOW MANY NODES IN TREE are bigger than "x"
{
    int count=0;
    if(root->data > x){count++;}
    for (int i = 0; i < root->children.size(); i++)
    {
        count+= biggerNodes(root->children[i],x);
    }
    return count;
}

int main(){

    treenode<int>* root= takeInput_levelWise();
    cout <<endl;
    cout <<endl;
    cout <<endl;
    // cout<< find(root,10) <<endl;
    cout<< biggerNodes(root,10) <<endl;
    
    return 0;
}