#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


void dijkstra(int** arr, int n)
{
    int* parent= new int[n];
    int* weight= new int[n];
    int* visited= new int[n];
    parent[0]= -1;
    weight[0]=0;
    visited[0]=0;

    for (int i = 1; i < n; i++)
    {
        weight[i]= INT_MAX;
        visited[i]=0;
    }

    int curr=0;
    for (int x = 0; x < n; x++)
    {
        visited[curr]=1;
        for (int i = 0; i < n; i++)
        {
            if(arr[curr][i] != 0 && visited[i]==0)
            {
                if(weight[curr]+ arr[curr][i] < weight[i])
                {
                    weight[i]= weight[curr]+ arr[curr][i];
                    parent[i]= curr;
                }
            }
        }
        int i;
        int mini= INT_MAX;
        for (i = 0; i < n; i++)
        {
            if(visited[i]==0 && weight[i] < mini)
            {
                mini= weight[i];
                curr=i;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
    }
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
        int f, s, weight; cin>>f>>s>>weight;
        arr[f][s] = weight;
        arr[s][f] = weight;
    }
    cout <<endl;
    cout <<endl;
    dijkstra(arr, n);

    return 0;
}
// 5 7
// 0 1 4
// 1 2 2
// 0 2 8
// 1 3 5
// 3 2 5
// 3 4 4
// 4 2 9