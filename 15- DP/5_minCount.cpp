// Problem Statement: Minimum Count
// Problem Level: MEDIUM
// Problem Description:
// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
// Input format :
// The first and the only line of input contains an integer value, 'N'.

// Output format :
// Print the minimum count of numbers required.

// Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec

// Sample Input 1 :
// 12

// Sample Output 1 :
// 3

// Explanation of Sample Output 1 :
// 12 can be represented as : 
// A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

// B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

// C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

// D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

// As we can see, the output should be 3.

// Sample Input 2 :
// 9

// Sample Output 2 :
// 1


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// int pow(int x, int n)   return (n==0)? 1 : x* pow(x,n-1);


int minCounter(int n)       // Basic/ OLD recursive approach...(time complexity b/w  2^n  & 3^n !!!)
{
    if(n==0) return 0;
    if(n==1) return 1;

    vector<int> vi;
    int i=1;
    int minvi= INT_MAX;
    while(i*i <= n)
    {
        int a = (minCounter(n- i*i));

        if(minvi>a)
        {
            minvi=a;
        }
        i++;
    }

    return minvi+1;
}





int MEMO_solution(int n, int* arr)      //Memoisation solution
{
    if(n==0) return arr[n]= 0;
    if(n==1) return arr[n]= 1;

    vector<int> vi;
    int i=1;
    int minvi= INT_MAX;
    while(i*i <= n)
    {
        int a;
        if(arr[n- i*i] != -1) a= arr[n- i*i];
        else a = (MEMO_solution(n- i*i , arr));

        if(minvi>a)
        {
            minvi=a;
        }
        i++;
    }

    return arr[n] = minvi+1;
}

int MEMO_minCounter(int n)
{
    int *arr= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i]=-1;
    }
    return MEMO_solution(n,arr);
}





int DP_minCounter(int n)            // DP (bottom-up solution)
{
    int *arr= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        if(i<=1) arr[i]=i;
        else{
            int minvi=INT_MAX;
            int x=1;
            while(x*x <=i)
            {
                int a=INT_MAX;
                if(arr[i- x*x] != -1)
                {
                    a= arr[i- x*x];
                }
                if(a< minvi) minvi=a;
                x++;
            }
            arr[i]= minvi+1;
        }
    }
    return arr[n];
    
}


int main(){

    int n=8;
    cout<< minCounter(n) <<endl;
    cout<< MEMO_minCounter(n) <<endl;
    cout<< DP_minCounter(n) <<endl;

    return 0;
}


// Gintama and daily lives of highschool boys
