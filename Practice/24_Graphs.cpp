#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void dfs(int** arr, int n, int sv, int* visited)
{
    cout<< sv <<endl;
    visited[sv]=1;

    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1 && !visited[i])
        {
            dfs(arr, n, i, visited);
        }
    }
}

void bfs(int** arr, int n, int sv, int* visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);

    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();
        if(!visited[front]) continue;
        cout<< front <<endl;
        visited[front]= 1;
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1 && !visited[i])
            {
                pendingNodes.push(i);
            }
        }
    }
}

bool hasPath(int** arr, int n, int v1, int v2, int* visited)
{
    if(arr[v1][v2] == 1) return true;
    visited[v1]=1;

    for(int i=0; i<n; i++)
    {
        if(arr[v1][i] == 1 && visited[i] == 0)
        {
            bool ans= hasPath(arr, n, i, v2, visited);

            if(ans) return ans;
        }
    }
    return false;
}

vector<int> getPath_DFS(int** arr, int n, int v1, int v2, int* visited)
{
    vector<int> vi;
    if(arr[v1][v2])
    {
        vi.push_back(v2);
        vi.push_back(v1);
        return vi;
    }
    visited[v1]=1;

    for (int i = 0; i < n; i++)
    {
        if(arr[v1][i] && !visited[i])
        {
            vector<int> ans= getPath(arr, n, i, v2, visited);
            // visited[i] = 1;
            if(ans.size() >0 )
            {
                ans.push_back(v1);
                return ans;
            }
        }
    }
    return vi;
    
}

vector<int> getPath_BFS(int** arr, int n, int v1, int v2, int* visited)
{
    vector<int> vi;
    queue<int> pendingNodes;
    pendingNodes.push(v1);
    vi.push_back(v1);

    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i] && !visited[i])
            {
                // if(i== v2)
                pendingNodes.push(i);
            }
        }
    }
}

int main(){

    int n; cin>>n;
    int e; cin>>e;
    int** arr= new int*[n];
    int *visited= new int[n];

    for(int i=0; i<n; i++)
    {
        arr[i]= new int[n];
        visited[i]=0;
        for(int j=0; j<n; j++)
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


    cout <<endl;
    
    // dfs(arr,n, 0, visited);
    // bfs(arr,n, 0, visited);
    // cout<< hasPath(arr,n,4, 1, visited) <<endl;
    // vector<int> vi= getPath_DFS(arr,n, 0, 5, visited);
    vector<int> vi= getPath_BFS(arr,n, 0, 5, visited);

    for (int i = 0; i < vi.size(); i++)
    {
        cout<< vi[i] <<endl;
    }
    

    return 0;
}

