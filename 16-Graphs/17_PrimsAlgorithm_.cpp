#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


void Prim(int** arr, int n, int e)
{
    int*visited= new int[n];
    int* weight= new int[n];
    int* parent= new int[n];

    parent[0]= -1;
    weight[0]= INT_MAX;
    visited[0]= 0;


    for (int i = 1; i < n; i++)
    {
        visited[i]=0;
        weight[i]= INT_MAX;
    }

    int i = -1;
    for (int x = 0; x < n; x++)
    {
        if(i== -1) i=x;
        visited[i]=1;
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] != 0 && visited[j]==0)
            {
                if(arr[i][j] < weight[j])
                {
                    weight[j]= arr[i][j];
                    parent[j]= i;
                }
            }
        }

        int mini= INT_MAX;

        for (int ap = 0; ap < n; ap++)
        {
            if(visited[ap]==0)
            {
                if(weight[ap] < mini)
                {
                    mini= weight[ap];
                    i=ap;
                }
            }
        }
        if(mini== INT_MAX) i++;
    }
    
    for (int x = 1; x < n; x++)
    {
        cout<< parent[x]<<" "<<x<<" "<<weight[x] <<endl;
    }

}


int main(){

    int n; cin>>n;
    int e; cin>>e;
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
        int f,s, weight;
        cin>>f>>s>> weight;

        arr[f][s]= weight;
        arr[s][f]= weight;
    }

    cout <<endl;
    cout <<endl;

    Prim(arr, n, e);


    return 0;
}

// 5 7
// 0 1 4
// 1 2 2
// 2 3 3
// 3 4 6
// 0 2 8
// 2 4 9
// 1 3 6
