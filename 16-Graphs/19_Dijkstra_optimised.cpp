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

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > history;

    for (int i = 1; i < n; i++)
    {
        weight[i]= INT_MAX;
        visited[i]=0;
    }

    pair<int,int> pi(0,0);
    history.push(pi);

    int curr=0;
    for (int x = 0; x < n+1; x++)   // When this loop runs n+1 times, it gives correct ans, but for "n" times, it takes the wrong route / longer route for the last step of the MST...
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

                    pair<int, int> pi(weight[i] , i);
                    history.push(pi);
                }
            }
        }
        curr= history.top().second;
        history.pop();
        

        // int mini= INT_MAX;
        // for (int i = 0; i < n; i++)
        // {
        //     if(visited[i]==0 && weight[i] < mini)
        //     {
        //         mini= weight[i];
        //         curr=i;
        //     }
        // }
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

