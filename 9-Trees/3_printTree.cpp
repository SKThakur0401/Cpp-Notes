#include<iostream>
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


void printTree(treenode<int>* root)
{
    if(root==NULL){return;}         //NOTE !!! THIS IS JUST TO AVOID AN "EDGE CASE" WHERE A STUPID USER ENTERS A NULL VALUE AS PARAMETER.... TO AVOID THE CODE FROM GIVING ERROR IN LINE BELOW COZ OF        " root->data "


    cout<< root->data <<": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data <<",";
    }
    cout <<endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main(){

    treenode<int>* root = new treenode<int>(1);
    treenode<int>* node1= new treenode<int>(2);
    treenode<int>* node2= new treenode<int>(3);

    root->children.push_back(node1);
    node1->children.push_back(node2);

    printTree(root);        // the node which you pushed_back first will be stored in "root->children[0]" 
                            // and the other in "root->children[1]" and so on.... so node which is "pushed_back" first will be printed first :)

    return 0;
}