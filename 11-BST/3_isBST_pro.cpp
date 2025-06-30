// Note: in the right node... the "minimum" can be equal to "root->data" we made it a standard rule.... bcoz there are cases where equal elements are there... so we need to put the eqaul in left or right.... so as a rule... we place it on the right :)

// HERE TIME COMPLEXITY= O(n)

#include<iostream>
#include<queue>
#include<climits>
using namespace std;


class trinity
{
    public:
    int min;
    int max;
    bool isitBST;

    trinity()
    {
        min= INT_MAX;           // so the starting value of "min" is the largest integer :)
        max= INT_MIN;           // and for "max" its the smallest integer
        isitBST= true;
    }
};

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data)
    {
        this->data= data;
        left= NULL;
        right= NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput_lvlWise()
{
    int rootData; cin>>rootData;
    if(rootData== -1) {return NULL;}
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "Enter left of "<<front->data <<" : ";
        int l; cin>>l;
        if(l != -1)
        {
            BinaryTreeNode<int>* nodel= new BinaryTreeNode<int>(l);
            front->left= nodel;
            pendingNodes.push(nodel);
        }

        cout<< "Enter right of "<<front->data <<" : ";
        int r; cin>>r;
        if (r != -1)
        {
            BinaryTreeNode<int>* noder= new BinaryTreeNode<int>(r);
            front->right= noder;
            pendingNodes.push(noder);
        }
    }
    return root;
}

void print_lvl_Wise(BinaryTreeNode<int>* root)
{
    if(root== NULL){return;}

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data <<": ";
        if (front->left != NULL)
        {
            cout<< "L-"<<front->left->data <<",";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout<< "R-"<<front->right->data <<",";
            pendingNodes.push(front->right);
        }
        cout <<endl;
    }
}

trinity isBST_pro(BinaryTreeNode<int>* root)
{
    if(root== NULL)
    {
        trinity t;
        return t;
    }

    trinity L = isBST_pro(root->left);
    trinity R = isBST_pro(root->right);

    if(L.isitBST== false) return L;
    if(R.isitBST== false) return R;


    trinity t;      // Note: look at the constructor for its by default values of "min","max" etc..

    t.min = min(L.min ,root->data);
    t.max = max(R.max ,root->data);

    if(L.max >= root->data) t.isitBST= false;   // Bcoz we want it to give false even if the largest
                                            // element in the left node is equal to the root...(we will allow the equal element in the right node :)
    if(R.min < root->data) t.isitBST= false;

    return t;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();

    cout <<endl;
    cout <<endl;

    cout<< isBST_pro(root).isitBST <<endl;
}