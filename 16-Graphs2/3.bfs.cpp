#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


void printBFS(vector<int> adj[], bool* visited, int si)
{
    queue<int> pendingNodes;
    pendingNodes.push(si);

    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();
        if(visited[front]) continue;
        cout<< front <<endl;
        visited[front]= true;

        for (int i = 0; i < adj[front].size(); i++)
        {
            if( !visited[adj[front][i]] ) pendingNodes.push(adj[front][i]);
        }
    }
}

void BFS(vector<int> adj[], int v)
{
    bool *visited= new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            printBFS(adj, visited, i);
        }
    }
}


int main(){

    int v,e;
    cin>>v>>e;

    vector<int> adj[v+1];

    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    
    BFS(adj, v);

    return 0;
}


