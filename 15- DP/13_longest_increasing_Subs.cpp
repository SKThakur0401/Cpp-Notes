// Here, "DP" is applied in an untraditional/ different way, unlike all our previous questions, but its important to know this kind of implementation!!

// Problem Statement: Longest Increasing Subsequence
// Problem Level: MEDIUM
// Problem Description:
// Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
// Input Format
// Line 1 : An integer N 
// Line 2 : Elements of arrays separated by spaces

// Output Format
// Line 1 : Length of longest subsequence

// Input Constraints
// 1 <= n <= 10^3

// Sample Input :
// 6
// 5 4 11 1 16 8

// Sample Output 1 :
// 3

// Sample Output Explanation
// Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

// Sample Input 2:
// 3
// 1 2 2

// Sample Output 2 :
// 2


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int LongestSub(int arr[], int n, int lastEntry= INT_MIN)        // Time complexity : O(2^n)
{
    if(n==0) return 0;
    int l2= INT_MIN;
    int l1 = LongestSub(arr+1, n-1, lastEntry);
    if(arr[0]> lastEntry) l2 = 1 + LongestSub(arr+1, n-1, arr[0]);

    return max(l1,l2);
}

int DP_LongestSub(int input[],int n)       // Time Comlexity : O(n*n), Space complexity : O(n) 
                                        // (in our previous quesionts,TC was O(N), for SC O(N)
{
    int * output= new int[n];
    output[0]=1;

    for (int i = 1; i < n; i++)
    {
        output[i]=1;
        for (int j = i-1; j >=0; j--)
        {
            if(input[j]>= input[i])
            {
                continue;
            }

            int possibleAns= output[j]+1;
            if(possibleAns> output[i])
            {
                output[i]= possibleAns;
            }
        }
    }
    int ans= 0;
    for (int i = 0; i < n; i++)
    {
        if(output[i]> ans)
        {
            ans=output[i];
        }
    }

    delete [] output;
    return ans;

}

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<< LongestSub(arr, n) <<endl;
    // cout<< MEMO_LongestSub(arr, n) <<endl;
    cout<< DP_LongestSub(arr, n) <<endl;

    return 0;
}



