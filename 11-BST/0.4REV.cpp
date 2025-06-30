#include "0.0BinaryTree.h"
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(){ next = NULL; }

    node(int data)
    {
        this->data= data;
        next= NULL;
    }

    ~node()
    {
        delete next;
    }
};

class tri
{
    public:
    int min, max;
    bool isItBST;

    tri(){}

    tri(int mi, int ma, bool b)
    {
        min =mi;
        max =ma;
        isItBST = b;
    }
};

tri isBST(BinaryTreeNode<int>* root)
{
    if(!root)
    {
        tri x(INT_MAX, INT_MIN, true);
        return x;
    }

    if(!root->left && !root->right)
    {
        tri x(root->data, root->data, true);
        return x;
    }

    tri leftAns = isBST(root->left);
    if(!leftAns.isItBST)
    {
        return leftAns;
    }

    tri rightAns = isBST(root->right);
    if(!rightAns.isItBST)
    {
        // tri x(INT_MAX, INT_MIN, false);
        // return x;
        return rightAns;
    }

    if(leftAns.max >= root->data || rightAns.min < root->data)
    {
        tri x(INT_MAX, INT_MIN, false);
        return x;
    }

    tri alpha(leftAns.min, rightAns.max, true);
    return alpha;
}

bool ans(BinaryTreeNode<int>* root)
{
    return isBST(root).isItBST ;
}

BinaryTreeNode<int>* ConstructTree(int arr[], int si, int ei)
{
    if(si> ei) return NULL;
    int mid = (si+ei)/2;

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[mid]);

    root->left = ConstructTree( arr, si, mid-1);
    root->right = ConstructTree( arr, mid+1, ei);

    return root;
}

void inorder(BinaryTreeNode<int>* root, node*& head, node* &tail)
{
    if(!root) return;

    inorder(root->left, head, tail);

    if(!tail)
    {
        head= new node(root->data);
        tail= head;
    }
    else
    {
        tail->next = new node(root->data);
        tail=tail->next;
    }

    inorder(root->right, head, tail);
}

vector<int> pathFinder(BinaryTreeNode<int>* root, int k)
{
    if(!root)
    {
        vector<int> vi; return vi;
    }

    vector<int> leftAns = pathFinder(root->left , k);
    vector<int> rightAns = pathFinder(root->right,k);


    if(root->data == k)
    {
        vector<int> vi;
        vi.push_back(k);
        return vi;
    }

    if(leftAns.empty() && rightAns.empty())
    {
        vector<int> vi; return vi;
    }

    if(!leftAns.empty())
    {
        leftAns.push_back(root->data);
        return leftAns;
    }


    if(!rightAns.empty())
    {
        rightAns.push_back(root->data);
        return rightAns;
    }

    vector<int> vi; return vi;
}

int main()
{
    // int arr[]= {1,2,3,4,5,6,7};

    // BinaryTreeNode<int>* root= ConstructTree(arr,0, (sizeof(arr)/4)-1 );
    // cout <<endl;
    // cout <<endl;
    // print_lvl_Wise(root);

    BinaryTreeNode<int>* root = takeInput_lvlWise();
    // node* head= NULL;
    // node* tail= NULL;
    // inorder(root, head, tail);
    // while(head)
    // {
    //     cout<< head->data <<" ";
    //     head=head->next;
    // }
    cout <<endl;
    cout <<endl;
    int k=3;
    vector<int> path = pathFinder(root, k);

    for (int i = 0; i < path.size(); i++)
    {
        cout<< path[i] <<" ";
    }
    cout <<endl;
    
    return 0;
}

