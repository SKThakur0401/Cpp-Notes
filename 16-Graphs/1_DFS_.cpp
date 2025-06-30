// A graph is a set of vertices which may or may-not be connected to each other, (Vertices are just like people linked on FACEBOOK!!! , The people are vertices, and the linkage between people is "edges" here  .. ...  2  people may be linked, or may not be linked, they might also have a common friend....)

// So for "n" people in facebook, they can be friends in (n-C-2) ways (just like no. of possible handshakes in n-C-2), similarly total no. of ways in which "n" vertices can be connected is "n-C-2",  so! , in worst case complexity scenario... for "n" vertices there could be "n-C-2" edges!, so when time complexity depends directly on edges... then "worst case time complexity" is of the order of "O(n-C-2) ...which is same as  O(n^2) " .... however in best case scenario.... for "n" vertices.. there are "n-1" edges,( check/count yourself!) ,, so best case complexity would be  " O(n) "

// Now, there are 2 "good" methods for implementing a graph... they are called "Adjacency Matrix  & Adjacency List", here we are going to implement "Adjacency Matrix"


// Here, we are going to implement "Graphs" using "2-D array" where "1" will be stored if 2-vertices have an edge,,, and "0" will be stored if "2" vertices don't have an edge...

// DFS: Depth First Search, here we go deep from starting value in one direction only we keep on going until there are is nothing left in that direction... Thereafter we take the other direction.


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


void print_DFS(int** arr, int n, int sv, int* visited)      // We call this Depth first search its a traversal method, where we go deep in one direction first and then we go along second different direction after all elements of first direction has been traversed.    (Here, "sv" is starting vertex... from where we want the program to start its)
{
    cout<< sv <<endl;
    visited[sv]= true;
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1)
        {
            if(visited[i]) continue;

            print_DFS(arr,n, i, visited);
        }
    }
}




int main(){

    // Creating 
    int n,e;
    cin>>n>>e;
    int ** arr= new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
    }
    

    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        arr[f][s] =1;
        arr[s][f] =1;
    }


    int * visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;
    }
    

    print_DFS(arr, n, 0, visited);


    // Delete all the memory (Normal dynamic-memory deletion which we have always done...)

    for (int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;

    delete [] visited;
    

    return 0;
}

