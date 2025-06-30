#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int biggestPiece(int** arr,  int n, int i, int j, int ** visited)
{
    visited[i][j]= 1;
    int a1=0;
    int a2=0;
    int a3=0;
    int a4=0;


    if(i+1 <n && arr[i+1][j]==1 && visited[i+1][j]==0)
    {
        a1= biggestPiece(arr, n, i+1, j, visited);
    }

    if(j+1 <n && arr[i][j+1]==1 && visited[i][j+1]==0)
    {
        a2= biggestPiece(arr, n, i, j+1, visited);
    }    

    if(i-1 >=0   && arr[i-1][j]==1 && visited[i-1][j]==0)
    {
        a3= biggestPiece(arr, n, i-1, j, visited);
    }    
    if(j-1 >=0 && arr[i][j-1]==1 && visited[i][j-1]==0)
    {
        a4= biggestPiece(arr, n, i, j-1, visited);
    }

    // return 1 + max(max(a1,a2) , max(a3,a4));
    return 1 + a1+a2+a3+a4 ;        // ' 1+ '  bcoz the index "i-j" itself has a "1" , so it should also be present in the final sum...
}



int biggie(int** arr, int n)
{
    int ma=INT_MIN;

    int** visited= new int*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j]= 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]==1 && visited[i][j]==0)
            {
                int ans= biggestPiece(arr, n, i, j, visited);
                if(ans>ma) ma= ans;
            }
        }
    }
    
    return ma;
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
    
    cout<< biggie(arr,n) <<endl;
    

    return 0;
}

