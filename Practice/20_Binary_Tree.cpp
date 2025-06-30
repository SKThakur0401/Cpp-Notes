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
        this->data= data; left=NULL; right= NULL;
    }

    ~BinaryTreeNode()
    {
        delete left; delete right;
    }
};

BinaryTreeNode<int>* takeInput()
{
    int data; cin>>data;
    if(data== -1) return NULL;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(data);

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

BinaryTreeNode<int>* takeInput_lvl_Wise()
{
    int rd; cin>>rd;
    if(rd== -1) return NULL;

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rd);
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front(); pendingNodes.pop();

        int lcd; cin>>lcd;
        if(lcd== -1) front->left=NULL;
        else
        {
            front->left= new BinaryTreeNode<int>(lcd);
            pendingNodes.push(front->left);
        }

        int rcd; cin>>rcd;
        if(rcd== -1) front->right=NULL;
        else
        {
            front->right= new BinaryTreeNode<int>(rcd);
            pendingNodes.push(front->right);
        }
    }
    return root;
}

void print_lvl_Wise(BinaryTreeNode<int>* root)
{
    if(!root) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front(); pendingNodes.pop();

        cout<< front->data <<" : ";
        if(front->left){cout<<"L-"<< front->left->data <<", "; pendingNodes.push(front->left);}
        if(front->right) {cout<<"R-"<< front->right->data <<", "; pendingNodes.push(front->right);}
        cout <<endl;
    }
}

pair<int,int> HeightDiameter(BinaryTreeNode<int>* root)
{
    if(!root) {pair<int,int> pi(0,0); return pi;}

    if(!root->left && !root->right)
    {
        pair<int,int> pi(1,0); return pi;
    }

    pair<int,int> leftAns = HeightDiameter(root->left);
    pair<int,int> rightAns = HeightDiameter(root->right);
    int d= max(leftAns.first + rightAns.first , max(leftAns.second, rightAns.second));
    pair<int,int> ans(1+ max(leftAns.first,rightAns.first), d);
    return ans;
}

void printTree(BinaryTreeNode<int>* root)
{
    if(!root) return;
    cout<< root->data << " : ";
    if(root->left) cout<<"L-"<< root->left->data <<", ";
    if(root->right) cout<<"R-"<< root->right->data <<", ";
    cout <<endl;

    printTree(root->left);
    printTree(root->right);
}

void mirror(BinaryTreeNode<int>* root)
{
    if(!root) return;

    // BinaryTreeNode<int>* temp = root->left;
    // root->left= root->right;
    // root->right= temp;
    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

void preorder_iterative(BinaryTreeNode<int>* root)
{
    if(!root) return;

    stack<BinaryTreeNode<int>* > st;
    st.push(root);

    while(!st.empty())
    {
        BinaryTreeNode<int>* top = st.top(); st.pop();
        cout<<top->data<<" ";

        if(top->right) st.push(top->right);
        if(top->left) st.push(top->left);
    }
}

void inorder_iterative(BinaryTreeNode<int>* root)
{
    if(!root) return;

    BinaryTreeNode<int>* curr= root;
    stack<BinaryTreeNode<int>* > st;

    while(curr || !st.empty())
    {
        while(curr)
        {
            st.push(curr);
            curr= curr->left;
        }

        BinaryTreeNode<int>* a = st.top(); st.pop();
        cout<< a->data <<" ";

        curr= a->right;
    }
}

void postorder(BinaryTreeNode<int>* root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}

void postorder_iterative(BinaryTreeNode<int>* root)
{
    if(!root) return;

    stack<BinaryTreeNode<int>* > st;
    stack<BinaryTreeNode<int>* > pt;
    st.push(root);
    while(!st.empty())
    {
        BinaryTreeNode<int>* curr= st.top(); st.pop();
        pt.push(curr);
        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }

    while (!pt.empty())
    {
        cout<<pt.top()->data<<" ";
        pt.pop();
    }
    
}

pair<int, bool> isBalanced(BinaryTreeNode<int>* root)
{
    if(root== NULL){ pair<int, bool> pi(0, true) ; return pi;}

    pair<int,bool> leftAns= isBalanced(root->left);
    pair<int,bool> rightAns= isBalanced(root->right);
    if(!(leftAns.second && rightAns.second) || abs(leftAns.first - rightAns.first) >1)
    {
        pair<int ,bool> pi(0,0);
        return pi;
    }

    pair<int, bool> pi(1+ max(leftAns.first,rightAns.first) , true);
    return pi;
}

template <typename T>
class node
{
    public:
    T data;
    node<T>* next;

    node(T data)
    {
        this->data= data;
        next=NULL;
    }
};

vector<node<int> * > LLiser(BinaryTreeNode<int>* root)
{
    vector<node<int>* > ans;
    if(!root) return ans;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    node<int>* head =NULL;
    node<int>* tail =NULL;

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front== NULL)
        {
            ans.push_back(head);
            head=NULL; tail=NULL;
            if(!pendingNodes.empty()) pendingNodes.push(NULL);
            continue;
        }

        node<int>* newNode = new node<int>(front->data);

        if(head == NULL)
        {
            head= newNode;
            tail= newNode;
        }

        else
        {
            tail->next= newNode;
            tail=tail->next;
        }

        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);
    }

    return ans;
}

void give(node<int>* head)
{
    while(head)
    {
        cout<< head->data <<" ";
        head= head->next;
    }
    cout <<endl;
}


int main(){

    BinaryTreeNode<int>* root= takeInput_lvl_Wise();
    cout <<endl;
    cout <<endl;
    // mirror(root);
    // print_lvl_Wise(root);

    // preorder_iterative(root);
    // inorder_iterative(root);
    // postorder(root);
    // cout <<endl;
    // postorder_iterative(root);

    // cout<< "Is it balanced : " <<isBalanced(root).second;
    cout<< "LLiser will work" <<endl;
    // vector<node<BinaryTreeNode<int>* >* > ll = LLiser(root);
    vector<node<int>* > ll = LLiser(root);
    cout<< "LLiser has worked" <<endl;
    for (int i = 0; i < ll.size(); i++)
    {
        give(ll[i]);
        // cout<< ll[i]->data->data <<endl;
    }
    

    cout <<endl;
    cout <<endl;

    // cout<< "Height : "<< HeightDiameter(root).first <<endl;
    // cout<< "Diameter : "<< HeightDiameter(root).second <<endl;

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1


// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 10 -1 -1 11 12 -1 -1 -1 -1 -1

