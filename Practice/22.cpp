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
        this->data=data;
        left=NULL;
        right=NULL;
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

    root->left= takeInput();
    root->right= takeInput();

    return root;
}

void printing(BinaryTreeNode<int>* root)
{
    if(!root) return;

    cout<< root->data <<": ";
    if(root->left) cout<< root->left->data <<" , ";
    if(root->right) cout<< root->right->data;
    cout <<endl;

    printing(root->left);
    printing(root->right);
}

BinaryTreeNode<int>* takeInput_lvlWise()
{
    int data; cin>>data;
    if(data== -1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(!pendingNode.empty())
    {
        BinaryTreeNode<int>* front= pendingNode.front();
        pendingNode.pop();

        int ld; cin>>ld;
        if(ld != -1)
        {
            front->left= new BinaryTreeNode<int>(ld);
            pendingNode.push(front->left);
        }

        int rd; cin>>rd;
        if(rd != -1)
        {
            front->right= new BinaryTreeNode<int>(rd);
            pendingNode.push(front->right);
        }
    }
    return root;
}

void print_lvlWise(BinaryTreeNode<int>* root)
{
    if(!root) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data<<": ";
        if(front->left)
        {
            cout<< "L- "<<front->left->data<< " , ";
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

BinaryTreeNode<int>* mirror(BinaryTreeNode<int>* root)
{
    if(!root) return NULL;

    swap(root->left, root->right);

    root->left  = mirror(root->left);
    root->right = mirror(root->right);
    return root;
}

pair<int,int> hd(BinaryTreeNode<int>* root)
{
    if(!root)
    {
        pair<int,int> pi(0,0);
        return pi;
    }

    pair<int,int> leftAns = hd(root->left);
    pair<int,int> rightAns = hd(root->right);

    int h = 1+ max(leftAns.first, rightAns.first);
    int d = max(h, max(leftAns.second, rightAns.second));
    pair<int,int> pi(h,d);
    return pi;
}

void post_order(BinaryTreeNode<int>* root)
{
    stack<BinaryTreeNode<int>* > f;
    stack<BinaryTreeNode<int>* > s;

    f.push(root);
    while(!f.empty())
    {
        BinaryTreeNode<int>* topper = f.top();
        f.pop();
        s.push(topper);

        if(topper->left) f.push(topper->left);
        if(topper->right) s.push(topper->right);

    }

    while(!s.empty())
    {
        cout<< s.top()->data <<endl;
        s.pop();
    }
}

void inorder(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* curr= root;
    stack<BinaryTreeNode<int>* > st;
    // st.push(root);

    while(!st.empty() || curr != NULL)
    {
        while(curr)
        {
            st.push(curr);
            curr= curr->left;
        }

        cout<< st.top()->data <<endl;
        curr= st.top()->right;
        st.pop();
        // curr=curr->right;
    }
}

class tri
{
    public:
    int mini; int maxi;
    bool ans;
    tri(int mini, int maxi, bool ans)
    {
        this->mini= mini;
        this->maxi= maxi;
        this->ans= ans;
    }
};

tri isBST(BinaryTreeNode<int>* root)
{
    if(!root)
    {
        tri t(INT_MAX, INT_MIN, true);
        return t;
    }

    tri leftAns= isBST(root->left);
    tri rightAns= isBST(root->right);

    bool b= leftAns.ans && rightAns.ans && (leftAns.maxi < root->data) && (rightAns.mini >= root->data);

    if(!b)
    {
        tri t(0,0, b); return t;
    }

    tri t( min(leftAns.mini,root->data) , max(rightAns.maxi,root->data) , b);
    return t;
}

bool isItBst(BinaryTreeNode<int>* root)
{
    return isBST(root).ans;
}

class BST
{
    public:
    BinaryTreeNode<int>* root;

    BST(){}

    BST(BinaryTreeNode<int>* root)
    {
        this->root= root;
    }

    private:

    bool hasData(int key) {return hasData(root,key);}
    bool insert(int key) {return insert(root,key);}
    bool del(int key) {return del(root,key);}

    public:

    bool hasData(BinaryTreeNode<int>* root, int key)
    {
        if(!root) return false;

        if(root->data == key) return true;

        if(root->data < key) return hasData(root->right, key);
        if(root->data > key) return hasData(root->left, key);
        return false;
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int key)
    {
        if(!root)
        {
            BinaryTreeNode<int>* root= new BinaryTreeNode<int>(key);
            return root;
        }

        if(root->data <= key)
        {
            root->right= insert(root, key);
        }

        if(root->data > key)
        {
            root->left= insert(root->left, key);
        }
        return root;
    }

    BinaryTreeNode<int>* minBTN(BinaryTreeNode<int>* root)
    {
        if(root->left) minBTN(root->left);
        return root;
    }

    BinaryTreeNode<int>* del(BinaryTreeNode<int>* root, int key)
    {
        if(!root) return NULL;

        if(root->data < key) return root->right= del(root->right, key);
        if(root->data > key) return root->left = del(root->left, key);

        if(root->data == key)
        {
            if(!root->left && !root->right)
            {
                delete root; return NULL;
            }

            if(root->left && root->right)
            {
                BinaryTreeNode<int>* temp = minBTN(root->right);
                root->data= temp->data;
                root->right= del(root->right, temp->data);
                return root;
            }

            if(root->left)
            {
                BinaryTreeNode<int>* a = root->left;
                root->left= NULL; delete root;
                return a;
            }

            if(root->right)
            {
                BinaryTreeNode<int>* a = root->right;
                root->right= NULL; delete root;
                return a;
            }
            return NULL;
        }
        return NULL;
    }

};

BinaryTreeNode<int>* leftCopy(BinaryTreeNode<int>* root)
{
    if(!root) return NULL;

    BinaryTreeNode<int>* lc= new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* attachment = root->left;
    root->left= lc;
    lc->left= attachment;
    root->right= leftCopy(root->right);
    lc->left= leftCopy(lc->left);
    return root;
}

BinaryTreeNode<int>* makeTree(int pre[], int n, int mi= INT_MIN, int ma= INT_MAX)
{
    static int index=0;
    if(index==n) return NULL;
    int curr= pre[index];

    if(curr > mi && curr <= ma)
    {
        index++;
        BinaryTreeNode<int>* root= new BinaryTreeNode<int>(curr);
        root->left = makeTree(pre, n, mi, curr);
        root->right = makeTree(pre, n, curr, ma);
        return root;
    }

    return NULL;
}

void morrisInorder(BinaryTreeNode<int>* root)
{
    if(!root) return;
    BinaryTreeNode<int>* curr= root;
    while(curr)
    {
        if(curr->left == NULL)
        {
            cout<< curr->data <<endl;
            curr=curr->right;
        }

        if(curr->left)
        {
            BinaryTreeNode<int>* prev = curr->left;
            while(prev->right != NULL && prev->right != curr)
            {
                prev=prev->right;
            }

            if(prev->right== NULL)
            {
                prev->right =curr;
                curr= curr->left;
            }

            if(prev->right== curr)
            {
                prev->right =NULL;
                cout<< curr->data <<endl;
                curr=curr->right;
            }
        }
    }
}

int main(){

    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    // // print_lvlWise(root);
    // // inorder(root);
    // cout<< isItBst(root) <<endl;

    // int pre[6] = {4,2,1,6,5,7};

    // BinaryTreeNode<int>* root = makeTree(pre , 6);

    // print_lvlWise(root);

    morrisInorder(root);

    return 0;
}
// 4 2 6 1 3 -1 -1 -1 -1 -1 -1 -1



