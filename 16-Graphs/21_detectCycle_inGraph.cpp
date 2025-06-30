#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


bool detectCycle_DFS(int** arr, int n, int sv, int* visited, int* over)
{
    visited[sv]= 1;
    over[sv]=1;
    for (int i = 0; i < n; i++)
    {
        if(arr[sv][i] != 0)
        {
            // if(visited[i]==1 && i != sv)
            // {
            //     if(over[i]==1) return true;
            // }
            if(visited[i]==0)
            {
                bool b= detectCycle_DFS(arr, n, i, visited, over);
                if(b) return b;
            }
            else if(over[i]==1) return true;

        }
    }

    over[sv]=0;
    return false;
}


int main(){

    // Creating 
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
        // arr[s][f] =1;
    }


    int * visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;
    }


    int * over= new int[n];
    for (int i = 0; i < n; i++)
    {
        over[i]=0;
    }
    
    cout<< detectCycle_DFS(arr, n, 0, visited, over)<<endl;



    for (int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;

    delete [] visited;
    

    return 0;
}
// 4 4
// 1 2
// 2 3
// 3 4
// 1 4


