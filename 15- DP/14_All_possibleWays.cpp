// Interesting!!! We can use an "Unordered_map" (HASHMAP) as a memo!!! , for memoisation, instead of using an array (if its suitable acc to circumstances)!

// Chapter Assignment
// Problem Statement: All possible ways
// Problem Level: MEDIUM
// Problem Description:
// Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
// For eg. if a = 10 and b = 2, only way to represent 10 as -
// 10 = 1^2 + 3^2

// Hence, answer is 1.
// Note : x^y represents x raise to the power y
// Inout Format :
// Two integers a and b (separated by space)

// Output Format :
// Count

// Constraints :
// 1 <= a <= 10^5
// 1 <= b <= 50

// Sample Input 1 :
// 10 2

// Sample Output 1 :
// 1

// Sample Input 2 :
// 100 2

// Sample Output 2 :
// 3



#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;


int ways(int a, int b, int i=1)
{
    if(a==0) return 1;
    int ans=0;

    if(pow(i,b) <= a)
    {
        int w1= ways(a- pow(i,b) , b,i+1);
        int w2= ways(a , b, i+1);

        ans= w1 + w2;
    }

    return ans;
}


int DP_fuckingWays(int a, int b, unordered_map<string, int> &um ,int i=1)
{
    if(a==0) return 1;
    int ans=0;


    string key= to_string(a)+ "-" + to_string(i);
    if(um.count(key))
    {
        return um[key];
    }

    if(pow(i,b) <= a)
    {
        int w1= DP_fuckingWays(a- pow(i,b), b, um, i+1);
        int w2= DP_fuckingWays(a , b, um, i+1);
        
        ans= w1 + w2;
    }

    return um[key] = ans;
}



int DP_ways(int a, int b)
{
    unordered_map<string, int> um;

    return DP_fuckingWays(a, b, um, 1);
}





int main(){


    int a,b;
    cin>>a>>b;

    cout<< ways(a,b) <<endl;
    cout<< DP_ways(a,b) <<endl;

    return 0;
}

