#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void print_DFS(int** arr, int n, int sv, int* visited)
{
    cout<< sv <<" ";
    visited[sv]=1;
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i] != 0 && visited[i] == 0)
        {
            print_DFS(arr, n, i, visited);
        }
    }
    
}

void dfs(int** arr, int n)
{
    int* visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;
    }

    for (int i = 0; i < n; i++)
    {
        if(visited[i]==0)
        {
            print_DFS(arr, n, i, visited);
            cout<<"    ";
        }
    }
    
    
}

void print_BFS(int** arr, int n, int sv, int* visited2)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited2[sv]=1;
    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();

        cout<< front <<" ";
        pendingNodes.pop();

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i] != 0 && !visited2[i])
            {
                pendingNodes.push(i);
                visited2[i]=1;
            }
        }
        
    }

}


bool hasPath_DFS(int** arr, int n, int sv, int ev, int * visited)
{
    if(sv==ev) return true;

    if(arr[sv][ev] != 0) return true;
    visited[sv]= 1;

    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i] !=0 && !visited[i])
        {
            bool b= hasPath_DFS(arr,n, i, ev, visited);

            if(b) return b;
        }
    }

    return false;
    
}

bool hasPath_BFS(int** arr, int n, int sv, int ev, int* visited2)
{
    if(sv== ev || arr[sv][ev]!=0) return true;

    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited2[sv]=1;

    while (!pendingVertices.empty())
    {
        int front= pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]!=0 && !visited2[i])
            {
                if(i== ev) return true;

                pendingVertices.push(i);
                visited2[i]=1;
            }
        }
    }

    return false;
}

int main(){
    int n,e;
    cin>>n>>e;

    int** arr= new int*[n];

    for (int i = 0; i < n; i++)
    {
        arr[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
    }

    for (int i = 0; i < e; i++){
        int f,s;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;
    }

    int * visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;
    }
    int * visited2= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited2[i]=0;
    }
    
    
    // print_DFS(arr,n, 0, visited);

    // cout <<endl;
    
    // dfs(arr,n);

    // cout <<endl;

    // print_BFS(arr,n,0, visited2);

    cout<< hasPath_BFS(arr,n, 0,5, visited) <<endl;
    cout<< hasPath_DFS(arr,n, 0,5, visited2) <<endl;


    return 0;
}

