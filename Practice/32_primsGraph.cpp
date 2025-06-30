#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int findMinVertex(int* weight, bool* visited, int n)
{
    int minVertex= -1;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && (minVertex== -1 || weight[i] < edge[minVertex][i]))
        {
            
        }
    }
    
}

void prims(int** edge, int n)
{
    int* weight= new int[n];
    int* parent= new int[n];
    bool* visited= new bool[n];

    for (int i = 0; i < n; i++)
    {
        weight[i]= INT_MAX;
        visited[i]= 0;
    }

    parent[0]= -1;
    weight[0]= 0;
    
    for (int i = 0; i < n; i++)
    {
        int minVertex= findMinVertex(weight, visited, n);

        for (int j = 0; j < n; j++)
        {
            /* code */
        }
        
    }
    
}

int main(){

    int n,e;
    cin>>n>>e;
    int** edge= new int*[n];
    for (int i = 0; i < n; i++)
    {
        edge[i]= new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < e; i++)
    {
        int f,s, w;
        cin>>f>>s>>w;
        edge[f][s]= w;
        edge[s][f]= w;
    }

    prims(edge, n);
    

    return 0;
}

