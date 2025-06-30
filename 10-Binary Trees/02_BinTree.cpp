#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

template <typename T>
class node
{
    public:
    T data;
    node* next;

    node() {}

    node(T data)
    {
        this->data= data;
        next= NULL;
    }

    // ~node()
    // {
    //     delete next;
    // }
};

template <typename T>
class binaryTreeNode
{
    public:
    T data;
    binaryTreeNode<T>* left;
    binaryTreeNode<T>* right;

    binaryTreeNode(){}

    binaryTreeNode(T data)
    {
        this->data= data;
        left=NULL;
        right=NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

binaryTreeNode<int>* takeInput()
{
    int rD; cin>>rD;
    if(rD== -1) return NULL;

    binaryTreeNode<int>* root= new binaryTreeNode<int>(rD);

    root->left= takeInput();
    root->right= takeInput();

    return root;
}

binaryTreeNode<int>* takeInput_lvl_wise()
{
    int rd; cin>>rd;
    if(rd== -1) return NULL;
    binaryTreeNode<int>* root= new binaryTreeNode<int>(rd);

    queue< binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>* front= pendingNodes.front();

        pendingNodes.pop();

        int lc, rc;
        cin>> lc>>rc;
        if(lc != -1) {front->left= new binaryTreeNode<int>(lc);   pendingNodes.push(front->left);}
        if(rc != -1) {front->right= new binaryTreeNode<int>(rc); pendingNodes.push(front->right);}
    }
    return root;
}


void print(binaryTreeNode<int>* root)
{
    if(root==NULL) return;
    cout<< root->data <<" : ";
    if(root->left  != NULL) cout<< "L-"<< root->left->data<<" , ";
    if(root->right != NULL) cout<< "R-"<< root->right->data;

    cout <<endl;

    print(root->left);
    print(root->right);
}

void print_lvl_wise(binaryTreeNode<int>* root)
{
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data <<" : ";
        if(front->left != NULL)
        {
            cout<< "L-"<<front->left->data <<"  ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL)
        {
            cout<< "R-"<<front->right->data <<"  ";
            pendingNodes.push(front->right);
        }
        cout <<endl;
    }
}

int countNodes(binaryTreeNode<int>* root)
{
    if(root==NULL) return 0;

    return 1+ countNodes(root->left) + countNodes(root->right);
}

int countLeaf(binaryTreeNode<int>* root)
{
    if(root==NULL) return 0;
    if(root->left== NULL && root->right== NULL) return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}


bool isPresent(binaryTreeNode<int>* root, int n)
{
    if(root== NULL) return false;
    if(root->data == n) return true;

    bool l= isPresent(root->left, n);
    bool r= isPresent(root->right, n);

    return l || r ;
}

int height(binaryTreeNode<int>* root)
{
    if(root==NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}


void mirror(binaryTreeNode<int>* root)
{
    if(root == NULL) return ;

    binaryTreeNode<int>* temp= root->left;
    root->left= root->right;
    root->right= temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder_print(binaryTreeNode<int>* root)
{
    if(root==NULL) return;
    inorder_print(root->left);
    cout<< root->data <<" ";
    inorder_print(root->right);
}

void preOrder(binaryTreeNode<int>* root)
{
    if(root==NULL) return;

    cout<< root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(binaryTreeNode<int>* root)
{
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<" ";
}

int search(int inorder[],int si, int ei, int curr)
{
    for (int i = si; i <= ei; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

// int search(int inorder[], int si ,int ei, int curr)
// {
//     for (int i = si; i <= ei; i++)
//     {
//         if(inorder[i]== curr) return i;
//     }
// }

binaryTreeNode<int>* buildTree(int preorder[], int inorder[], int si, int ei)
{
    static int index=0;
    int curr= preorder[index];
    index++;

    binaryTreeNode<int>* root= new binaryTreeNode<int>(curr);

    if(si== ei) return root;

    int pos= search(inorder, si, ei, curr);

    root->left  = buildTree(preorder, inorder, si, pos-1);
    root->right = buildTree(preorder, inorder, pos+1, ei);

    return root;
}

binaryTreeNode<int>* buildTree2(int postorder[], int inorder[], int si, int ei)
{
    if(si> ei) return NULL;
    static int index= ei;
    int curr= postorder[index];
    index--;

    binaryTreeNode<int>* root= new binaryTreeNode<int>(curr);

    if(si== ei) return root;

    int pos= search(inorder, si, ei, curr);

    root->right =  buildTree2(postorder, inorder, pos+1, ei);
    root->left  =  buildTree2(postorder, inorder, si, pos-1);

    return root;
}

pair<int,int> diameter(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> ans(0,0);
        return ans;
    }
    pair<int,int> l= diameter(root->left);
    pair<int,int> r= diameter(root->right);

    int lh= l.first;
    int rh= r.first;
    int ld= l.second;
    int rd= r.second;

    int h= 1+ max(lh,rh);
    int d= max(lh + rh, max(ld,rd));

    pair<int,int> ans(h,d);

    return ans;
}

pair<int,int> minmax(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> ans(INT_MAX, INT_MIN);
        return ans;
    }

    pair<int,int> lans = minmax(root->left);
    pair<int,int> rans = minmax(root->right);

    int mini =  min(root->data, min(lans.first, rans.first));
    int maxi =  max(root->data, max(lans.second, rans.second));

    pair<int,int> ans(mini,maxi);
    return ans;
}


pair<bool, int> chkBalance(binaryTreeNode<int>* root)
{
    if(root== NULL)
    {
        pair<bool,int> ans(true,0);
        return ans;
    }

    pair<bool,int> leftAns= chkBalance(root->left);
    pair<bool,int> rightAns= chkBalance(root->right);

    if(!leftAns.first || !rightAns.first)
    {
        pair<bool,int> ans(false, 0);
        return ans;
    }

    if(abs(leftAns.second - rightAns.second) > 1)
    {
        pair<bool,int> ans(false, 0);
        return ans;
    }

    pair<bool,int> ans(true, 1+ max(leftAns.second, rightAns.second));

    return ans;
}

vector<node<int>*> LLiser(binaryTreeNode<int>* root)
{
    vector<node<int>*> headList;

    node<int>* tail= NULL;
    int level=0;

    queue<binaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front==NULL)
        {
            if(!pendingNodes.empty()) {pendingNodes.push(NULL);}
            level++;
        }

        else
        {
            if(front->left != NULL) pendingNodes.push(front->left);
            if(front->right != NULL) pendingNodes.push(front->right);

            node<int>* newNode= new node<int>(front->data);
            if(headList.size()== level)
            {
                headList.push_back(newNode);
                tail= newNode;
            }
            else
            {
                tail->next= newNode;
                tail= tail->next;
            }
        }
    }
    return headList;
}

int main()
{

    binaryTreeNode<int>* root= takeInput_lvl_wise();

    // int preorder[]= {1,2,4,5,3,6,7};

    // int postorder[]= {4,5,2,6,7,3,1};
    // int inorder[] = {4,2,5,1,6,3,7};

    // binaryTreeNode<int>* root = buildTree(preorder,inorder,0,6);
    // binaryTreeNode<int>* root = buildTree2(postorder,inorder,0,6);

    // print_lvl_wise(root);

    // cout <<endl;
    // pair<int,int> ans= diameter(root);

    // cout<< ans.first <<endl;
    // cout<< ans.second <<endl;

    // pair<int,int> ans= minmax(root);

    // cout<< "Min : "<< ans.first <<endl;
    // cout<< "Max : "<< ans.second <<endl;
    // cout<< min(root) <<endl;

    // pair<bool,int> ans = chkBalance(root);

    // cout<< ans.first <<endl;

    vector<node<int>*> headList= LLiser(root);

    // cout<< headList.size() <<endl;
    for (int i = 0; i < headList.size(); i++)
    {
        node<int>* head= headList[i];
        while(head != NULL)
        {
            cout<< head->data <<" ";
            head=head->next;
        }
        cout <<endl;
    }
    

    return 0;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

