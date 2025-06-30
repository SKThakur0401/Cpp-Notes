// QUESTION: FIND THE SECOND LARGEST NUMBER IN THE TREE

// After reading this file later on.... I realised that using "largest and Sec_largest function" first finds the largest and then the second largest....thus traversing through the tree "twice" ... we can solve this question in "one" traversal...thus reducing the time complexity by almost half :)


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

int largest(treenode<int>* root)
{
    int max= root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int n= largest(root->children[i]);
        if(n> max){max=n;}
    }
    return max;
}

int Sec_largest(treenode<int>*root, int max)
{
    int secmax=0;
    if(root->data < max){secmax=root->data;}
    for (int i = 0; i < root->children.size(); i++)
    {
        int S = Sec_largest(root->children[i],max);
        if(S> secmax){secmax= S;}
    }
    return secmax;
}


pair<int,int> oneTraversal(treenode<int>* root)  //Finds the second-largest element in one traversal
{
    pair<int,int> p;
    p.first= root->data;
    p.second= 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        pair<int,int> x = oneTraversal(root->children[i]);

        if(x.first > p.first)
        {
            if(x.second > p.first) p= x;

            else if(x.second < p.first)
            {
                p.second= p.first;
                p.first= x.first;
            }
        }
        else if(x.first < p.first)
        {
            if(x.first > p.second) p.second= x.first;
        }

    }
    return p;
}

int main(){

    treenode<int>* root= takeInput_levelWise();
    cout <<endl;
    cout <<endl;
    int max= largest(root);
    cout<< "Second Largest node in tree using 2nd Largest : "<<Sec_largest(root,max) <<endl;
    cout<< "Second Largest node in tree using oneTraversal: "<<oneTraversal(root).second <<endl;

    return 0;
}

// NOTE: U CAN ALSO SOLVE IT USING A "CLASS" THAT STORES BOTH LARGEST AND SECOND LARGEST NUMBER... SO U WOULDN'T NEED TO FIND LARGEST AND SECOND LARGEST SEPARATELY... (U WOULDN'T NEED TO TRAVERSE TWICE IN TREE) ..... LATER ADDED NOTE: I did it using One-traversal :)
