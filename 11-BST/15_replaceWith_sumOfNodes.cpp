// QUESTION: REPLACE A NODE WITH (SUM OF ALL THE NODES WHICH ARE GREATER THAN OR EQUAL TO THE NODE ITSELF) ... OFCOURSE WE NEED TO ADD THE NODE ITSELF TO IT ALSO... AND THE TOTAL SUM WOULD BE THE FINAL VALUE/ DATA OF THAT NODE...DO THIS FOR ALL THE NODES :)


// WE CAN DO THIS PROBLEM WITH BRUTE FORCE APPROACH... OF COMPARING EACH NODE WITH ALL NODES AND THEN ADDING THEIR VALUES IF THEY ARE GREATER.... BUT THAT'S NOT THE BEST WAY OUT....TRY TO DO IT THE WAY WE DID "isBST_Pro" ...


// SOLUTION : SINCE WE ARE DEALING WITH "BST" WE SHOULD ACTUALLY TRY TO FIND A WAY TO TRAVEL FROM LARGEST TO SMALLEST ELEMENT....i.e. DESCENDING ORDER... COZ WE KNOW..THE LARGEST ELEMENT WILL NOT NEED ANYTHING TO BE ADDED SO WE ADD "0" THEN WE MOVE TO THE SECOND LARGEST ELEMENT...AND WE NEED TO ADD ONLY "1" ELEMENT TO IT (BECAUSE ONLY ONE ELEMENT IS LARGER THAN IT...) , SO WE MAINTAIN A VARIABLE "sum" which holds sum of all the elements we traverse through..since we r traversing in descending order..."sum" should be added to "root->data" bcoz all the previously visited numbers were greater than root (so they all should be added to root.... in other words, "sum" should be added to root :) ... and all the elements which we'll visit after root will be smaller than root... so this technique is perfect!

// NOW, HOW CAN WE TRAVERSE IN DESCENDING ORDER FASHION. ..... ITS REALLY SIMPLE... JUST USE "INORDER" WITH "root->right.... root .... root->left" fashion... it will anyway traverse in descending order :)


#include "0.0BinaryTree.h"

int replaceWithSum(BinaryTreeNode<int>* &root,int &sum)
{
    if(root==NULL) return 0;
    int rightAns=replaceWithSum(root->right,sum);

    sum+= root->data;
    root->data=sum;

    int leftAns =replaceWithSum(root->left,sum);


    return root->data;
}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;
    cout <<endl;
    int sum=0;
    replaceWithSum(root,sum);
    print_lvl_Wise(root);
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
