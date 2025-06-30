#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<unordered_map>
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

vector<int> getPath_DFS(int** arr, int n, int sv, int ev, int* visited, vector<int> &ans)
{
    if(sv==ev) return ans;
    ans.push_back(sv);

    if(arr[sv][ev] !=0)
    {
        ans.push_back(ev);
        return ans;
    }
    visited[sv]= 1;

    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1 && !visited[i])
        {
            ans= getPath_DFS(arr,n, i, ev, visited, ans);

            if(ans.size() !=0) return ans;
        }
    }
    
    vector<int> nothing;
    return nothing;
}



vector<int> getPath_BFS(int** arr, int n, int sv, int ev, int* visited)
{
    vector<int> ans;
    if(arr[sv][ev] !=0)
    {
        ans.push_back(sv);
        ans.push_back(ev);
        return ans;
    }
    unordered_map<int,int> um;
    visited[sv]=1;

    queue<int> pendingNodes;
    pendingNodes.push(sv);
    int i;
    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();

        for (i = 0; i < n; i++)
        {
            if(arr[front][i] !=0 && visited[i]== 0)
            {
                pendingNodes.push(i);
                visited[i]=1;
                um[i]= front;
                // if(i== ev) break;
            }
        }
    }

    if(i != ev) return ans;

    while(um[i] != sv)
    {
        ans.push_back(i);

        i= um[i];
    }
    ans.push_back(sv);

    return ans;
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

    int* visited= new int[n];
    for (int j = 0; j < n; j++)
    {
        visited[j]=0;
    }

    vector<int> ans;
    int sv=0;
    int ev=3;

    ans= getPath_BFS(arr, n, sv, ev, visited);

    if(ans.empty()) cout<< "No path" <<endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i]<< " ";
    }
    cout <<endl;
    
    return 0;
}

// 7 6
// 0 1
// 1 2
// 2 0
// 1 3
// 2 4
// 5 6