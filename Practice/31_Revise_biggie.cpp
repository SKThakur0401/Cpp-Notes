#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int biggestPiece(int** arr, int n, int i, int j, bool** visited)
{
    int bigAns=1;
    visited[i][j]=1;

    if(i+1 <n && !visited[i+1][j] && arr[i+1][j] == 1)
    {
        bigAns+= biggestPiece(arr, n, i+1, j, visited);
    }

    if(j+1 <n && !visited[i][j+1] && arr[i][j+1] == 1)
    {
        bigAns+= biggestPiece(arr, n, i, j+1, visited);
    }

    if(i-1 >=0 && !visited[i-1][j] && arr[i-1][j] == 1)
    {
        bigAns+= biggestPiece(arr, n, i-1, j, visited);
    }

    if(j-1 >=0 && !visited[i][j-1] && arr[i][j-1] == 1)
    {
        bigAns+= biggestPiece(arr, n, i, j-1, visited);
    }
    
    return bigAns;
}


int biggie(int** arr, int n)
{
    bool** visited= new bool*[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = new bool[n];
        for(int j=0; j<n; j++)
        {
            visited[i][j]=false;
        }
    }

    int ans=0;

    for(int i=0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]==1 && !visited[i][j])
            {
                ans = max(ans, biggestPiece(arr, n, i, j, visited));
            }
        }
        
    }

    return ans;
}


int main(){

    int n; cin>>n;

    int** arr= new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout <<endl;
    cout <<endl;
    
    cout<<"The Size of biggest piece is : " <<biggie(arr,n) <<endl;
    

    return 0;
}

