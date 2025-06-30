// Find and print all paths whose sum come out to be "k" ,

// NOTE: Here, the paths may or may-not start from root!

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

BinaryTreeNode<int>* takeInput_lvlWise()	// I did some minor twitching in this function, and made "-2" The "Null" value indicator ... instead of "-1" .. bcoz in the given question "-1" was required as an input value
{
    int rootData; cin>>rootData;
    if(rootData== -2) return NULL;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "Enter left of "<<front->data <<" : ";
        int l; cin>>l;
        if(l != -2)
        {
            BinaryTreeNode<int>* nodel= new BinaryTreeNode<int>(l);
            front->left= nodel;
            pendingNodes.push(nodel);
        }

        cout<< "Enter right of "<<front->data <<" : ";
        int r; cin>>r;
        if (r != -2)
        {
            BinaryTreeNode<int>* noder= new BinaryTreeNode<int>(r);
            front->right= noder;
            pendingNodes.push(noder);
        }
    }
    return root;
}



void Ksum_paths(BinaryTreeNode<int>* root,int k, vector<int> vi)
{
	if(!root) return;
	if(k <0) return;

	// Ksum_paths(root->left, k, vi);
	// Ksum_paths(root->right, k, vi);

	vi.push_back(root->data);
	k-= root->data;
	if(k==0)
	{
		for (int i = 0; i < vi.size(); i++)
		{
			cout<< vi[i] <<" ";
		}
		cout <<endl;
		return;
	}

	Ksum_paths(root->left, k ,vi );
	Ksum_paths(root->right, k ,vi );
}

void Ksum_Call(BinaryTreeNode<int>* root, int k, vector<int> vi)	// bcoz the path may or may-not start from root, we need to call "Ksum_paths" function on root->left and right also!
{
	if(root->left) Ksum_Call(root->left, k, vi);

	if(root->right) Ksum_Call(root->right, k, vi);

	Ksum_paths(root, k, vi);
}

int main(){

	BinaryTreeNode<int>* root= takeInput_lvlWise();
	vector<int> vi;
	int k=5;
	cout <<endl;
	cout <<endl;
	cout <<endl;

	Ksum_Call(root, k, vi);

	// Ksum_paths(root,k, vi);

	return 0;
}

// GFG question--v

// 1 3 -1 2 1 4 5 -2 -2 1 -2 1 2 -2 6 -2 -2 -2 -2 -2 -2 -2 -2

