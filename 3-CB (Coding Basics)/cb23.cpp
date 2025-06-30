// Problem Statement: Return subset of an array
// Problem Level: HARD
// Problem Description:
// Given an integer array (of length n), find and return all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.
// Input format :
// Line 1 : Size of array
// Line 2 : Array elements (separated by space)

// Sample Input: 
// 3
// 15 20 12
 
// Sample Output:
// [] (this just represents an empty array, don't worry about the square brackets)
// 12 
// 20 
// 20 12 
// 15 
// 15 12 
// 15 20 
// 15 20 12
//                  ------SOLUTION--------









//GOOD, IF U NOTICED, IT'S JUST THE "STRING SUBSEQUENCE PROBLEM, DONE WITH INTEGER ARRAY" ,,, TRY URSELF, IF NOT VERY CONFIDENT WITH "STRING SUBSEQUENCE PROBLEM" :)

#include<iostream>
#include<cmath>
using namespace std;

int ans(int arr[], int n, string output[])
{
    if(n ==0){output[0]= "" ; return 1;}
    int smallSize = ans(arr+1,n-1,output);

    for (int i = 0; i < smallSize; i++)
    {
        output[i+ smallSize] = to_string(arr[0])+ " " + output[i];
    }
    return 2* (smallSize);
}


int main(){
    int n;

    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    string output[100];
    int count = ans(arr,n,output);

    for (int i = 0; i < count; i++)
    {
        cout<< output[i] <<endl;
    }
    
    

    return 0;
}