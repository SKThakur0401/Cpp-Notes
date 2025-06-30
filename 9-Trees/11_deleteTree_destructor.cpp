// TILL NOW WE HAVE CREATED ALL TREES DYNAMICALLY... WHICH MEANS WE HAVE TO EXPLICITLY DELETE ALL THESE TREES... OTHERWISE THEY WILL ALWAYS BE THERE IN "HEAP MEMORY"

// TO DELETE A TREE THERE ARE 2 WAYS.... METHOD-1> THE OBVIOUS WAY.. CREATING A FUNCTION THAT DELETES ALL NODES... WE CAN'T SIMPLY DELETE THE "ROOT" WE HAVE TO FIRST DELETE ALL ITS CONNECTED CHILDREN AND THEN DELETE THE ROOT.... FUNCTION NAME -->  "deleteTree"     (it is a simple code... I am not doing here)

// THIS METHOD IS VERY SIMILAR TO CALLING "postOrder" printing... there we started printing from the bottom then slowly going up.... here we have to start deleting from bottom... then slowly going up


// Method-2>  #THE COOL METHOD
// OUR DEFAULT DESTRUCTOR ( " delete root " ) just simply deletes a node...and doesn't care about it's connected children...(they continue to stay in the heap memory :(  

// WE CAN CREATE OUR OWN "DESTRUCTOR"  :)       ...WE DON'T HAVE TO CREATE A SEPARATE FUNCTION TO DELETE A TREE... WE CAN JUST IMPROVISE THE DEFAULT DESTRUCTOR TO DO THAT FOR US.... so even if we type         "  delete root  "    ... it will delete the entire tree :)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode*> children;
    treenode(T data){this->data=data;}

    ~treenode()                         // NOW WHEN WE CALL THE DESTRUCTOR...IT WILL DO THE 
    {                                   // FOLLOWING TASK...AND THEN DELETE THE "NODE" WHICH U ASKED TO DELETE... SO IT WILL BASICALLY FIRST DELETE ALL ITS CHILDREN/GRANDCHILDREN AND THEN DELETE THE NODE WE ASKED TO DELETE... MAKING THE "delete" function worthwhile :)
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

// Now below is an example to verify if it's working or not... it's working so no need to see below

void printTree_lvl_wise(treenode<int>* root)
{
    queue<treenode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL)
        {
            cout <<endl;
            if(pendingNodes.front() != NULL) pendingNodes.push(NULL);
            continue;
        }

        cout<< front->data <<" ";

        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
        }
        
    }
}

treenode<int>* takeInput_lvl_wise()
{
    int rootData; cin>>rootData;
    treenode<int>* root= new treenode<int>(rootData);

    queue<treenode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<< "How many children u want for "<< front->data<<" : ";
        int numChild; cin>>numChild;

        for (int i = 0; i < numChild; i++)
        {
            cout<< "Enter "<<i+1<<"th child of "<< front->data <<" : ";
            int data; cin>>data;
            treenode<int>* child= new treenode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


int main()
{
    treenode<int>* root= takeInput_lvl_wise();

    cout<<endl;
    printTree_lvl_wise(root);
    treenode<int>* rootChild= root->children[0];
    delete root;

    cout <<endl;

    printTree_lvl_wise(rootChild);

    return 0;
}

// 1 3 2 3 4 2 5 6 0 0 0 0