#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int mcm(int* arr, int si, int ei)
{

    if(si==ei) return 0;
    if(ei - si == 1) return 0;

    int k=si+1;
    int mini= INT_MAX;
    while(k< ei)
    {
        int w1= mcm(arr, si,k) + mcm(arr,k,ei) + arr[si]*arr[k]*arr[ei];
        k++;
        if(w1 <mini) mini= w1;
    }


    return mini;
}


int MEMO_mcm(int* arr, int si, int ei, unordered_map<string,int> &um)   // Using unordered map ;), my personal approach, this has much better space complexity than the 2-D array(O(n*n) space eaten) approach
{
    if(si==ei) return 0;
    if(ei - si == 1) return 0;
    string key = to_string(si) + "-" + to_string(ei);
    if(um.count(key)) return um[key];
    int k=si+1;
    int mini= INT_MAX;
    while(k< ei)
    {
        int w1= MEMO_mcm(arr, si,k , um) + MEMO_mcm(arr,k,ei , um) + arr[si]*arr[k]*arr[ei];
        k++;
        if(w1 <mini) mini= w1;
    }

    return um[key] = mini;

}


int MEMO_solution(int* arr, int si, int ei, int** memo)
{
    if(si==ei) return memo[si][ei]=0;
    if(ei - si == 1) return memo[si][ei]=0;

    if(memo[si][ei] != -1)
    {
        return memo[si][ei];
    }

    int k=si+1;
    int mini= INT_MAX;
    while(k< ei)
    {
        int w1= MEMO_solution(arr, si,k, memo) + MEMO_solution(arr,k,ei, memo) + arr[si]*arr[k]*arr[ei];
        k++;
        if(w1 <mini) mini= w1;
    }


    return memo[si][ei]= mini;
}


int MEMO_mcm2(int* arr, int si, int ei)     // Memoisation using 2-D array
{
    int ** memo= new int*[ei+1];

    for (int i = 0; i < ei+1; i++)
    {
        memo[i]= new int[ei+1];
    }
    for (int i = 0; i < ei+1; i++)
    {
        for (int j = 0; j < ei+1; j++)
        {
            memo[i][j] = -1;
        }
    }
    
    return MEMO_solution(arr, si, ei, memo);
}


int main(){
    int n; cin>>n;
    int * arr= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        cin>>arr[i];
    }

    unordered_map<string, int> um;


    cout<< MEMO_mcm(arr, 0, n, um) <<endl; 
    cout<< MEMO_mcm2(arr, 0, n) <<endl; 
    cout<< mcm(arr, 0, n) <<endl;

    
    return 0;
}

// 10
// 3892 98 923 81 283 832 56 65 32 82 11