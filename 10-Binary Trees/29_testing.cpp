// { Driver Code Starts
//
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

int it=0;

class Solution{
    public:
    
    int fn(int in[], int curr, int si , int ei)
    {
        for(int i=si ; i<= ei; i++)
        {
            if(in[i] == curr) return i;
        }
        return -1;
    }
    
    Node* bt(int in[], int pre[], int si, int ei)
    {
        if(si> ei) return NULL;

        static int it=0;
        int curr= pre[it];
        it++;
        Node* root;
        root->data = curr;
        if(si== ei) return root;

        int pos = fn(in, curr, si, ei);

        root->left  = bt(in, pre, si, pos-1);
        root->right = bt(in, pre, pos+1, ei);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        // if(n<=0) return NULL;
        
        // if(n==1)
        // {
        //     Node* root;
        //     root->data = pre[it];
        //     it++;
        //     return root;
        // }
        // Node* root;
        // // static int it =0;
        // root->data = pre[it];
        // int curr= pre[it];
        // it++;
        // int pos = fn(in, curr, n);
        
        // root->left  = buildTree(in, pre, pos);
        // root->right = buildTree(in, pre, n - pos-1);
        
        // return root;
        
        return bt(in, pre, 0, n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends