#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool hasPath_DFS(int** arr, int n, int v1, int v2, bool* visited)
{
    if(arr[v1][v2]) return true;
    
    visited[v1]= true;
    for (int i = 0; i < n; i++)
    {
        if(arr[v1][i]== 1 && !visited[i]) 
        {
            bool ans= hasPath_DFS(arr,n, i, v2, visited);

            if(ans) return true;
        }
    }

    return false;
}

bool hasPath_BFS(int** arr, int n, int v1, int v2, bool* visited)
{
    if(arr[v1][v2]==1) return true;
    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1]= true;

    while (!pendingVertices.empty())
    {
        int front= pendingVertices.front();
        pendingVertices.pop();
        if(visited[front]) continue;
        visited[front]= true;
        if(arr[front][v2]==1) return true;
        
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1)
            {
                pendingVertices.push(i);
            }
        }
    }
    return false;
}


int main(){

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

    int v1, v2;
    cin>>v1>>v2;

    bool* visited= new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    

    // cout<<hasPath_DFS(arr, n, v1, v2, visited)<<endl;
    cout<<hasPath_BFS(arr, n, v1, v2, visited)<<endl;

    return 0;
}

// 7 5
// 0 3
// 0 2
// 2 3
// 1 4
// 5 6
