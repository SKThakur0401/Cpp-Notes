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

int nextLarger(treenode<int>*root, int n)
{
    int min=999999;     // A very large no.  ... ideally one should import "climits" and use MAX_INT
    if(root->data >n){min=root->data;}

    for (int i = 0; i < root->children.size(); i++)
    {
        int x= nextLarger(root->children[i],n);
        if(x< min){min=x;}
    }
    return min;
}

int main(){


    treenode<int>* root= takeInput_levelWise();

    cout <<endl;
    cout <<endl;

    cout<< nextLarger(root, 21) <<endl;


    return 0;
}