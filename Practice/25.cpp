#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


void print_DFS(int** arr, int sv, bool* visited, int n)
{
    cout<< sv <<"  ";
    visited[sv]=true;
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1 && !visited[i])
        {
            print_DFS(arr, i, visited, n);
        }
    }
    
}

void DFS(int** arr, int n)
{
    bool* visited= new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) print_DFS(arr, i, visited, n);
    }
    
}

void print_BFS(int** arr, int sv, bool* visited, int n)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);

    while(!pendingNodes.empty())
    {
        int front= pendingNodes.front();
        pendingNodes.pop();

        if(visited[front]) continue;
        cout<< front <<" ";
        visited[front]= true;

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i] == 1 && !visited[i])
            {
                pendingNodes.push(i);
            }
        }
    }
}

void BFS(int** arr, int n)
{
    bool* visited= new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) print_BFS(arr, i, visited, n);
    }
}

vector<int> getPath(int** arr, int n, bool* visited, int v1, int v2)
{
    vector<int> ans;
    // visited[v1]= true;

    if(arr[v1][v2]== 1)
    {
        ans.push_back(v2);
        ans.push_back(v1);
        return ans;
    }

    visited[v1]= true;

    for (int i = 0; i < n; i++)
    {
        if (arr[v1][i] == 1 && !visited[i])
        {
            vector<int> vi = getPath(arr, n, visited, i, v2);
            if(vi.size() > 0)
            {
                vi.push_back(v1);
                return vi;
            }
        }
    }

    return ans;
}

vector<int> getPath_BFS(int** arr, int n, bool* visited, int v1, int v2)
{
    unordered_map<int,int> um;
    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1]= true;
    
    while (!pendingVertices.empty())
    {
        // if(front== v2) break;
        int front= pendingVertices.front();
        pendingVertices.pop();
        if(front== v2) break;
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i] && !visited[i])
            {
                // if(i== v2) break;
                um[i]= front;
                // if(i== v2) break;
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }

    if(um.count(v2)==0)
    {
        vector<int> nothing; return nothing;
    }

    vector<int> vi;
    int fk=v2;
    while(fk != v1)
    {
        vi.push_back(fk);
        fk= um[fk];
    }

    vi.push_back(v1);
    return vi;
}

int main(){

    cout<< "DOO : " <<endl;
    int n,e; cin>>n>>e;

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

    bool* visited= new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    
    // int sv=0;

    // DFS(arr, n);
    int v1, v2;
    cin>>v1>>v2;

    vector<int> vi= getPath(arr, n, visited, v1, v2);

    cout <<endl;
    cout <<endl;

    for (int i = 0; i < vi.size(); i++)
    {
        cout<< vi[i] <<"  ";
    }

    return 0;
}


