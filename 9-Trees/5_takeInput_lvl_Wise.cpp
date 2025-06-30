// HERE, WE ARE GOING TO TAKE INPUT AND PRINT IT... BOTH "LEVEL-WISE" THIS TIME (COZ ITS MORE ORGANISED).....AFTER ONE ROOT WE COVER ALL ITS CHILD AND THEN LOOK FOR CHILDREN OF CHILDS...

// THIS IS "takeInput_levelWise", here "queue" is going to be a great help!!!... here giving input is easier and more "organized".... unlike the previous file where for giving input, one must have the knowledge of "recursion".

// LEVEL WISE MEANS...FIRST, FIRST GENERATION THEN SECOND GENERATION AND THEN IN SAME ORDER ALL GENERATION WILL BE PRINTED / TAKEN INPUT OF....

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

int main(){

    treenode<int>* root= takeInput_levelWise();
    printTree_levelWise(root);

    return 0;
}