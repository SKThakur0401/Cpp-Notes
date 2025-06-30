// Given a graph, return a "vector<vector<int> >" storing all the connected components in separate vectors,,, 

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void DFS(int** arr, int n, int sv, int* visited, vector<int> &vi)   // Puts all the elements which are connected to "sv( starting vertex )" in the vector "vi", also marks them as visited (true):)
{
    visited[sv]= true;
    vi.push_back(sv);
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]== 1 && !visited[i])
        {
            DFS(arr, n, i, visited, vi);
        }
    }
}



vector<vector<int> > connectedComponents(int** arr, int n)
{
    vector<vector<int> > ans;

    int* visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }

    for (int i = 0; i < n; i++)
    {
        if(visited[i]== false)
        {
            vector<int> vi;
            DFS(arr, n, i, visited, vi);
            ans.push_back(vi);
        }
    }

    return ans;
}

int main(){

    int n; cin>>n;
    int e; cin>>e;
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
    
    vector<vector<int> > ans;

    ans= connectedComponents(arr,n);

    cout <<endl;
    cout <<endl;

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<< ans[i][j] <<" ";
        }
        cout <<endl;
    }
    

    return 0;
}


