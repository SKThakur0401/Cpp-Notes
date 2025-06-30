// IMPORTANT NOTE: 99-percent  QUESTIONS OF "TREES" CAN BE SOLVED BY SIMPLE RECURSION

#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector <treenode*> children;
    treenode(T data){this->data = data;}
};

int main()
{

    treenode<int>* root = new treenode<int>(1);
    treenode<int>* node1= new treenode<int>(2);
    treenode<int>* node2= new treenode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    cout<< root->children[1]->data <<endl;

    treenode<int>* node3 = new treenode<int>(5);
    root->children.push_back(node3);
    cout<< root->children[2]->data <<endl;
    return 0;
}