#include<iostream>
#include<queue>
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

BinaryTreeNode<pair<int, char> >* insert(priority_queue<pair<int, char>, vector<pair<int, char> >, greater<pair<int,char> > > &pq ,  BinaryTreeNode<pair<int,char> >* root)
{
    pair<int,char> p1= pq.top();
    pq.pop();
    pair<int,char> p2= pq.top();
    pq.pop();
    pair<int,char> x;
    x.first = p1.first + p2.first;
    x.second=NULL;
    root= new BinaryTreeNode<pair<int,char >(x);
    root->left= new BinaryTreeNode<pair<int,char >(p1);
    root->right= new BinaryTreeNode<pair<int,char >(p2);
    pq.push(x);

    return root;
}

void Huff(string s)
{
    // int arr[26];
    int arr[26]={0};

    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i]- 'a']++;
    }

    priority_queue<pair<int, char>, vector<pair<int, char> >, greater<pair<int,char> > >pq;
    
    for (int i = 0; i < 26; i++)
    {
        pair<int, char> pi(arr[i], char('a'+i));
        pq.push(pi);
    }
    

    BinaryTreeNode<pair<int,char> >* root;

    while(!pq.empty())
    {

    }
    
}

int main(){

    string s; cin>>s;

    Huff(s);
    

    return 0;
}