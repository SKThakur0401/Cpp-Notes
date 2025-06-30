#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode<T>* > children;

    treenode(T data)
    {
        this->data= data;
    }

    // void takeInput
};

// template <typename T>
treenode<int>* takeInput(int a=1 , int b=-1)
{
    cout<< "Enter " <<a<< "th child of "<< b<<" :";
    int d; cin>>d;
    treenode<int>* root= new treenode<int>(d);

    cout<< "How many children does "<<root->data<<" have: ";
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        treenode<int>* child = takeInput(i+1, d);
        root->children.push_back(child);
    }

    return root;
}


treenode<int>* takeInput_lvl_Wise()
{
    int rd; cin>>rd;
    treenode<int>* root= new treenode<int>(rd);

    queue<treenode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        treenode<int>* front= pendingNodes.front(); pendingNodes.pop();

        cout<< "How many children does "<< front->data<<" have : ";
        int numChild; cin>>numChild;

        for (int i = 0; i < numChild; i++)
        {
            cout<< "Enter "<< i+1<< "th child of "<< front->data<<" : ";
            int cd; cin>>cd;
            treenode<int>* child= new treenode<int>(cd);
            front->children.push_back(child);

            pendingNodes.push(child);
        }
    }
    return root;
}

// template <typename T>
void printer(treenode<int>* root)
{
    cout<< root->data <<" : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<< root->children[i]->data <<",";
    }
    cout <<endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printer(root->children[i]);
    }
    return;
}

void print_lvl_Wise(treenode<int>* root)
{
    queue<treenode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        treenode<int>* front = q.front(); q.pop();

        cout<< front->data << " : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            cout<< front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout <<endl;
    }
}


void lvl_Wise_print(treenode<int>* root)
{
    queue<treenode<int>*> q;
    q.push(root); q.push(NULL);

    while(!q.empty())
    {   
        if(!q.front())
        {
            q.pop(); cout <<endl;
            if(!q.empty()) q.push(NULL);
        }

        else
        {
            treenode<int>* front= q.front(); q.pop();
            cout<< front->data <<" ";

            for (int i = 0; i < front->children.size(); i++)
            {
                q.push(front->children[i]);
            }
        }
    }
}

int height(treenode<int>* root)
{
    if(root== NULL) return 0;

    int h=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        h= max(h, height(root->children[i]));
    }
    return 1+h;
}

int count(treenode<int>* root)
{
    if(!root) return 0;
    int c=1;
    for (int i = 0; i < root->children.size(); i++)
    {
        c+= count(root->children[i]);
    }
    return c;
}

pair<int,int> solve(treenode<int>* root, pair<int,int> pi)
{
    if(root->data > pi.first)
    {
        pi.second= pi.first;
        pi.first= root->data;
    }

    else if(root->data > pi.second)
    {
        pi.second=root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        pi = solve(root->children[i], pi);
    }
    return pi;
}

int second_Largest(treenode<int>* root)
{
    pair<int,int> pi(INT_MIN, INT_MIN);
    return solve(root, pi).second;
}



int main(){

    treenode<int>* root= takeInput_lvl_Wise();
    cout <<endl;
    print_lvl_Wise(root);

    cout <<endl;
    cout <<endl;
    cout<< "HEIGHT : "<< height(root) <<endl;
    cout <<endl;
    cout<< "COUNT NODES : "<< count(root) <<endl;
    cout <<endl;
    cout<< "Second largest : "<< second_Largest(root) <<endl;
    return 0;
}

// 1 3 2 2 5 0 6 0 3 0 4 0

// 1 3 2 2 5 0 6 0 3 2 7 0 8 0 4 0

// 1 3 2 2 5 1 10 0 6 0 3 2 7 1 11 0 8 0 4 0



// LEVEL WISE INPUT
// 1 3 2 3 4 2 5 6 2 7 8 0 1 10 0 1 11 0 0 0

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 0 0 0