// THIS IS THE SOLUTION U SHOULD ACTUALLY USE...
// THIS IS A VERY IMPORTANT QUESTION...UNDERSTAND IT THOROUGHLY

// HERE WE ARE "SIMULTANEOUSLY" HANDLING "HEIGHT" AND "DIAMETER"

#include "00BinaryTree.h"

pair<int,int> heightDiameter(BinaryTreeNode<int>* root)
{
    if (root== NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> nodel= heightDiameter(root->left);
    pair<int,int> noder= heightDiameter(root->right);
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


pair<int,int> HeightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftAns = HeightDiameter(root->left);
    pair<int,int> rightAns = HeightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;
    
    pair<int,int> ans;

    ans.first = 1+ max(lh,rh);
    ans.second = max(lh+rh,max(rd,ld));

    return ans;
}

pair<int,int> MinMax(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int,int> left =MinMax(root->left);
    pair<int,int> right = MinMax(root->right);

    pair<int,int> ans;
    ans.first = min(root->data,min(left.first,right.first));
    ans.second = max(root->data,max(left.second,right.second));

    return ans;

}

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    cout <<endl;
    cout <<endl;

    pair<int,int> p= heightDiameter(root);
    pair<int,int> p2= HeightDiameter(root);
    pair<int,int> mm= HeightDiameter(root);

    cout<< "height is : "<<p.first <<endl;
    cout<< "Diameter is : "<<p.second <<endl;

    cout<< "height is : "<<p2.first <<endl;
    cout<< "Diameter is : "<<p2.second <<endl;

    cout<< "min is : "<<p.first <<endl;
    cout<< "max is : "<<p.second <<endl;
}