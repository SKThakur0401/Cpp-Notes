// Chapter Assignment
// Problem Statement: Ways To Make Coin Change
// Problem Level: MEDIUM
// Problem Description:
// For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
// Return 0 if the change isn't possible.
// Input Format
// The first line of the input contains an integer value N, which denotes the total number of denominations.

// The second line of input contains N values, separated by a single space. These values denote the value of denomination.

// The third line of the input contains an integer value, that denotes the value of V.

// Output Format
// Print the total total number of ways i.e. W.

// Constraints :
// 1 <= n <= 10
// 1 <= V <= 1000

// Time Limit: 1sec

// Sample Input 1 :
// 3
// 1 2 3
// 4

// Sample Output 1 :
// 4

// Explanation to Sample Input 1 :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

// Sample Input 2 :
// 6
// 1 2 3 4 5 6
// 250

// Sample Output 2 :
// 13868903


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int coinChange(int* arr, int n, int sum, int starterIndex=0)
{
    if(sum<0) return 0;
    if(sum==0) return 1;

    int ans=0;

    for (int i = starterIndex; i < n; i++)
    {

        ans+= coinChange(arr, n, sum- arr[i], i);
    }
    return ans;
}


int MEMO_solution(int* arr, int n, int sum, int starterIndex, unordered_map<string,int> &um)
{
    if(sum<0) return 0;
    if(sum==0) return 1;

    string key= to_string(starterIndex) + "-" + to_string(sum);
    if(um.count(key)) return um[key];

    int ans=0;

    for (int i = starterIndex; i < n; i++)
    {

        ans+= MEMO_solution(arr, n, sum- arr[i], i, um);
    }
    return um[key] = ans;
}


int MEMO_coinChange(int* arr, int n, int sum, int starterIndex=0)
{
    unordered_map<string, int> um;

    return MEMO_solution(arr, n, sum, 0 , um);
}



int main(){

    int n; cin>>n;
    int *arr= new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int sum; cin>>sum;

    cout<< coinChange(arr, n, sum) <<endl;
    // cout<< MEMO_coinChange(arr, n, sum) <<endl;

    return 0;
}

