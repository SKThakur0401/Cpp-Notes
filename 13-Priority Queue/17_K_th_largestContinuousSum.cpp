// QUESTION:
// K-th Largest Sum Contiguous Subarray
// Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.


// EXAMPLE -
// Input: a[] = {20, -5, -1} 
//          k = 3
// Output: 14
// Explanation: All sum of contiguous 
// subarrays are (20, 15, 14, -5, -6, -1) 
// so the 3rd largest sum is 14.
 
// Input: a[] = {10, -10, 20, -40} 
//          k = 6
// Output: -10 
// Explanation: The 6th largest sum among 
// sum of all contiguous subarrays is -10.

// THINK OF THE OPTIMAL CODE... (IT'S A QUESTION FROM DSA-CRACK-SHEET)

#include<iostream>
#include<queue>
using namespace std;


int main(){


    int n; cin>>n; int k; cin>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int sum[n+1];
    sum[0]=0;
    for (int i = 1; i < n+1; i++)
    {
        sum[i]= sum[i-1]+arr[i-1];
    }

    priority_queue<int, vector<int> , greater<int> > pq;



    for (int i = n; i >=1; i--)
    {
        pq.push(sum[i]);
        if(pq.size() == k+1) pq.pop();

        for (int j = 0; j < i; j++)
        {
            int diff= sum[i] - sum[j];
            pq.push(diff);
            if(pq.size() == k+1) pq.pop();
        }
    }

    cout<< pq.top() <<endl;

    return 0;
}

// 4 6
// 10 -10 20 -40