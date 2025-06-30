#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int answer= 0;

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

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
    int data; cin>>data;
    if(data== -1) return NULL;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL)
        {
            if(!pendingNodes.empty()) pendingNodes.push(NULL);
            continue;
        }

        int l; cin>>l;
        if(l != -1)
        {
            front->left= new BinaryTreeNode<int>(l);
            pendingNodes.push(front->left);
        }


        int r; cin>>r;
        if(r != -1)
        {
            front->right= new BinaryTreeNode<int>(r);
            pendingNodes.push(front->right);
        }
    }

    return root;
}
void printTree_lvlWise(BinaryTreeNode<int>* root)
{
    if(!root) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        cout<< front->data <<" : ";
        if(front->left)
        {
            cout<< "L- "<<front->left->data<<"  ";
            pendingNodes.push(front->left);
        }

        if(front->right)
        {
            cout<< "R- "<<front->right->data;
            pendingNodes.push(front->right);
        }

        cout <<endl;
    }
}
// template <typename T>
class BST
{
    public:
    BinaryTreeNode<int>* root;


    BST(BinaryTreeNode<int>* root)
    {
        this->root= root;
    }

    BinaryTreeNode<int>* insert(int k)
    {
        return insert(k, root);
    }

    BinaryTreeNode<int>* del(int k)
    {
        return del(k, root);
    }

    // BinaryTreeNode<int>* insert(int k)
    // {
    //     return insert(k, root);
    // }

    private:
    BinaryTreeNode<int>* insert(int k, BinaryTreeNode<int>* root)
    {
        if(!root)
        {
            root = new BinaryTreeNode<int>(k); return root;
        }

        if(root->data > k)
        {
            root->left= insert(k, root->left);
        }
        if(root->data <= k)
        {
            root->right= insert(k, root->right);
        }
        return root;
    }

    BinaryTreeNode<int>* minNode(BinaryTreeNode<int>* root)
    {
        while(root->left) {root=root->left;}
        return root;
    }

    BinaryTreeNode<int>* del(int k, BinaryTreeNode<int>* root)
    {
        if(!root) return root;
        if(root->data > k)
        {
            root->left = del(k, root->left);
        }

        else if(root->data < k)
        {
            root->right = del(k, root->right);
        }

        else if(root->data == k)
        {
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }

            else if(root->left && root->right)
            {
                BinaryTreeNode<int>* temp = minNode(root->right);
                root->data= temp->data;
                root->right= del(temp->data, root->right);
                // delete temp;
                return root;
            }

            else if(root->left)
            {
                // BinaryTreeNode<int>* a = root;
                root= root->left;
                // delete a;
                // return root;
            }

            else if(root->right)
            {
                // BinaryTreeNode<int>* a = root;
                root= root->right;
                // delete a;
                // return root;
            }
        }

        return root;
    }


};


class quadruple
{
    public:
    int max;
    int min;
    int height;
    bool ans;
    quadruple()
    {
        max= INT_MIN;
        min= INT_MAX;
        height=0;
        ans= true;
    }
};


quadruple largest_BST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        quadruple q;
        return q;
    }

    quadruple leftAns= largest_BST(root->left);
    quadruple rightAns= largest_BST(root->right);

    quadruple q;
    if(leftAns.ans==false && rightAns.ans==false)
    {
        q.height=max(leftAns.height,rightAns.height);
        q.ans= false;
    }

    else if(leftAns.ans==false)
    {
        q.height=max(leftAns.height, rightAns.height);
        q.ans=false;
        return q;
    }

    else if(rightAns.ans==false)
    {
        q.height=max(rightAns.height, leftAns.height);
        q.ans=false;
        return q;
    }
    if(leftAns.max> root->data || rightAns.min< root->data)
    {
        q.ans=false;
        q.height= max(leftAns.height,rightAns.height);
        return q;
    }
    answer= max(answer, 1+ max(leftAns.height, rightAns.height));
    q.height= 1+ max(leftAns.height, rightAns.height);
    q.min=min(root->data, leftAns.min );
    q.max=max(root->data, rightAns.max);
    return q;
}

void replaceWithSum(BinaryTreeNode<int>* root, int &sum)
{
    if(!root) return;
    replaceWithSum(root->right, sum);

    root->data+= sum;
    sum= root->data;

    replaceWithSum(root->left, sum);
}

BinaryTreeNode<int>* preTree(int pre[], int lower, int upper, int n)
{
    static int i=0;
    if(i==n) return NULL;
    int curr= pre[i];
    
    if(curr > lower && curr < upper)
    {
        i++;
        BinaryTreeNode<int>* root= new BinaryTreeNode<int>(curr);

        root->left= preTree(pre, lower, curr-1, n);
        root->right= preTree(pre, curr+1, upper, n);
        return root;
    }
    return NULL;
}







int main(){

    // BinaryTreeNode<int>* root= takeInput_lvlWise();


    int pre[] = {30,20,10,15,25 , 23,39,35,42};
    // cout<< sizeof(pre) <<endl;
    
    BinaryTreeNode<int>* root = preTree(pre, INT_MIN, INT_MAX, sizeof(pre)/4 -1);

    printTree_lvlWise(root);


    return 0;
}

