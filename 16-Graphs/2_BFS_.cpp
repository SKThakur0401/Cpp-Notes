#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void print_BFS(int ** arr, int n, int sv, int * visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);

    while(!pendingNodes.empty())
    {   
        int front= pendingNodes.front();
        pendingNodes.pop();
        if(visited[front]) continue;
        cout<< front <<endl;
        visited[front]= true;
        for (int i = 0; i < n; i++)
        {
            if(arr[front][i]==1)
            {
                if(visited[i]) continue;

                pendingNodes.push(i);
            }
        }
    }
    
}


int main()
{
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
        arr[s][f] =1;
    }

    int* visited= new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=0;
    }

    print_BFS(arr, n, 0, visited);

    return 0;
}

// 7 7
// 0 1
// 0 2
// 1 5
// 5 4
// 4 3
// 3 2
// 2 6



// 7 8
// 0 1
// 0 2
// 1 3
// 1 4
// 2 6
// 3 5
// 4 5
// 6 5

