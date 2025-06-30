#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class treenode
{ 
    public:
    T data;
    vector<treenode*> children;
    treenode(T data)
    {
        this->data= data;
    }
    ~treenode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};


treenode<int>* takeInput()
{
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);

    cout<< "How many children Does "<<rootData<<" have : " <<endl;
    int numChild; cin>>numChild;

    for (int i = 0; i < numChild; i++)
    {
        cout<< "Enter "<<i+1<<"th child of "<<root->data<<" : ";

        treenode<int>* child= takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(treenode<int>* root)
{
    cout<< root->data <<": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<< root->children[i]->data <<",";
    }
    cout <<endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

treenode<int>* takeInput_levelWise()
{
    cout<< "Enter rootData : ";
    int rootData; cin>>rootData;
    if(rootData== -1) return NULL;
    treenode<int>* root= new treenode<int>(rootData);
    queue<treenode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter how many children "<<front->data<<" have: ";
        int numChild; cin>>numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout<< "Enter "<<i+1<<"th child of "<<front->data<<" : ";
            int childData; cin>>childData;
            treenode<int>* child= new treenode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


int countNodes(treenode<int>* root)
{

    if(root== NULL) return 0;
    int c=1;
    for (int i = 0; i < root->children.size(); i++)
    {
        c+=  countNodes(root->children[i]);
    }
    return c;
}

int maxima(treenode<int>* root)     // returns the node with maximum data
{
    int max= root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int testing= maxima(root->children[i]);

        if(testing> max) max= testing;
    }
    return max;
}

int height(treenode<int>* root)     // returns the longest chain from "root"
{
    if(root==NULL) return 0;
    int hmax=1;

    for (int i = 0; i < root->children.size(); i++)
    {
        int testing= 1+ height(root->children[i]);
        if(testing >hmax) hmax= testing;
    }
    return hmax;
}

bool identical(treenode<int>* a, treenode<int>* b)  // returns true if 2 given trees r identical
{
    if(a->data != b->data  ||  a->children.size() != b->children.size()) return false;

    for (int i = 0; i < a->children.size(); i++)
    {
        bool x= identical(a->children[i],b->children[i]);
        if(x== false) return false;
    }
    return true;
}

pair<int, int> Summer(treenode<int>* root)     // returns sum of father and its 'immediate' children
{
    int sum= root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum+= root->children[i]->data;
    }
    pair<int, int> p;
    p.first= root->data;
    p.second=sum;

    return p;
}

int answer(treenode<int>* root)
{
    pair<int, int> p= Summer(root);
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<int,int> x= Summer(root->children[i]);
        if(x.second> p.second) p= x;
    }
    return p.first;
}


int nextLarger(treenode<int>* root, int n)  // returns element just larger than "n" present in tree
{
    int min= INT_MAX;

    if(root->data > n) min= root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        int x= nextLarger(root->children[i],n);
        if(x < min) min= x;
    }
    return min;
}

void depthify(treenode<int>* root, int k=0)     // replaces all node data with its depth :)
{
    root->data= k;
    for (int i = 0; i < root->children.size(); i++)
    {
        depthify(root->children[i],k+1);
    }
}


int main(){
    treenode<int>* root= takeInput_levelWise();
    printTree(root);
    cout <<endl;
    cout <<endl;

    cout<< "Total number of nodes: "<<countNodes(root) <<endl;
    cout<< "Largest data in a node: "<<maxima(root) <<endl;
    cout<< "Height of tree: "<<height(root) <<endl;
    cout<< "Answer to SumQuest : "<<answer(root) <<endl;
    cout<<"Next Larger : "<<nextLarger(root,18) <<endl;

    depthify(root);
    printTree(root);
    return 0;
}