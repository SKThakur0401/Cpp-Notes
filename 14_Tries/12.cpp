// { Driver Code Starts

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


using namespace std;
#define MAX 1000

vector<vector<int> > uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int> > vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends

#include<vector>
/*You are required to complete this function*/

class TrieNode
{
    public:
    bool isTerminal;
    bool data;
    TrieNode* left;
    TrieNode* right;
    TrieNode(bool d)
    {
        data= d;
        left=NULL;
        right=NULL;
        
        isTerminal= false;
    }
    
    ~TrieNode()
    {
        delete left;
        delete right;
    }
};

class Trie
{
    TrieNode* root;
    public:
    Trie()
    {
        root= new TrieNode(true);
    }
    
    void insert(int arr[], int n, TrieNode* root)
    {
        if(n==0)
        {
            root->isTerminal= true;
            return;
        }
        
        if(arr[0])
        {
            if(root->right==NULL) root->right= new TrieNode(true);
            insert(arr+1, n-1, root->right);
            return;
        }
        if(root->left==NULL) root->left= new TrieNode(false);
        insert(arr+1,n-1, root->left);
        return;
    }
    
    void insert(int arr[], int n)
    {
        insert(arr,n, root);
    }
    
    bool search(int arr[],int n, TrieNode* root)
    {
        if(n==0) return root->isTerminal;
        
        if(arr[0])
        {
            if(root->right !=NULL && root->right->data== true) return search(arr+1,n-1,root->right);
        
            return false;
        }
        else
        {
            if(root->left !=NULL && root->left->data== false) return search(arr+1, n-1, root->left);
        
            return false;
        }
    }
};



vector<vector<int> > uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    Trie somu;
    vector<vector<int> > ans(row);
    int j=0;
    
    for(int i=0; i<row; i++)
    {
        // somu.insert(M[i], col);
        if(somu.search(M[i], col))
        {
            for(int x=0; x< col; x++)
            {
                ans[j].push_back(M[i][x]);
            }
            j++;
        }
        somu.insert(M[i], col);
    }
    return ans;
}



