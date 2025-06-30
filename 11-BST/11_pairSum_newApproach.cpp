// HERE WE R GOING TO USE VECTORS...BCOZ ITS EASIER TO FILL ELEMENTS IN IT FROM BINARY TREE... WE WILL ALSO CUSTOMIZE OUR "MERGE-SORT" PROGRAM TO WORK FOR VECTORS...(QUITE EASY/LOGICAL...BE MINIMALISTIC).... THEN USING 2 VARIABLES...FIND THE ANSWER

// NOTE: In case of BST... u can use inorder traversal to get the array in ascending/descending order

#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int si, int mid , int ei)
{
    int n1= mid-si +1;
    int n2= ei-mid ;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i]=arr[si+i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i]=arr[mid+1+i];
    }
    
    int i,j,k;
    i=0;j=0;k=si;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j]){  arr[k]=a[i]; k++;   i++;}
        else if(a[i]>b[j]){  arr[k]=b[j]; k++;   j++;}
        else if(a[i] == b[j]){ arr[k]=a[i]; k++; i++; arr[k]=b[j]; k++; j++;}
    }
    while (i<n1)
    {
        arr[k]=a[i];k++;i++;
    }
    while (j<n2)
    {
        arr[k]=b[j];k++;j++;
    }
}

void msort(vector<int>& arr, int si , int ei)
{

    if(si>=ei){return;}
    int mid = (si+ei)/2;

    msort(arr,si , mid);
    msort(arr,mid+1,ei);
    merge(arr, si, mid , ei);
}


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
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput_lvl_Wise()
{
    int rootData; cin>>rootData;
    if(rootData== -1)return NULL;

    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        int leftData; cin>> leftData;
        if(leftData != -1)
        {
            front->left= new BinaryTreeNode<int>(leftData);
            pendingNodes.push(front->left);
        }

        int rightData; cin>> rightData;
        if(rightData != -1)
        {
            front->right= new BinaryTreeNode<int>(rightData);
            pendingNodes.push(front->right);
        }
    }
    return root;
}

void filler(BinaryTreeNode<int>*root,vector<int>&allForOne)
{
    if(root== NULL) return;

    allForOne.push_back(root->data);
    filler(root->left, allForOne);
    filler(root->right, allForOne);
}

void pairSum(BinaryTreeNode<int>*root,vector<int> v ,int k)
{
    filler(root,v);
    msort(v,0,v.size()-1);

    int i=0; int j= v.size()-1;

    while(i<j)
    {
        if(v[i]+ v[j] == k)
        {
            cout<<v[i]<<" "<<v[j]<<endl;
            i++; j--;
        }
        else if(v[i]+ v[j] > k) j--;
        else if(v[i]+ v[j] < k) i++;
    }
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvl_Wise();

    vector<int> v;
    cout <<endl;
    cout <<endl;
    cout <<endl;

    cout<< "What u want the sum to be : ";
    int sum; cin>> sum;
    pairSum(root,v,sum);

    return 0;
}

// 9 3 10 1 6 -1 14 -1 -1 -1 -1 -1 -1