// QUESTION: MAKE A FUNCTION THAT RETURNS "true" if 2 trees are identical and false elsewise

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

bool identical(treenode<int>*root1, treenode<int>*root2)
{
    if(root1->data == root2->data  &&  root1->children.size() == root2->children.size())
    {
        for (int i = 0; i < root1->children.size(); i++)
        {
            bool x= identical(root1->children[i], root2->children[i]);
            if(x== false){return false;}
        }
        return true;
    }
    return false;
}

int main(){

    cout<< "Enter Data for the First Tree :" <<endl;
    treenode<int>* root1= takeInput_levelWise();
    cout <<endl;
    cout <<endl;
    cout<< "Enter Data for the Second Tree :" <<endl;
    treenode<int>* root2= takeInput_levelWise();

    cout <<endl;
    cout <<endl;
    cout <<endl;

    cout<< identical(root1,root2) <<endl;

    return 0;
}