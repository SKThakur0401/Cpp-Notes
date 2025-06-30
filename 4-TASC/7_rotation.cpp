// QUESTION :
// Chapter Assignment
// Problem Statement: Rotate array
// Problem Level: EASY
// Problem Description:
// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
// Note:
// Change in the input array/list itself. You don't need to return or print the elements. 

// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains the value of 'D' by which the array/list needs to be rotated.

// Output Format :
// For each test case, print the rotated array/list in a row separated by a single space.

// Output for every test case will be printed in a separate line.

// Constraints :
// 1 <= t <= 10^4
// 0 <= N <= 10^6
// 0 <= D <= N
// Time Limit: 1 sec

// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7
// 2

// Sample Output 1:
// 3 4 5 6 7 1 2

// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7
// 0
// 4
// 1 2 3 4
// 2

// Sample Output 2:
// 1 2 3 4 5 6 7
// 3 4 1 2



// SOLUTION :

// METHOD -1 (OTHER 2 METHODS ARE DISCUSSED IN FOLLOWING FILES)
// TAKING THE FIRST ELEMENT OUT,(STORING IT IN A VARIABLE) AND THEN MOVING ALL THE ELEMENTS LEFT BY 1 UNIT..AND THEN PLACING THE FIRST ELEMENT IN THE LAST UNIT, WHICH IS VACANT NOW....REPEATING THIS PROCESS "D" TIMES FOR "D" ROTATIONS.



#include<iostream>
#include<cmath>
using namespace std;

void rotate(int arr[], int n, int D)
{
    for (int x = 0; x < D; x++)
    {
        int si = arr[0];
        for (int i = 0; i < n-1; i++)
        {
            arr[i]=arr[i+1];
        }
        arr[n-1] = si;
    }
}

int main(){
    int t;
    cin>>t;
    for(int j=0;j<t; j++){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int D;
        cin>>D;
        rotate(arr,n,D);
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
    

    return 0;
}