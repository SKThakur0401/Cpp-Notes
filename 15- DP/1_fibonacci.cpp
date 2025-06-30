// "DP" is an extension of "recursion" only, if u know recursion well, then "DP" will be easy, else impossible.

// DP is nothing but "recursion + storage", it is a method to optimise recursion, i.e. reduce time complexity by preventing the redundant calculations, (by maintaining an array which contains info about which operations are already performed)

// Question: How do we know, when to use DP?

// Answer:  i> When we are given a choices
            // When we r given a choice to do something or not...(like in knapsack)..., we can totally imagine that recursion can solve this problem, so we use "DP" there,

//        ii> When we need to "optimise something", like maximise,minimise etc...


// Question:  How do we use DP?
// Answer  :  There are two methods,
//         i. Recursion+ memoisaion
//        ii. Top-down approach

// In all these soln, first use "recursion", then make the necessary changes in recursive soln, to implement "top-down" or "memoisation" approach.

// Lets solve "fibonacci series" with the help of recursion, and the with "recursion+memoisation" for better Time Comlexity.

// Note: Time complexity of "fibonacci" (if u remember is)  O(2^n) , which is "very-high".


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int Old_fibo(int n)     // The "old" code of fibonacci that we know
{
    return (n==0 || n==1)? n : Old_fibo(n-1) + Old_fibo(n-2);
}


int fibonacci(int n, int * arr);    // This line is just to tell that "fibonacci" function exists!, 
                                    // and is coded later on, so don't give any error



int fibo(int n)                     // This is "fibonacci" with "memoisation"
{                                   // Memoisation is a "top-to-bottom" approach
    int *arr= new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        arr[i]=-1;
    }
    return fibonacci(n, arr);
}

int fibonacci(int n, int *arr)      // Helper function
{
    if(n==0 || n==1)
    {
        return arr[n]=n;
    }

    if(arr[n] != -1) return arr[n];

    return arr[n]= fibonacci(n-1,arr) + fibonacci(n-2, arr);
}

int main(){

    cout<< Old_fibo(20) <<endl;
    

    cout<< fibo(20) <<endl;

    return 0;
}


// AFTER USING MEMOISATION, WE "DRASTICALLY REDUCED" THE TIME COMPLEXITY FROM "O(2^n)"  to "O(n)" !!
// So, although memoisation consumes space, its worth it coz the time complexity is much better now!
