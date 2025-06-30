// Construct Binary Tree from String with bracket representation

// Input : "1(2)(3)" 
// Output : 1 2 3
// Explanation :
//            1
//           / \
//          2   3
// Explanation: first pair of parenthesis contains 
// left subtree and second one contains the right 
// subtree. Preorder of above tree is "1 2 3".  


#include "00BinaryTree.h"
#include <stack>

using namespace std;

int fetchEI(string s, int si)
{
    stack<char> st;
    st.push(s[si]);
    int i=si+1;
    while(1)
    {
        if(s[i]== ')') st.pop();
        if(s[i]== '(') st.push('(');

        if(st.empty()) return i;
        i++;
    }
}



BinaryTreeNode<int>* constructTree(string s, int si, int ei)
{
    if(ei == si)
    {
        if(s[si] != '(' || s[si] != ')')
        {
            int x= s[si] - '0';     // TO GET THE INTEGER... WE DID -'0'
            BinaryTreeNode<int>* node = new BinaryTreeNode<int>(x);
            return node;
        }
    }
    if(si> ei) return NULL;

    int x= s[si] - '0';    // WE DID " - '0'  " TO GET THE EXACT INTEGER... OTHERWISE IT WOULD HAVE GIVEN "49", IT'S ASCII VALUE..
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(x);

    int si1 = si+1;
    int ei1 = fetchEI(s, si+1);

    root->left = constructTree(s, si1+1, ei1-1);
    int si2 = ei1+1;
    int ei2 = ei;
    root->right = constructTree(s, si2 +1, ei2 -1);

    return root;
}


int main(){
    // string s = "1(2(4)(5))(3(6)(7))";
    // string s = "4(2(3)(1))(6(5))";
    string s = "1(2(4(6)())(5))(3)";

    BinaryTreeNode<int>* root= constructTree(s , 0 , s.size()-1);

    print_lvl_Wise(root);


    return 0;
}

