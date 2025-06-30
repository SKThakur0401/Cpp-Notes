// Very easy question, return true if the entire graph is connected, else false,

// Soln... just create a isConnected function, which calls "markVisited" function, which will have a "starting vertex", that could be "any number from the list of vertices, if that vertex is connected to all other vertices, then it will paint them all as true, else ... some vertices which are left unconnected will still remain false... then check if any vertex is false or not, if any vertex is false, then return false, else true"

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;





void markVisited(int** arr, int n, int sv, int* visited)
{
    visited[sv]=true;

    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1 && !visited[i])
        {
            markVisited(arr, n, i, visited);
        }
    }
    
}

bool isConnected(int **arr, int n)
{
    int* visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }

    markVisited(arr,n, 0, visited);

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) return false;
    }
    
    return true;
}


int main(){

    int n; cin>>n;
    int e; cin>>e;
    int** arr= new int*[n];
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

        arr[f][s]=1;
        arr[s][f]=1;
    }
    
    cout<< isConnected(arr,n) <<endl;

    return 0;
}



