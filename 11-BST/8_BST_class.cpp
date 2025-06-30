// Here we are going to make a class explicitly for " BSTs " .... this class will have "3" functions, 
//  "hasData"---> which takes a number as argument and returns true if that no. is present in BST

// "insert"---> takes a no. as argument.... and insert it into the "BST" at its rightful place :)

// "del" ---> takes a no. as argument.... and delete it from the LL... NOTE: here we will have to face three scenarios.... I> the deleted node don't have any kids, here we can simply delete root without a care in the world ;)       NOTE: We named our function "del" and not "delete" bcoz "delete" is a reserved keyword.

// II> the deleted node had one child ..... then we will simply make it point to that child :)

// III> the deleted node has both children... here we will do something unique... we will find the "min" no. on the right of "Node" .... and place that no. at the place of node (which has to be deleted).... and now we will delete the node...(which earlier had the min term on the right) so....our required term is deleted... and our BST is also maintained :)

#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data)
    {
        this->data= data;
        left= NULL;
        right= NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput_lvlWise()
{
    int rootData; cin>>rootData;
    if(rootData== -1) {return NULL;}
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "Enter left of "<<front->data <<" : ";
        int l; cin>>l;
        if(l != -1)
        {
            BinaryTreeNode<int>* nodel= new BinaryTreeNode<int>(l);
            front->left= nodel;
            pendingNodes.push(nodel);
        }

        cout<< "Enter right of "<<front->data <<" : ";
        int r; cin>>r;
        if (r != -1)
        {
            BinaryTreeNode<int>* noder= new BinaryTreeNode<int>(r);
            front->right= noder;
            pendingNodes.push(noder);
        }
    }
    return root;
}

void print_lvl_Wise(BinaryTreeNode<int>* root)
{
    if(root== NULL){return;}

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< front->data <<": ";
        if (front->left != NULL)
        {
            cout<< "L-"<<front->left->data <<",";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout<< "R-"<<front->right->data <<",";
            pendingNodes.push(front->right);
        }
        cout <<endl;
    }
}

// Search, insert and delete are three functions of this class

template <typename T>
class BST
{
    public:
    BinaryTreeNode<T>* root;

    BST(){}
    BST(BinaryTreeNode<int>* root)
    {
        this->root= root;
    }

    private:
    bool hasData(T data, BinaryTreeNode<T>* root)
    {
        if(root== NULL) return false;
        if(root->data== data) return true;
        else if(root->data > data)
        {
            return hasData(data, root->left);
        }

        else
        {
            return hasData(data,root->right);
        }
    }

    BinaryTreeNode<int>* insert(T data, BinaryTreeNode<T>* root)
    {
        if(root== NULL)
        {
            root= new BinaryTreeNode<int>(data);
            return root;
        }

        if(data > root->data)
        {
            root->right=insert(data,root->right);
        }

        if(data== root->data)
        {
            root->right=insert(data,root->right);
        }

        if(data < root->data)
        {
            root->left=insert(data,root->left);
        }
        return root;
    }

    BinaryTreeNode<int>* minBTN(BinaryTreeNode<int>* root)
    {
        if(root->left == NULL) return root;
        return minBTN(root->left);
    }

    BinaryTreeNode<int>* del(T data, BinaryTreeNode<int>* root)
    {
        if(root== NULL) return NULL;

        if(root->data == data)
        {
            if(root->left == NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            
            else if(root->left != NULL && root->right!=NULL)
            {
                BinaryTreeNode<int>* min = minBTN(root->right);
                root->data= min->data;
                // delete min;           // This gives "inaccurate/ slightly incorrect results"... the line below gives correct result
                root->right= del(min->data, root->right);
                return root;
            }

            else if(root->left== NULL)      // here, we can simply do  "return root->right"
                                            // that would be fine...but it wouldn't delete the "root" from heap memory and it will permanently remain there :( ...  we can't simply do "delete root" coz it will delete everything that follows and we need to return "root->right" .... so we will smartly remove it
            {
                BinaryTreeNode<int>* temp = root->right;
                // delete root;     // this will eradicate everything after root...bcoz of our  
                                    // custom made delete destructor :)

                root->right= NULL;   // Now since "x" or root->right is cutoff from the link..      
                                    // deleting root wouldn't be a problem
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int>* temp= root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
        }

        else if(root->data > data)
        {
            root->left= del(data,root->left);
        }

        else if(root->data < data)
        {
            root->right= del(data,root->right);
        }
        return root;
    }


    public:
    bool hasData(T data)
    {
        return hasData(data,root);
    }

    BinaryTreeNode<int>* insert(T data)
    {
        return insert(data,root);
    }

    BinaryTreeNode<int>* del(T data)
    {
        return del(data,root);
    }


    ~BST()
    {
        delete root;            // We have already customised our "BinaryTreeNode class" such that 
                                // when asked to delete root.... it will delete the entire tree
                                // Here we have clearified that when asked to delete a "BST" ... this class must also delete the "BinaryTree" residing within :)
    }
};



// int main()
// {
//     BinaryTreeNode<int>* root= takeInput_lvlWise();
//     BST<int> s(root);
//     cout <<endl;
//     cout <<endl;
//     cout <<endl;
//     root= s.insert(1);
//     root= s.insert(3);
//     root= s.insert(5);
//     root= s.insert(7);
//     root= s.insert(14);
//     root= s.insert(21);
//     root= s.insert(28);
//     root= s.insert(35);
//     root= s.insert(42);
//     root= s.insert(49);
//     // root= s.del(49);
//     // root= s.del(64);
//     root= s.del(16);
//     // root= s.del(21);
//     // root= s.del(42);
//     print_lvl_Wise(root);
//     // cout<<s.hasData(4)<<endl;
// }

int main()
{
    BinaryTreeNode<int>* root= takeInput_lvlWise();
    BST<int> meriTree(root);
    cout <<endl;
    cout <<endl;
    // meriTree.insert(31);
    cout<< meriTree.hasData(31) <<endl;
    // meriTree.insert(88);
    cout<< meriTree.hasData(88) <<endl;

    root=meriTree.insert(4);
    root=meriTree.insert(9);
    root=meriTree.insert(8);
    root=meriTree.insert(5);
    root=meriTree.del(4);
    root=meriTree.del(9);
    root=meriTree.del(8);
    root=meriTree.del(5);


    print_lvl_Wise(root);
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

// 10 6 14 2 8 11 18 -1 -1 -1 -1 -1 -1 -1 -1



// 16 4 64 2 8 32 128 -1 -1 -1 -1 -1 -1 -1 -1

// NOTE: ALL THESE OPERATIONS...(INSERT, DEL, HASDATA) HAVE TIME COMPLEXITY OF O(height) .... so it is very important to create a balanced binary tree....to reduce time complexity... ek completely unbalanced binary tree....time complexity O(n) de dega (where "n" is no. of nodes) ...this makes the use of binary tree completely meaningless :)

// We are looking for a balanced BST... where height= log(n) .... and its most efficient in processing data...

// A balanced BST is where ... difference in (left-height and right-height is 0  or 1) ... ofcourse it means that elements are as closely packed as possible... bcoz for a tree of 7 elements... the difference will be "0"  and for a tree of 8 elements...it will be "1" bcoz we need to adjust that extra element and for that we need to raise the height on one side by "1"..... but after that next element will be added on the other side to make height difference again "0" otherwise it would become "2" and this does not QUALIFY TO BE BALANCED :)


