#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;

// To store the path, we r going to use a very interesting way, try it yourself, should be able to do it


vector<int> getPath_BFS(int** arr, int n, int v1, int v2, bool* visited, vector<int> ans)
{
    queue<int> pendingVertices;
    pendingVertices.push(v1);

    unordered_map<int,int> um;
    visited[v1]= true;

    while (!pendingVertices.empty())
    {
        int front= pendingVertices.front();
        pendingVertices.pop();

        if(front== v2) break;

        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1 && !visited[i])
            {
                visited[i]= true;
                um[i]= front;
                pendingVertices.push(i);
            }
        }
    }

    ans.push_back(v2);
    int fk= v2;

    if(um.count(fk)==0)
    {
        vector<int> nothing;
        return nothing;
    }

    while(um[fk] != v1)
    {
        ans.push_back(um[fk]);
        fk= um[fk];
    }
    ans.push_back(v1);
    return ans;
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

    vector <int> ans;
    

    ans= getPath_BFS(arr, n, v1, v2, visited, ans);

    
    cout <<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] <<" ";
    }

    return 0;
}



// 8 8
// 3 1
// 3 4
// 1 2
// 1 0
// 4 5
// 4 6
// 5 7
// 6 7

