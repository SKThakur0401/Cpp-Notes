// Finding diameter of the tree...(It's basically same as finding the longestr carbon chain in an organic compound)     NOTE: THIS IS NOT THE OPTIMISED SOLUTION..


#include "00BinaryTree.h"

int height(BinaryTreeNode<int>* root)
{
    if(root== NULL) return 0;
    int hl= 1 + height(root->left);
    int hr= 1 + height(root->right);
    if(hl > hr) return hl;
    return hr;
}
 
int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL){return 0;}
    int diameter_about_root = height(root->left) + height(root->right);   //longest chain about root

    int diameter_about_left = diameter(root->left);     //longest chain about root->left
    int diameter_about_right= diameter(root->right);    //longest chain about root->right

    // NOW, ANSWER IS MAXIMUM OF the three diameters....(about_root, about_left, about_right)

    return max(diameter_about_root, max(diameter_about_right,diameter_about_left));
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout<< "Diameter is : "<<diameter(root) <<endl;
}

// IN OUR "diameter" FUNCTION... TO CALC TIME-COMPLEXITY.... WE SHOULD IMAGINE 2 CASES... FIRST- A BALANCED TREE WITH EVERYTHING IN SYMMETRY  EG: 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1   (LVL-WISE INPUT)

// SECOND- AN UNBALANCED TREE WITH NO SYMMETRY, EG: 1 -1 2 -1 3 -1 4 -1 5 -1 6 -1 7 -1 8

// THESE EXAMPLES WILL HELP U IMAGINE THE STRUCTURE OF THE TWO TREES...
// NOTE: WHENEVER IN CASE OF TREE.... WHEN THE TIME-COMPLEXITY IS NOT OBVIOUS/ OBVIOUSLY(O(n)) ....
// THEN U MUST IMAGE THESE TWO TREE STRUCTURES....(BCOZ THESE ARE THE EXTREME CASES... ONE FULLY BALANCED AND OTHER COMPLETELY UNBALANCED)... AND FIND TIME-COMPLEXITY IN THESE 2 CASES...

// THE FIRST CASE FORMS A "RECURRENCE RELATION" IDENTICAL TO "MERGE-SORT" THEREFORE, TIME COMPLEXITY = O(n*logn)

// THE SECOND CASE FORMS A "RECURRENCE RELATION" IDENTICAL TO "BUBBLE-SORT" THEREFORE, TIME COMPLEXITY = O(n*n)

// PERCEPTIBLE: THE HEIGHT OF FIRST TREE IS "logn" and it's  TC= n*logn
// PERCEPTIBLE: THE HEIGHT OF SECOND TREE IS "n" and it's  TC= n*n

// THEREFORE...TIME COMPLEXITY = N*(height of tree)

// NOTE: THIS IS NOT AN OPTIMISED SOLUTION... BCOZ EACH TIME WE ARE FINDING THE HEIGHT OF THE TREE.... AND DIAMETER OF THE TREE SEPARATELY...WHEREAS...THEY ARE BOTH LINKED... 
// (   DIAMETER= height(root->left) + height(root->right)   ) 


// IN THE NEXT FILE: WE HAVE WRITTEN THE OPTIMISED CODE...USING THE FOLLOWING POINTS...
// we could have created a class which holds 2 integers.... height and diameter... and recursively returns both... 
// in that way we can calc "height" within the process of calculating diameter!!! (understand this)

// so height is calculated within the process of calculating diameter...now TIME-COMPLEXITY WILL NOT AT ALL BE AFFECTED BY THE HEIGHT... NEW TIME-COMPLEXITY= O(n)  and earlier it was O(n* (height))...now since height is calculated within calculation of diameter...calculation of height ain't no consuming time-complexity ....therefore the fctor of height  is eliminated