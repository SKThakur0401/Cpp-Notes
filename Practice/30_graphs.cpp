#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;


void print_DFS(int** arr, int sv, int n, bool* visited)
{
    cout<< sv <<"  ";
    visited[sv]= true;

    for(int i=0; i<n; i++)
    {
        if(arr[sv][i]== 1)
        {
            if(visited[i]) continue;

            print_DFS(arr, i, n, visited);
        }
    }
}
void DFS(int** arr, int sv, int n, bool* visited)
{
    for(int i=0; i<n; i++)
    {
        if(!visited[i]) print_DFS(arr, i, n, visited);
    }
}
void print_BFS(int ** arr, int sv, int n, bool* visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv]= true;


    while(!pendingNodes.empty())
    {
        int front = pendingNodes.front();
        pendingNodes.pop();

        for(int i=0; i<n; i++)
        {
            if(arr[front][i]== 1)
            {
                if(visited[i]== false)
                {
                    pendingNodes.push(i);
                    visited[i] =true;
                }
            }
        }

        cout<< front <<"  ";
    }
}

bool hasPath(int** arr, int n, int si, int ei, bool* visited)
{
    if(arr[si][ei]== 1) return true;
    visited[si]= true;

    for(int i=0; i<n; i++)
    {
        if(arr[si][i] == 1 && !visited[i])
        {
            bool temp = hasPath(arr, n, i, ei, visited);

            if(temp) return true;
        }
    }
    return false;
}

vector<int> getPath_DFS(int** arr, int n, int si, int ei, bool* visited)
{
    vector<int> ans;
    if(si== ei)
    {
        ans.push_back(si);
        return ans;
    }
    visited[si]= true;

    for(int i=0; i<n; i++)
    {
        if(arr[si][i] == 1 && !visited[i])
        {
            ans= getPath_DFS(arr, n, i, ei, visited);

            if(ans.size() > 0)
            {
                ans.push_back(si);
                return ans;
            }
        }
    }

    vector<int> empty;
    return empty;
}

vector<int> getPath_BFS(int** arr, int n, int si, int ei, bool* visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(si);
    unordered_map<int,int> um;

    while(!pendingNodes.empty())
    {
        int front = pendingNodes.front();
        pendingNodes.pop();

        if(visited[front]) continue;
        visited[front]= 1;

        for(int i=0; i<n; i++)
        {
            if(arr[front][i]== 1 && !visited[i])
            {
                pendingNodes.push(i);
                
                um[i] = front;
                if(i== ei) break;
            }
        }
    }

    vector<int> ans;
    int fk= ei;
    ans.push_back(ei);

    while(um.count(fk))
    {
        fk= um[fk];
        ans.push_back(fk);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



int main(){

    int n,e;
    cin>>n>>e;

    int** arr= new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i]= new int[n];
        for(int j=0; j<n; j++)
        {
            arr[i][j]= 0;
        }
    }
    for(int i=0; i<e; i++)
    {
        int f,s;
        cin>>f>>s;
        arr[f][s]= 1;
        arr[s][f]= 1;
    }
    bool* visited= new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]= false;
    }
    cout <<endl;
    


    return 0;
}

