// Chapter Assignment
// Problem Statement: Node with maximum child sum
// Problem Level: MEDIUM
// Problem Description:
// Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

// Output format :
// The first and only line of output contains the data of the node with maximum sum, as described in the task.

// Constraints:
// Time Limit: 1 sec

// Sample Input 1 :
// 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

// Sample Output 1 :
// 1


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

class bint        // It is a class comprising of 2 ints...custom made for this question :)       // Realised later: could have used the inbuilt "pair<int,int>" does the same thing ;)
{
    public:
    int sum;                // CONTAINS SUM OF FATHER AND ITS CHILDREN'S DATA :)
    int fnode;              // FATHER NODE
    bint(int sum,int fnode)
    {
        this->sum=sum;
        this->fnode=fnode;
    }
    bint(){}
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


bint sum_fC(treenode<int>*root)
{
    int sum=0;
    sum+=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum+=root->children[i]->data;
    }
    bint b(sum,root->data);
    return b;
}

bint fatherChild(treenode<int>* root)
{
    bint max= sum_fC(root);
    for (int i = 0; i < root->children.size(); i++)
    {
        bint calc = sum_fC(root->children[i]);
        if(calc.sum > max.sum)
        {
            max=calc;
        }
        bint calc2= fatherChild(root->children[i]);
        if(calc2.sum > max.sum)
        {
            max= calc2;
        }
    }
    return max;
}

void Answer_er(treenode<int>*root)
{
    cout<< fatherChild(root).fnode <<endl;
}

int main(){

    treenode<int>* root= takeInput_levelWise();
    cout <<endl;
    cout <<endl;
    cout <<endl;

    Answer_er(root);
    
    return 0;
}