//QUESTION : Chapter Assignment
// Problem Statement: Geometric Sum
// Problem Level: MEDIUM
// Problem Description:
// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

// using recursion.
// Input format :
// Integer k

// Output format :
// Geometric sum
 
// Constraints :
// 0 <= k <= 1000

// Sample Input 1 :
// 3

// Sample Output 1 :
// 1.875






#include<iostream>
#include<cmath>
using namespace std;

double pow(int x, int n){
    if(n==0){return 1;}
    return x * pow(x,n-1);
}

double geo(int k){
    if(k==0){return 1;}
    return (1/(pow(2,k))) + geo(k-1);
}


int main(){
    int k;
    cin>>k;
    cout<< geo(k) <<endl;
    

    return 0;
}