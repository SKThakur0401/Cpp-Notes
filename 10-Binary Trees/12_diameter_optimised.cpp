// THIS IS THE SOLUTION U SHOULD ACTUALLY USE...
// THIS IS A VERY IMPORTANT QUESTION...UNDERSTAND IT THOROUGHLY

// HERE WE ARE "SIMULTANEOUSLY" HANDLING "HEIGHT" AND "DIAMETER"

#include "00BinaryTree.h"

pair<int,int> heightDiameter_old(BinaryTreeNode<int>* root)
{
    if (root== NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> nodel= heightDiameter_old(root->left);
    pair<int,int> noder= heightDiameter_old(root->right);
    int lh = nodel.first;
    int rh = noder.first;
    int ld = nodel.second;
    int lr = noder.second;
    int height= 1+ max(lh,rh);
    int diameter= lh+rh;
    pair<int,int> p;
    p.first=height;
    p.second= max(diameter, max(nodel.second,noder.second));
    return p;
}


pair<int,int> heightDiameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> ans(0,0);
        return ans;
    }
    pair<int,int>  leftAns = heightDiameter(root->left);
    pair<int,int> rightAns =heightDiameter(root->right);

    int lh= leftAns.first;
    int rh= rightAns.first;
    int ld= leftAns.second;
    int rd= rightAns.second;

    int height  = 1+ max(lh,rh);
    int diameter = max(lh + rh, max(ld,rd));

    pair<int,int> ans(height ,diameter);

    return ans;
}


int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    pair<int,int> p= heightDiameter_old(root);
    pair<int,int> q= heightDiameter(root);

    cout<< "height_old is : "<<p.first <<endl;
    cout<< "Diameter_old is : "<<p.second <<endl;


    cout<< "height is : "<<q.first <<endl;
    cout<< "Diameter is : "<<q.second <<endl;

}


