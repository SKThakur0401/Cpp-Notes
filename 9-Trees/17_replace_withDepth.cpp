// Chapter Assignment
// Problem Statement: Replace with depth
// Problem Level: MEDIUM
// Problem Description:
// You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

// Output format:
// The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output 1 for more details.

// Constraints:
// Time Limit: 1 sec

// Sample Input 1:
// 10 3 20 30 40 2 40 50 0 0 0 0

// Sample Output 1:
// 0 
// 1 1 1 
// 2 2



// SOLUTION: HERE I SPECIALLY CREATED A FUNCTION "print" to print in the way given above :)


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

void replace(treenode<int>* &root, int k)
{
    root->data= k;
    for (int i = 0; i < root->children.size(); i++)
    {
        replace(root->children[i], k+1);
    }
}

void print(treenode<int>* root)
{
    int k= root->data;
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);

    if(k < root->data){k++, cout <<endl;}
    while (!pendingNodes.empty())
    {
        treenode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        if(front->data ==k){cout<< front->data <<" ";}
        if(front->data !=k){cout<<endl<< front->data <<" ";k++;}
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
        }
    }
}

int main(){

    treenode<int>* root= takeInput_levelWise();
    cout <<endl;
    cout <<endl;
    replace(root,0);

    print(root);

    return 0;
}
