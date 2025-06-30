#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void dfs(int** arr, int n, bool* visited, int si)
{
    cout<< si <<endl;
    visited[si]=true;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[si][i] != 0 && !visited[i])
        {
            dfs(arr, n, visited, i);
        }
    }
    
}


void bfs(int** arr, int n, bool* visited, int si)
{
    queue<int> pendingNodes;
    pendingNodes.push(si);
    visited[si]=true;

    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();
        cout<< front <<"  ";
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i] != 0 && !visited[i])
            {
                pendingNodes.push(i);
                visited[i]=true;
            }
        }
        
    }
    cout <<endl;
}


void printDFS(int** arr, int n, bool* visited)
{

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) bfs(arr, n, visited, i);
    }
    
}

int findMinVertex(int* distance, int n, bool* visited)
{
    int minDistance=-1;
    int minVertex=-1;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && (minDistance == -1 || distance[i] < minDistance))
        {
            minDistance=distance[i];
            minVertex= i;
        }
    }
    return minVertex;
}


void dijkstra(int** arr, int n)
{
    int* distance= new int[n];
    bool* visited=new bool[n];

    for (int i = 0; i < n; i++)
    {
        distance[i]= INT_MAX;
        visited[i]= false;
    }
    distance[0]=0;

    for (int i = 0; i < n-1; i++)
    {
        int curr= findMinVertex(distance, n, visited);
        
        if(curr== -1) break;
        visited[curr]= true;

        for (int j = 0; j < n; j++)
        {
            if(arr[curr][j] != 0 && !visited[j])
            {
                int dist= distance[curr] + arr[curr][j];
                if(dist < distance[j]) distance[j]= dist;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<< i<<"   "<<distance[i] <<endl;
    }
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
    
    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;
    }
    
    // bool* visited=new bool[n];

    // for (int i = 0; i < n; i++)
    // {
    //     visited[i]=false;
    // }

    cout <<endl;
    cout <<endl;
    // printDFS(arr, n, visited);

    dijkstra(arr, n);

    return 0;
}



