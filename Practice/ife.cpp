#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


template <typename T>
class TreeNode
{
    public:
    T data;
    TreeNode<T> * left;
    TreeNode<T> * right;
};

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if (!root) return ans;
    
    vector<TreeNode<int>* > vi;
    queue<TreeNode<int>* > pendingNodes;
    vector<int> lefty;
    vector<int> leafy;
    vector<int> righty;
    
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front(); pendingNodes.pop();

        if(!front)
        {
            TreeNode<int>* fir = vi[0];
            TreeNode<int>* las = vi[vi.size()-1];
            if(fir == las)
            {
                if(!fir->left && !fir->right) lefty.push_back(fir->data);
            }

            else
            {
                if(!fir->left && !fir->right) lefty.push_back(fir->data);
                if(!las->left && !las->right) righty.push_back(las->data);
            }

            // for(auto i: vi)
            // {
            //     if(!i->left && !i->right) leafy.push_back(i->data);
            // }

            if(!pendingNodes.empty()) pendingNodes.push(NULL);
            vi.clear();
            continue;
        }

        vi.push_back(front);
        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);
        if(!front->left && !front->right) leafy.push_back(front->data);
    }
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
    
}


int main(){


    

    return 0;
}






/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// vector<int> traverseBoundary(TreeNode<int>* root){
//     // Write your code here.
//     vector<int> ans;
//     vector<TreeNode<int>* > vi;
//     queue<TreeNode<int>* > pendingNodes;
    
    
// }

#include<bits/stdc++.h>
using namespace std;

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if (!root) return ans;
    
    vector<TreeNode<int>* > vi;
    queue<TreeNode<int>* > pendingNodes;
    vector<int> lefty;
    vector<int> leafy;
    vector<int> righty;
    
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front(); pendingNodes.pop();

        if(!front)
        {
            TreeNode<int>* fir = vi[0];
            TreeNode<int>* las = vi[vi.size()-1];
            bool vi0= false;
            bool vil= false;
            if(fir == las)
            {
                if(fir->left || fir->right) {lefty.push_back(fir->data); vi0= true;}
            }

            else
            {
                if(fir->left || fir->right) {lefty.push_back(fir->data); vi0 = true;}
                if(las->left || las->right) {righty.push_back(las->data); vil= true;}
            }

            for(auto i: vi)
            {
   if(!i->left && !i->right && (i != vi[0] || !vi0) && (i != vi[vi.size()-1] || !vil)) leafy.push_back(i->data);
            }

            if(!pendingNodes.empty()) pendingNodes.push(NULL);
            vi.clear();
            continue;
        }

        vi.push_back(front);
        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);
//         if(!front->left && !front->right) leafy.push_back(front->data);
    }
    
//     cout<<"Left : ";
//     for(int i=0; i< lefty.size(); i++)
//     {
//         cout<< lefty[i]<<" ";
//     }
//     cout<<endl;
    
//     cout<<"Leaf : ";
//     for(int i=0; i< leafy.size(); i++)
//     {
//         cout<< leafy[i]<<" ";
//     }
//     cout<<endl;
    
//     cout<<"Right : ";
//     for(int i=0; i< righty.size(); i++)
//     {
//         cout<< righty[i]<<" ";
//     }
//     cout<<endl;
    
    for(int xxx=0; xxx< leafy.size(); xxx++){
        lefty.push_back(leafy[xxx]);
    }
    
    leafy.clear();
//     reverse(righty.begin(), righty.end());
    
    for(int ix= righty.size()-1; ix>=0; ix--)
    {
        lefty.push_back(righty[ix]);
    }
    righty.clear();
    return lefty;
}


