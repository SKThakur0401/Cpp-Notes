#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int main(){

    int v,e;
    cin>>v>>e;

    vector<int> adj[v+1];       // An array of size "v+1" where each element is " vector<int> "
                                // "v+1" assuming 1-based indexing :)
                                // had it been 0-based indexing, size of array would have been "v"
    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);           // In case of directed graph this wouldn't have been there :)
    }
    

    // In case of weighted graph we would have used "  vector<pair<int,int> >  "  where one part can hold the ending node, and second part can hold the weight of that edge :)

    // In this undirected-unweighted graph space complexity = O(2*E)

    return 0;
}

