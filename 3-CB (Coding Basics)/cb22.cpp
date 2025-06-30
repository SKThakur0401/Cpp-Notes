// Chapter Assignment
// Problem Statement: Staircase
// Problem Level: EASY
// Problem Description:
// A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
// Input format :
// Integer N
 
// Output Format :
// Integer W
 
// Constraints :
// 1 <= N <= 30

// Sample Input 1 :
// 4

// Sample Output 1 :
// 7

// Sample Input 2 :
// 5

// Sample Output 2 :
// 13


#include<iostream>
#include<cmath>
using namespace std;

void stairs(int n, int & k)
{
    if(n==0){k+=1;}
    else if(n > 0){
    stairs(n-1,k);
    stairs(n-2,k);
    stairs(n-3,k);
    }
}

int stairs_Memoised(int n, int memo[])
{
    int ans=0;
    if(n<0) return 0;
    if(n==0) return memo[0] = 1;
    if(memo[n] !=0 ) return memo[n];
    ans+= stairs_Memoised(n-1, memo);
    ans+= stairs_Memoised(n-2, memo);
    ans+= stairs_Memoised(n-3, memo);

    return memo[n] = ans;
}

int stairs_Memo(int n)
{
    int* memo = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        memo[i]= 0;
    }
    return stairs_Memoised(n, memo);
    
}

int main(){

    cout<< "Enter no. of staircases : ";
    int n;
    cin>>n;
    int k=0;
    stairs(n,k);

    cout<< k <<endl;
    return 0;
}