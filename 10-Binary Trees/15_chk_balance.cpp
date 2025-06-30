// RETURN TRUE IF THE TREE IS BALANCED...ELSE FALSE.... A BALANCED TREE IS A TREE IN WHICH FOR ANY NODE.. THE DIFFERENCE BETWEEN IT'S LEFT AND RIGHT HEIGHTS IS EITHER "0 OR 1" AND NOT MORE THAN 1 !!! ....    THIS WILL MAKE MORE SENSE AFTER YOU STUDY "BST" WHERE TIME-COMPLEXITY IS PROPORTIONAL TO "HEIGHT OF THE TREE"... AND A BALANCED TREE HAS THE MINIMUM HEIGHT FOR THE MAXIMUM NUMBER OF NODES... THE HEIGHT DIFFERENCE SHOULD BE 0 ... AT-MOST "1" ... e.g. IN A TREE WITH SEVEN NODES..... MINIMUM HEIGHT POSSIBLE IS "3" BUT WITH "8" NODES.... WE NEED TO ADD ONE EXTRANODE AT EITHER ONE OF THE SIDES...(THEREFORE INCREASING HEIGHT OF ONE SIDE WHILE OTHER REMAINS SAME.... THAT'S WHY HEIGHT DIFFERENCE OF "1" IS ACCEPTED...COZ ITS INEVITABLE TO KEEP IT ALWAYS "0" )

// USING "balance and height" functions is the unoptimised solution it has TC = O(n* (height) )....just like in the case of diameter

// "balancePro" is the optimised/best solution.... where calculation of height and boolean is taking place "simultaneously" thus removing the hardwork of calculating height each time (we r doing the same thing as in file: 13,12)

#include "00BinaryTree.h"


int height(BinaryTreeNode<int>* root)
{
    if(root== NULL) return 0;
    int hl= 1 + height(root->left);
    int hr= 1 + height(root->right);
    if(hl > hr) return hl;
    return hr;
}

bool balance(BinaryTreeNode<int>*root)
{
    if(root==NULL) return true;
    if(abs(height(root->left)-height(root->right)) >1) return false;
    bool l= balance(root->left);
    bool r= balance(root->right);
    return (l && r && true);
}

bint balancePro(BinaryTreeNode<int>*root)
{
    if(root== NULL)
    {
        bint p;
        p.height=0;
        p.b=true;
        return p;
    }

    bint pl= balancePro(root->left);
    bint pr= balancePro(root->right);

    int lh= pl.height;
    int rh= pr.height;
    bool lb= pl.b;
    bool rb= pr.b;

    int height= 1+ max(lh,rh);
    bool b= min( abs(lh-rh)<= 1 ,min(lb,rb));
    if(b == 0)
    {
        bint p;
        p.height= height;
        p.b= b;
        return p;
    }

    bint p;
    p.height=height;
    p.b=b;
    return p;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    cout<<balancePro(root).b <<endl;
}
