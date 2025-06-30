// IN "DEPTH" CONCEPT... WE COMPARE THE DISTANCE WITH ROOT AS REFERENCE POINT...WHERE DEPTH OF ROOT IS 0,,,, AND DEPTH OF 1st generation children is "1" ..and so on.

// WE R GOING TO WRITE A FUNCTION : "printAt_levelK" which will print all the "k-th" generation children...or k-th level children


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

void printAt_levelK(treenode<int>* root,int k)
{

    // if(root== NULL){return;}         // this is just an edge case where root is null....we write this line just to handle the edge case of root being given null by user...u can uncomment it...it wouldn't affect the code
    
    if(k==0){cout<< root->data <<endl;}

    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            printAt_levelK(root->children[i], k-1);
        }
    }
}

int main(){

    treenode<int>* root = takeInput_levelWise();

    cout<< "Which level node / nodes you want to call : " <<endl;
    int k; cin>>k;
    printAt_levelK(root,k);

    return 0;
}
