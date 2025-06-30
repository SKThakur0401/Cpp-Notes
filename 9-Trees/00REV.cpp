#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class treenode
{ 
    public:
    T data;
    vector <treenode*> children;
    treenode(T data)
    {
        this->data=data;
    }

    // ~treenode
    // {
    //     for (int i = 0; i < root->children.size(); i++)
    //     {
    //         delete root->children[i];
    //     }
        
    // }
};


void printTree(treenode<int>* root)
{
    cout<< root->data<<": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<< root->children[i]->data<<",";
    }

    cout <<endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
} 


treenode<int>* takeInput()
{
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);

    cout<< "How many children Does "<<rootData<<" have : ";
    int numChild; cin>>numChild;

    for (int i = 0; i < numChild; i++)
    {
        cout<< "Enter "<<i+1<<"th child of "<<root->data<<" : ";

        treenode<int>* child= takeInput();
        root->children.push_back(child);
    }
    
    return root;
}


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


void printTree_levelWise(treenode<int>* root)  // PRINTS IN AN ORGANISED WAY EVEN WITH "takeInput_lvlWise"
{
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        treenode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";

        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
            cout<< front->children[i]->data <<",";
        }
        cout <<endl;
    }
}


int main(){
    // treenode<int>* root = new treenode<int>(1);
    // treenode<int>* node1= new treenode<int>(2);
    // treenode<int>* node2= new treenode<int>(3);
    
    // root->children.push_back(node1);
    // node1->children.push_back(node2);
    treenode<int>* root= takeInput();
    printTree(root);
    cout <<endl;
    cout <<endl;
    printTree_levelWise(root);
    
    return 0;
}