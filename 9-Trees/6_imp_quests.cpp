// IMPORTANT NOTE: 99-percent  QUESTIONS OF "TREES" CAN BE SOLVED BY SIMPLE RECURSION

// THREE VERY SIMPLE FUNCTIONS TO "COUNT" TOTAL NUMBER OF NODES...  TO FIND "SUM OF ALL NODES"... AND TO FIND NODE STORING MAXIMUM VALUE... THESE QUESTIONS ARE VERY SIMILAR...THEY R JUST BASED ON "TRAVERSAL IN TREES"

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

int countNodes(treenode<int>* root)
{
    if(root== NULL){return 0;}
    int count=1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count+= countNodes(root->children[i]);
    }
    return count;
}

int sumOf_Nodes(treenode<int>*root)
{
    int sum= root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum+= sumOf_Nodes(root->children[i]);
    }
    return sum;
}

int maxValue(treenode<int>* root)
{
    int max=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int n= maxValue(root->children[i]);
        if(n> max){max=n;}
    }
    return max;
}

int main(){

    treenode<int>* root= takeInput_levelWise();
    cout<<"Number of nodes is : " <<countNodes(root) <<endl;
    cout<<"Sum of all nodes is : " <<sumOf_Nodes(root) <<endl;
    cout<<"Node with maximum value of data : " << maxValue(root) <<endl;
    return 0;
}