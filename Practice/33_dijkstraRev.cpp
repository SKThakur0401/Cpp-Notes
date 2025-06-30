#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int findMinVertex(int* distance, int n, bool *visited)
{
    int ans=-1;
    int minVer=-1;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && (ans== -1 || distance[i] < ans))
        {
            ans= distance[i];
            minVer=i;
        }
    }
    return minVer;
}


void dijkstra(int** arr, int n)
{
    int* distance= new int[n];
    bool* visited= new bool[n];

    for (int i = 0; i < n; i++)
    {
        distance[i]= INT_MAX;
        visited[i]= false;
    }

    distance[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        int curr= findMinVertex(distance, n, visited);
        if(curr== -1) break;
        visited[curr]= true;
        for (int j = 0; j < n; j++)
        {
            if(arr[curr][j] != 0 && !visited[j])
            {
                int dist= arr[curr][j]+ distance[curr];

                if(dist < distance[j]) distance[j]= dist;
            }
        }
    }
    
    cout <<endl;
    cout <<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<i <<"  "<<distance[i] <<endl;
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


