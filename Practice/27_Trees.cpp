#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode<T>* > children;

    treenode(){}

    treenode(T data)
    {
        this->data= data;
    }

    ~treenode()
    {
        for(int i=0; i<children.size(); i++)
        {
            delete [] children[i];
        }
        delete (*this);
    }

};

treenode<int>* takeInput()
{
    int rootData;
    // cout<<"Enter data : ";
    cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);
    int n; 
    cout<<"Enter number of children of "<<rootData<< " : ";
    cin>>n;

    // if(rootData != -1)
    for(int i=0; i<n; i++)
    {
        cout<< "Enter data of "<< i+1<<"th child of "<<rootData <<" : ";
        treenode<int>* child= takeInput();
        root->children.push_back(child);
    }

    return root;
}

treenode<int>* takeInput_lvlWise()
{
    cout<< "Enter root data : ";
    int data; cin>>data;

    treenode<int>* root= new treenode<int>(data);

    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        treenode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< "How many children does "<<front->data<<" have : ";
        int n; cin>>n;

        for (int i = 0; i < n; i++)
        {
            cout<< "Enter "<<i+1<<"th child of "<< front->data<<" : ";
            int childData; cin>>childData;
            treenode<int>* curr= new treenode<int>(childData);
            front->children.push_back(curr);
            pendingNodes.push(curr);

        }
        
    }
    return root;
}

void printTree(treenode<int>* root)
{
    cout<<root->data<<" : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<< root->children[i]->data <<"  ";
    }
    cout <<endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        // cout<< root->children[i]->data <<"  ";

        printTree(root->children[i]);
    }
}

void printTree_lvlWise(treenode<int>* root)
{
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        cout<< front->data<<" : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            cout<< front->children[i]->data <<" ";
            pendingNodes.push(front->children[i]);
        }
        cout <<endl;
    }
}

int height(treenode<int>* root)
{
    int h=1;

    for (int i = 0; i < root->children.size(); i++)
    {
        h= max(h, 1 + height(root->children[i]));
    }
    return h;
}

int countLeaf(treenode<int>* root)
{
    if(root->children.size() == 0) return 1;

    int c=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        c+= countLeaf(root->children[i]);
    }
    
    return c;
}

void print_lvl_K(treenode<int>* root, int target, int k=0)
{
    if(k== target) {cout<< root->data <<endl; return;}

    for (int i = 0; i < root->children.size(); i++)
    {
        print_lvl_K(root->children[i], target, k+1);
    }
}

int main(){

    treenode<int>* root= takeInput_lvlWise();

    // printTree_lvlWise(root);
    // cout<< "Height : "<< height(root) <<endl;
    // cout<< "leaf Count : "<< countLeaf(root) <<endl;
    print_lvl_K(root, 1);

    return 0;
}

