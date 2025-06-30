#include "0.0BinaryTree.h"

class node
{
    public:
    int data;
    node* next;
    node(int data): data(data){}
};

class noded
{
    public:
    node* head;
    node* tail;
    noded()
    {
        head= NULL;
        tail= NULL;
    }
};

class trinity
{
    public:
    int max; int min;
    bool ans;
    trinity(int min,int max)
    {
        this->min=min;
        this->max=max;
        min= INT_MAX;
        max= INT_MIN;
        ans= true;
    }
    trinity()
    {
        min= INT_MAX;
        max= INT_MIN;
        ans= true;
    }
};

bool search(BinaryTreeNode<int>* root, int k)
{
    if(root->data == k) return true;
    else if(root->data > k && root->left!= NULL)
    {
        bool fk = search(root->left,k);
        if(fk==true) return true;
    }
    else if(root->data < k && root->right!=NULL)
    {
        bool fk = search(root->right,k);
        if(fk==true) return true;
    }
    return false;
}

void rangePrint(BinaryTreeNode<int>* root, int a,int b)
{
    if(root==NULL) return;
    if(root->data >= a  && root->data <= b)
    {
        rangePrint(root->left, a,b);
        cout  <<  root->data  <<" ";
        rangePrint(root->right,a,b);
    }

    else if(root->data < a)
    {
        rangePrint(root->right,a,b);
    }

    else if(root->data > b)
    {
        rangePrint(root->left,a,b); 
    }
}

trinity isBST(BinaryTreeNode<int>* root)
{
    if(root== NULL)
    {
        trinity trio;
        return trio;
    }
    trinity l= isBST(root->left);
    trinity r= isBST(root->right);

    if(l.ans == false) return l;
    if(r.ans == false) return r;
    if(l.max > root->data || r.min  < root->data)
    {
        trinity trio;
        trio.ans= false;
        return trio;
    }

    int maxima= max(root->data, r.max);
    int minima= min(root->data,l.min);
    trinity trio(minima,maxima);
    return trio;
}

bool BST_finder(BinaryTreeNode<int>*root, int lower= INT_MIN, int upper= INT_MAX)
{
    if(root==NULL) return true;
    if(root->data< lower || root->data> upper) return false;
    bool isLeftOk = BST_finder(root->left,lower,root->data-1);
    bool isRightOk= BST_finder(root->right,root->data,upper);

    return isLeftOk && isRightOk;
}

BinaryTreeNode<int>* buildTree(int arr[],int si, int ei)
{
    if(si> ei) return NULL;
    int mid= (si+ei)/2;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[mid]);
    root->left= buildTree(arr,si,mid-1);
    root->right= buildTree(arr,mid+1,ei);

    return root;
}

noded Flatten_bst(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        noded x;
        x.head=NULL;
        x.tail=NULL;
        return x;
    }
    if(root->left != NULL && root->right != NULL)
    {
        noded lh= Flatten_bst(root->left);
        node* temp= new node(root->data);
        lh.tail->next= temp;
        noded rh= Flatten_bst(root->right);
        temp->next=rh.head;
        lh.tail= rh.tail;
        return lh;
    }

    // else if(root->left == NULL && root->right== NULL) return NULL;
    else if(root->right !=NULL)
    {
        node*temp= new node(root->data);
        noded rh= Flatten_bst(root->right);
        temp->next= rh.head;
        rh.head= temp;
        return rh;
    }

    else if(root->left != NULL)
    {
        noded lh= Flatten_bst(root->left);
        node* temp= new node(root->data);
        lh.tail->next= temp;

        lh.tail= temp;
        return lh;
    }

    else
    {
        noded ans;
        ans.head= new node(root->data);
        ans.tail= ans.head;
        return ans;
    }
    
}

BinaryTreeNode<int>* LCA(BinaryTreeNode<int>* root, int n1, int n2)
{
    if(root==NULL) return NULL;
    if(root->data == n1 || root->data == n2) return root;
    BinaryTreeNode<int>* l = LCA(root->left ,n1,n2);
    BinaryTreeNode<int>* r = LCA(root->right,n1,n2);
    if(l != NULL && r != NULL) return root;
    else if(l != NULL) return l;
    else if(r != NULL) return r;
    return NULL;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    // cout<< search(root,4) <<endl;
    // rangePrint(root,4,10);

    // int arr[]= {1,2,3,4,5,6,7};

    // cout<< isBST(root).ans<<endl;
    // cout<< BST_finder(root)<<endl;

    // BinaryTreeNode<int>* root= buildTree(arr,0,(sizeof(arr)/4) -1);
    // print_lvl_Wise(root);

    // noded d= Flatten_bst(root);
    // node* temp=d.head;
    // while(temp != NULL)
    // {
    //     cout<< temp->data <<" ";
    //     temp=temp->next;
    // }

    BinaryTreeNode<int>* ans= LCA(root,2,11);
    cout<< ans->data <<endl;

    return 0;
}

// 10 6 14 2 8 11 18 -1 -1 -1 -1 -1 -1 -1 -1