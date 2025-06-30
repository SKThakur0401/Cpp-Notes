#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node* node)
{

}


int main(){

    int n,e;
    vector<vector<Node*> > vi(n);

    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        vi[f]
    }
    
    

    return 0;
}

