// MST : Minimum spanning tree

// In case of "weighted graphs (we discussed it in file-9)" , the graph could be recreated to form the "most minimalistic graph possible!!" .... For a graph with "n" vertices, the most minimalistic graph or the "MST (minimum spanning tree)" will have "n-1" edges.

// The MST is created in such a way that the sum of the weight in going from one end to another is "minimum"

// First revise how to create the "MST" using pen-paper...

// We use "Kruskal's algorithm" to create the MST, here we have Created MST...

// We use "union-find" algorithm, to make sure that we are not making a loop, (bcoz the MST can't have a loop!!)


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class edge
{
    public:
    int si, weight, ei;

    edge(){}

    edge(int si, int ei, int weight)
    {
        this->si= si;
        this->ei= ei;
        this->weight= weight;
    }
};

bool comparator(edge a, edge b)
{
    return a.weight < b.weight;
}

vector<edge> Answerer(edge* arr, int e, int* parent)    // Returns vector which contains the MST
{
    vector<edge> ans;
    for (int i = 0; i < e; i++)
    {
        int a1= arr[i].si;
        int a2= arr[i].ei;
        int granda1= a1;
        int granda2= a2;

        while(parent[granda1] != granda1)
        {
            granda1= parent[granda1];
        }

        while(parent[granda2] != granda2)
        {
            granda2= parent[granda2];
        }
        
        if(granda1== granda2) continue;

        parent[granda1]= granda2;
        ans.push_back(arr[i]);
    }
    return ans;
}

int main(){

    int n,e;
    cin>>n>>e;
    edge* arr= new edge[e];

    for (int i = 0; i < e; i++)
    {
        int si,ei, weight;
        cin>>si>>ei>>weight;
        edge somu(si, ei, weight);
        arr[i]= somu;
    }
    
    sort(arr, arr+e, comparator);

    int* parent= new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
    }
    vector<edge> vi;

    cout <<endl;
    cout <<endl;
    vi= Answerer(arr, e, parent);
    for(edge i: vi)
    {
        cout<<i.si<<" "<<i.ei<<" "<<i.weight<<endl;
    }

    return 0;
}
// TIME COMPLEXITY : Sorting part : E(log(E))
//                 Union-find part: E x V           (V operations to ensure that there is no common parent, and since there's E edges, so time complexity ==> E x V )

// Total time complexity ==>   E(log(E)) + EV

// Now, we can't further optimise the sorting part, so it will cost E(log(E)) only, but we can further optimise by making changes in the "union-find-algorithm..." .... so we have "Union by rank and path compression"

// Now with this "Union by rank & path compression" the time complexity of finding parent will be turned to "log(V)" ... earlier it was " V " , so new time complexity would be---- >  Time Complexity = E(log(E)) + E(log(V))



// 6 11
// 0 1 1
// 0 2 5
// 2 3 10
// 0 3 4
// 1 3 3
// 1 2 6
// 3 4 7
// 2 4 8
// 4 5 2
// 2 5 9
// 3 5 6