#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


void print_DFS(int** arr, int n, int sv, int* visited)
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

void print_BFS(int** arr, int n, int sv, int* visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);

    while(!pendingNodes.empty())
    {   
        int front= pendingNodes.front();
        pendingNodes.pop();
        if(visited[front]) continue;
        cout<< front <<endl;
        visited[front]= true;
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1)
            {
                if(visited[i]) continue;

                pendingNodes.push(i);
            }
        }
    }
}


void DFS(int** arr, int n)
{
    int * visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(! visited[i]) print_DFS(arr, n, i, visited);
    }  
}


void BFS(int** arr, int n)
{
    int * visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(! visited[i]) print_BFS(arr, n, i, visited);
    }  
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

    DFS(arr,n);
    BFS(arr,n);

    return 0;
}

