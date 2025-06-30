#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int findMinVertex(int* distance, int n, bool *visited)
{
    int minVertex=-1;
    int minValue= INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && distance[i] < minValue)
        {
            minValue= distance[i];
            minVertex=i;
        }
    }
    return minVertex;
}

void dijkstra(int** arr, int n)
{
    int* parent= new int[n];
    bool* visited=new bool[n];
    int* distance=new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;

    for (int i = 0; i < n-1; i++)
    {
        int curr= findMinVertex(distance, n, visited);
        if(curr== -1) break;
        visited[curr]=true;

        for (int j = 0; j < n; j++)
        {
            if(arr[curr][j] != 0 && !visited[j])
            {
                if(arr[curr][j]+ distance[curr] < distance[j])
                {
                    distance[j]= arr[curr][j]+ distance[curr];
                    parent[j]=curr;
                }
            }
        }
    }

    cout <<endl;
    cout <<endl;

    for (int i = 0; i < n; i++)
    {
        cout<< i<<"  "<< distance[i] <<endl;
    }
    
}

int main(){


    int n,e;
    cin>>n>>e;
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
        int f,s,w;
        cin>>f>>s>>w;
        arr[f][s]=w;
        arr[s][f]=w;
    }
    

    cout <<endl;
    cout <<endl;
    dijkstra(arr, n);
    

    return 0;
}

// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8

// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5
