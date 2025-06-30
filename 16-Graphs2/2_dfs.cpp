#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


void printDFS(vector<int> adj[], bool* visited, int si=0)
{
    cout<< si <<"  ";
    visited[si]=1;

    for (int i = 0; i < adj[si].size(); i++)
    {
        if(!visited[adj[si][i]]) printDFS(adj, visited, adj[si][i]);
    }
}

void DFS(vector<int> adj[], int v)
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
            printDFS(adj, visited, i);
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
    
    DFS(adj, v);

    
    return 0;
}


