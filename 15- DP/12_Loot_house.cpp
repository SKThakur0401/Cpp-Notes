#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int LootHouse(int arr[],int n)
{
    if(n<0) return 0;
    if(n==0) return 0;

    int l1 = arr[0] + LootHouse(arr+2, n-2);
    int l2 = LootHouse(arr+1, n-1);

    return max(l1,l2);
}


int MEMO_solution(int arr[],int n, int *memo)
{
    if(n<0) return 0;
    if(n==0) return memo[n] = 0;

    if(memo[n] != -1) return memo[n];

    int l1 = arr[0] + MEMO_solution(arr+2, n-2, memo);
    int l2 = MEMO_solution(arr+1, n-1, memo);

    return memo[n] = max(l1,l2);
}

int MEMO_LootHouse(int arr[], int n)
{
    int * memo= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        memo[i]=-1;
    }
    return MEMO_solution(arr, n, memo);
}


int DP_LootHouse(int arr[], int n)
{
    int * memo= new int[n+1];

    memo[0] =0;
    memo[1] =arr[0];

    for (int i = 2; i <= n; i++)
    {
        memo[i]= max(memo[i-1] , arr[i-1] + memo[i-2]);
    }
    return memo[n];
}

int main(){


    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<< LootHouse(arr,n) <<endl;
    cout<< MEMO_LootHouse(arr,n) <<endl;
    cout<< DP_LootHouse(arr,n) <<endl;
    

    return 0;
}

