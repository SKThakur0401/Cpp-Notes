#include<iostream>
#include<climits>
#include<queue>
#include<vector>

using namespace std;

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
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};


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

BinaryTreeNode<int>* takeakeInput_lvl_Wise()
{
    int rootData; cin>>rootData;
    if(rootData== -1){return NULL;}

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        cout<< "left of "<<front->data<<" is : ";
        int leftData; cin>>leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int>* left= new BinaryTreeNode<int>(leftData);
            pendingNodes.push(left);
            front->left= left;
        }
        else{front->left= NULL;}


        cout<< "right of "<<front->data<<" is : ";
        int rightData; cin>>rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int>* right= new BinaryTreeNode<int>(rightData);
            pendingNodes.push(right);
            front->right=right;
        }
        else{front->right=NULL;}
    }
    return root;
};

int countNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL) return 0;
    int c=1;

    c+=countNodes(root->left)+countNodes(root->right);
    return c;
}

int position(int in[],int si,int ei,int curr)   //To find "position" for "buildTree" function...
{
    for (int i = si; i <= ei; i++)
    {
        if(in[i] == curr) return i;
    }
}

BinaryTreeNode<int>* buildTree(int pre[], int in[], int si,int ei)
{

    if(si> ei) return NULL;
    static int i=0;
    int curr= pre[i];
    BinaryTreeNode<int>*root= new BinaryTreeNode<int>(curr);
    i++;
    if(si==ei) return root;
    int pos = position(in,si,ei,curr);
    root->left=buildTree(pre,in,si,pos-1);
    root->right=buildTree(pre,in,pos+1,ei);
    return root;
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root)
{
    if (root==NULL)
    {
        pair<int,int> p;
        p.first=0; p.second=0; return p;
    }
    
    pair<int,int> lhd = heightDiameter(root->left);
    pair<int,int> rhd = heightDiameter(root->right);

    int ht= 1+ max(lhd.first , rhd.first);

    int dm= max(lhd.first+ rhd.first, max(lhd.second,rhd.second));
    pair<int,int> p;
    p.first=ht;
    p.second=dm;
    return p;
}

class node
{
    public:
    int data;
    node* next;
    node(int d): data(d) {}
};


void printLL(node* head)
{
    while (head != NULL)
    {
        cout<< head->data <<" ";
        head=head->next;
    }
    cout <<endl;
}


vector<node*> LLiser(BinaryTreeNode<int>* root)
{
    vector<node*> v;
    node* head=NULL;
    node* tail=NULL;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front==NULL)
        {
            tail=NULL;
            head=NULL;
            if(!pendingNodes.empty()) pendingNodes.push(NULL);
        }
        else
        {
            if(head==NULL)
            {
                node* newNode= new node(front->data);
                head=newNode;
                tail=newNode;
                v.push_back(head);
            }
            else
            {
                tail->next= new node(front->data);
                tail=tail->next;
            }
            if(front->left != NULL) pendingNodes.push(front->left);
            if(front->right != NULL) pendingNodes.push(front->right);
        }
    }
    return v;
}


int main()
{
    // cout <<endl;
    // cout <<endl;
    // int in[]={2,10,3,9,5,6};
    // int pre[]={5,10,2,3,9,6};
    // BinaryTreeNode<int>* root= buildTree(pre,in,0,(sizeof(pre)/4) -1);
    // print_lvl_Wise(root);

    // BinaryTreeNode<int>* root= takeakeInput_lvl_Wise();
    // cout <<endl;
    // cout <<endl;
    // cout <<endl;
    // cout<< heightDiameter(root).second <<endl;
    // cout<< INT_MAX <<endl;


    BinaryTreeNode<int>* root= takeakeInput_lvl_Wise();
    cout <<endl;
    cout <<endl;
    cout <<endl;
    // vector<node*> v= LLiser(root);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     printLL(v[i]);
    // }
    cout<< "Diameter is : "<< heightDiameter(root).second <<endl;
    
    return 0;
}


