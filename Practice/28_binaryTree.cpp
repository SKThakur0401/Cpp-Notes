#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

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

BinaryTreeNode<int>* takeInput()
{
    int data; cin>>data;
    if(data== -1) return NULL;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(data);

    root->left= takeInput();
    root->right= takeInput();
    return root;
}

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

void printTree(BinaryTreeNode<int>* root)
{
    if(!root) return;
    cout<< root->data <<" : ";

    if(root->left) cout<< "L- "<< root->left->data <<"  ";
    if(root->right) cout<< "R- "<< root->right->data <<"  ";
    cout <<endl;

    printTree(root->left);
    printTree(root->right);
}

bool isPresent(BinaryTreeNode<int>* root, int target){
    if(!root) return false;
    if(root->data== target) return true;

    bool lAns= isPresent(root->left, target);
    if(lAns) return true;
    bool rAns= isPresent(root->right, target);

    return rAns;
}


void mirror(BinaryTreeNode<int>* root){
    if(!root) return;

    BinaryTreeNode<int>* temp= root->left;
    root->left= root->right;
    root->right= temp;

    mirror(root->left);
    mirror(root->right);
}


void preOrder(BinaryTreeNode<int>* root)
{
    if(!root) return;
    cout<< root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}


void preOrderIterative(BinaryTreeNode<int>* root)
{
    if(!root) return;

    stack<BinaryTreeNode<int>*> st;
    st.push(root);
    while(!st.empty())
    {
        BinaryTreeNode<int>* x = st.top();
        cout<< st.top()->data <<" ";

        st.pop();

        if(x->right) st.push(x->right);
        if(x->left) st.push(x->left);
    }
}

// void postOrderIterative(BinaryTreeNode<int>* root)
// {
    
// }


void link(BinaryTreeNode<int>* root)
{
    if(!root->left) return;

    BinaryTreeNode<int>* curr= root->left;
    while(curr->right) curr=curr->right;
    curr->right= root;
    // return curr;
}

bool isLinked(BinaryTreeNode<int>* root)
{
    if(!root->left) return false;
    BinaryTreeNode<int>* curr= root->left;

    while(curr)
    {
        if(curr->right == root)
        {
            curr->right= NULL;
            return true;
        }

        else if(curr->right== NULL) return false;

        curr= curr->right;
    }
    return false;
}

bool isleftLink(BinaryTreeNode<int>* root)
{
    if(!root->left) return true;
    BinaryTreeNode<int>* curr= root->left;

    while(curr)
    {
        if(curr->right == root)
        {
            // curr->right= NULL;
            return true;
        }

        else if(curr->right== NULL) return false;

        curr= curr->right;
    }

    return true;
}

void linkerR(BinaryTreeNode<int>* root)
{
    if(!root) return;
    BinaryTreeNode<int>* curr= root;
    while(curr->right) curr= curr->right;
    curr->right= root;
}

void linkerL(BinaryTreeNode<int>* root)
{
    if(!root) return;
    BinaryTreeNode<int>* curr= root->left;
    if(!curr) return;
    while(curr->right) curr= curr->right;
    curr->right= root;
}

bool isrightLink(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root->right;

    while(curr)
    {
        if(curr->right == root)
        {
            // curr->right= NULL;
            return true;
        }

        else if(curr->right== NULL) return false;

        curr= curr->right;
    }

    return true;
}

void removeLink(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root;

    while(curr->right != root) curr= curr->right;
    curr->right= NULL;

    curr= root->left;
    if(!curr) return;

    while(curr->right != root) curr= curr->right;
    curr->right= NULL;
}

void morrisPostOrder(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root;
    
    while(curr)
    {
        if(isrightLink(curr) && isleftLink(curr))
        {
            removeLink(root);
            cout<< root->data <<" ";
        }

        else if(isleftLink(curr))
        {
            linkerR(curr);
            curr= curr->right;
        }

        else
        {
            linkerL(curr);
            curr= curr->left;
        }
    }
}

void morrisPreOrder(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root;

    while(curr)
    {
        if(isLinked(curr))
        {
            curr= curr->right;
        }

        else
        {
            cout<< curr->data <<" ";
            
            link(curr);
            if(curr->left) curr= curr->left;
            else if(curr->right) curr= curr->right;
            else if(!curr->left && !curr->right) break;
        }
    }
}

int searcher(int in[], int si, int ei, int curr)
{
    for(int i=si; i<= ei; i++)
    {
        if(in[i] == curr) return i;
    }
    return -1;
}

BinaryTreeNode<int>* buildTree(int pre[], int in[], int si, int ei, int &i)
{
    if(si>ei) return NULL;

    int curr= pre[i];
    i++;

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(curr);

    int search= searcher(in, si, ei, curr);

    root->left= buildTree(pre, in, si, search-1, i);
    root->right= buildTree(pre, in, search+1, ei, i);
    return root;
}

pair<int,int> minMax(BinaryTreeNode<int>* root)
{
    if(!root)
    {
        pair<int,int> pi(INT_MAX, INT_MIN);
        return pi;
    }

    pair<int,int> lans= minMax(root->left);
    pair<int,int> rans= minMax(root->right);

    int mini = min(root->data , min(lans.first, rans.first));
    int maxi = max(root->data , max(lans.second, rans.second));

    pair<int,int> pi(mini, maxi);
    return pi;
}

pair<int, bool> isBalanced(BinaryTreeNode<int>* root)
{
    if(!root)
    {
        pair<int, bool> pi(0, true);
        return pi;
    }

    pair<int, bool> lAns= isBalanced(root->left);
    if(!lAns.second) return lAns;

    pair<int, bool> rAns= isBalanced(root->right);
    if(!rAns.second) return rAns;

    if( abs(lAns.first - rAns.first) > 1)
    {
        pair<int, bool> pi(0, false);
        return pi;
    }

    pair<int, bool> pi(1 + max(rAns.first, lAns.first) , true);
    return pi;
}

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int swapCount(int arr[], int n)
{
    vector<pair<int,int> > vi;
    for(int i=0; i<n; i++)
    {
        pair<int,int> pi(arr[i], i);
        vi.push_back(pi);
    }

    sort(vi.begin(), vi.end(), compare);

    int swaps=0;
    for(int i=0; i< n; i++)
    {
        if(i != vi[i].second)
        {
            swap(vi[i], vi[vi[i].second]);
            swaps++;
        }
    }
    return swaps;
}


int main(){

    // BinaryTreeNode<int>* root= takeInput_lvlWise();
    // int preorder[]= {1,2,4,5,3,6,7};
    // int inorder[] = {4,2,5,1,6,3,7};
    // int x=0;
    // BinaryTreeNode<int>* root= buildTree(preorder, inorder, 0, 6, x);

    // printTree_lvlWise(root);

    // cout <<endl;
    // cout <<endl;

    // cout<< minMax(root).first <<endl;
    // cout<< minMax(root).second <<endl;

    // int arr[]= { 3, 5, 2, 4, 6, 8};         // ans=3
    int arr[]= {1,5,4,3,2};              // ans=2

    int n= sizeof(arr)/sizeof(arr[0]);

    cout<<swapCount(arr, n)<<endl;

    return 0;
}

