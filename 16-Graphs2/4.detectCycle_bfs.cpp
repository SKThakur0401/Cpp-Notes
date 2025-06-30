// Detect cycle in an undirected graph using "BFS" and "Adjacency list" ( adjacency list or 2-D matrix... u can solve with other if you know how to use one :)

// Intution behind this code : BFS travels in "level order", so from a point, startingIndex, if a node is visited along two different branches on the same level, then it means there is a cycle!
// Imagine a graph     0-1-2-3 & 3 is connected to 0 , and we start traversing from "0", so in first traversal our queue will have "1 & 2"  and in second traversal it will insert "3" into queue when checking for things connected to "1" and will also insert "3" when checking for things connected to "2", so it will visited "3" when moving along two different paths "on the same level"... which means those two paths are connecting!!! Therefore there's a cycle :)


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool isCycle(int V, vector<int> adj[])      // To check for multiple instances of unconnected
{                                           // components.
    vector<bool> visited(V, false);
    
    for(int i=0; i< V; i++)
    {
        if(!visited[i])
        {
            bool ans = isCycling(V, adj, visited, i);
            if(ans) return true;
        }
    }
    return false;
}


bool isCycling(int V, vector<int> adj[], vector<bool> &visited, int si) {       // To Check whether 
    // there is a cycle in that particular graph from starting index 'si', 

    
    queue<int> pendingNodes;
    pendingNodes.push(si);
    
    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();
        
        if(visited[front]) return true;
        
        visited[front]= true;
        
        for(int i=0; i< adj[front].size(); i++)
        {
            if(!visited[adj[front][i]])
            {
                pendingNodes.push(adj[front][i]);
            }
        }
    }
    
    return false;
}


int main(){


    

    return 0;
}

