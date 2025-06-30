// Maximum sum of nodes in Binary tree such that no two are adjacent; <--(search this on gfg to get entire question) Maximum possible sum of non adjacent nodes... Easy question in hard section ... if you know dp

#include "00BinaryTree.h"
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

unordered_map< BinaryTreeNode<int>* , int> um;		// For memoisation


int MaxSumOfNodes(BinaryTreeNode<int>* root)
{
	if(!root) return 0;

	if(um.count(root)) return um[root];

	int a1 = MaxSumOfNodes(root->left) + MaxSumOfNodes(root->right);

	int a2;
	if(root->left && root->right)
	{
		a2 = root->data + MaxSumOfNodes(root->left->left) + MaxSumOfNodes(root->left->right)+ MaxSumOfNodes(root->right->left)+ MaxSumOfNodes(root->right->right);
	}

	else if(root->left)
	{
		a2 = root->data + MaxSumOfNodes(root->left->left) + MaxSumOfNodes(root->left->right);
	}

	else if(root->right)
	{
		a2 = root->data + MaxSumOfNodes(root->right->left) + MaxSumOfNodes(root->right->right);
	}

	else if(!root->left && !root->right)
	{
		a2= root->data;
	}

	return um[root] = max(a1,a2);
}

int main()
{
	BinaryTreeNode<int>* root = takeInput_lvlWise();
	cout <<endl;
	cout <<endl;
	cout<< MaxSumOfNodes(root) <<endl;

	return 0;
}
