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
    vector<treenode* > children;

    treenode() {}

    treenode(T data)
    {
        this->data= data;
    }

    // ~treenode()
    // {
    //     for (int i = 0; i < children.size(); i++)
    //     {
    //         delete children[i];
    //     }
        
    // }
};

treenode<int> * takeInput()
{
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);
    cout<< "How many children does "<<rootData<<" have : ";
    int numChild; cin>>numChild;

    for (int i = 1; i <= numChild; i++)
    {
        int data;
        cout<< "Enter "<<i<<"th child of "<< root->data<<" : ";

        treenode<int>* child= takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(treenode<int>* root)
{
    cout<< root->data <<" : ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout<< root->children[i]->data <<",";
    }
    cout <<endl;

    for (int i = 0; i < root->children.size() ; i++)
    {
        printTree(root->children[i]);
    }
}

void printTree_lvl_wise(treenode<int>* root)
{
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL)
        {
            cout <<endl;
            if(pendingNodes.front() != NULL) pendingNodes.push(NULL);
            continue;
        }

        cout<< front->data <<" ";

        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
        }
        
    }
}

treenode<int>* takeInput_lvl_wise()
{
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);

    queue<treenode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "How many children u want for "<< front->data<<" : ";
        int numChild; cin>>numChild;

        for (int i = 0; i < numChild; i++)
        {
            cout<< "Enter "<<i+1<<"th child of "<< front->data <<" : ";
            int data; cin>>data;
            treenode<int>* child= new treenode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int height(treenode<int>* root)
{
    if(root->children.size()==0) return 1;

    int maxHeight=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxHeight = max(maxHeight ,1+ height(root->children[i]));
    }
    return maxHeight;
}

int countLeaf(treenode<int>* root)
{
    if(root->children.size()==0) return 1;
    int ans=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans+= countLeaf(root->children[i]);
    }
    return ans;
}

int BiggerNodes(treenode<int>* root, int x)
{
    int ans=0;
    if(root->data > x) ans++;
    // if(root->children.size()==0) return 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans+= BiggerNodes(root->children[i],x);
    }
    return ans;
}

bool clones(treenode<int>* root1 , treenode<int>* root2)
{
    if(root1->data != root2->data || root1->children.size() != root2->children.size()) return false;

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool b= clones(root1->children[i],root2->children[i]);
        if(!b) return b;
    }
    
    return true;
}

int nextLarger(treenode<int>* root, int n)
{
    int ans= INT_MAX;

    if(root->data > n) ans= root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        int x= nextLarger(root->children[i], n);

        if(x< ans) ans=x;
    }
    
    return ans;
}

pair<int,int> SecLargest(treenode<int>* root)
{
    pair<int,int> ans(root->data, 0);

    for (int i = 0; i < root->children.size(); i++)
    {
        pair<int,int> sC= SecLargest(root->children[i]);

        if(sC.second > ans.first) {ans = sC; continue;}

        if(sC.first > ans.first)
        {
            ans.second=ans.first;
            ans.first= sC.first ;

        }
        if(sC.first <ans.first && sC.first > ans.second) ans.second= sC.first;

    }
    return ans;
}

int secLar(treenode<int>* root)
{
    return SecLargest(root).second;
}

int main(){

    // treenode<int>* root= takeInput();
    treenode<int>* root= takeInput_lvl_wise();

    cout <<endl;
    cout <<endl;
    // cout<< "Height : "<< height(root) <<endl;
    // cout<< "Count of Leaf : "<< countLeaf(root) <<endl;
    cout<<"next Larger : " <<nextLarger(root, 2) <<endl;
    cout<<"2nd largest : " <<secLar(root) <<endl;
    cout <<endl;

    printTree_lvl_wise(root);


    return 0;
}


// 1 3 2 2 5 0 6 0 3 0 4 0

// 1 3 2 3 4 2 5 6 0 0 0 0
