#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void oneChain(int** arr, int n, int sv, int* visited, vector<int> &ans)
{
    visited[sv]= 1;
    ans.push_back(sv);
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i]==1 && visited[i]==0)
        {
            oneChain(arr, n, i, visited, ans);
        }
    }
}


vector<vector<int> > connectedComponents(int** arr, int n, int* visited)
{
    vector<vector<int> > ans;
    for (int i = 0; i < n; i++)
    {
        if(visited[i]==0)
        {
            vector<int> vi;
            oneChain(arr, n, i, visited, vi);
            ans.push_back(vi);
        }
    }
    return ans;
}

int main(){

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

    int* visited= new int[n];
    
    for (int i = 0; i < n; i++){    visited[i]=0;   }
    
    cout <<endl;
    cout <<endl;
    
    
    vector<vector<int> > ans= connectedComponents(arr,n, visited);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout <<endl;
    }
    
    

    return 0;
}

// 12 12
// 2 3
// 3 4
// 4 5
// 5 2
// 0 1
// 1 6
// 6 0
// 7 8
// 8 9
// 9 7
// 10 11
// 9 11