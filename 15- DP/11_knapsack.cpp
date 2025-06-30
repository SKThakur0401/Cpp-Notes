#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int knapsack(int n, int W[], int V[], int cap)
{
    if(n==0 || cap==0) return 0;

    int w1= knapsack(n-1, W+1, V+1, cap);
    int w2= INT_MIN;
    if(cap-W[0] >=0) w2= knapsack(n-1, W+1, V+1, cap -W[0]) + V[0];

    return max(w1,w2);
}


int MEMO_solution(int n, int W[], int V[], int cap, int** arr)
{
    if(n==0 || cap==0) return arr[n][cap] = 0;

    if(arr[n][cap] != -1) return arr[n][cap];


    int w1= MEMO_solution(n-1, W+1, V+1, cap, arr);
    int w2= INT_MIN;
    if(cap-W[0] >=0) w2= MEMO_solution(n-1, W+1, V+1, cap -W[0], arr) + V[0];

    return arr[n][cap] = max(w1,w2);
}

int MEMO_knapsack(int n, int W[], int V[], int cap)
{
    int **arr = new int*[n+1];

    for (int i = 0; i < n+1; i++)
    {
        arr[i]= new int[cap+1];
    }

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < cap+1; j++)
        {
            arr[i][j] = -1;
        }
    }
    return MEMO_solution(n, W, V, cap, arr);
}


int DP_knapsack(int n, int W[], int V[], int cap)
{
    int **arr = new int*[n+1];

    for (int i = 0; i < n+1; i++)
    {
        arr[i]= new int[cap+1];
    }
    // Base case initialisation
    for (int i = 0; i < n+1; i++)
    {
        arr[i][0]=0;
    }

    for (int i = 1; i < n+1; i++)
    {
        arr[0][i]=0;
    }

    int j= cap;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {        
            if(W[i-1] <= j)
            {
                arr[i][j]= max(V[i-1] + arr[i-1][j- W[i-1]] , arr[i-1][j]);
            }

            else
            {
                arr[i][j]= arr[i-1][j];
            }
        }
    }
    return arr[n][cap];
}




int main(){


    int n; cin>>n;
    int W[n];
    for (int i = 0; i < n; i++)
    {
        cin>>W[i];
    }
    int V[n];
    for (int i = 0; i < n; i++)
    {
        cin>>V[i];
    }
    int cap; cin>>cap;

    cout<< MEMO_knapsack(n, W, V, cap) <<endl;
    cout<< DP_knapsack(n, W, V, cap) <<endl;
    cout<< knapsack(n, W, V, cap) <<endl;


    return 0;
}

// 10
// 39 92 32 92 74 82 88 47 12 53
// 382 9238 93 23 7894 9283 928 583 9123 398 

