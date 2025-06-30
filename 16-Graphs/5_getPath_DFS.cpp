#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


vector<int> getPath_DFS(int** arr, int n, int v1, int v2, bool* visited, vector<int> ans)
{
    ans.push_back(v1);

    if(v1== v2)
    {
        return ans;
    }
    visited[v1]=true;

    for (int i = 0; i < n; i++)
    {
        if(arr[v1][i]==1 && !visited[i])
        {
            vector<int> vi = getPath_DFS(arr,n, i, v2, visited, ans);
            if(!vi.empty())  return vi;
        }
    }
    vector<int> vi;
    return vi;
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
    

    ans= getPath_DFS(arr, n, v1, v2, visited, ans);

    
    cout <<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] <<" ";
    }
    

    // cout<<hasPath_BFS(arr, n, v1, v2, visited)<<endl;

    return 0;
}

