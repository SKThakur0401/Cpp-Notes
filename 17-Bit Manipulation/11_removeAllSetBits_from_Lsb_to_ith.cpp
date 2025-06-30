// Question: Remove all set bits starting from "LSB"(least significant bit, right most) to the "ith" bit (from right)...

// Solve in " O(1) " time complexity...



// Solution is quite interesting/mathematical type...

// SOLUTION : (THINK URSELF BEFORE READING...)  for any no. if we want to make all it's digit starting from "LSB" to "ith" digit 0!! , we should do "bitwise and" of that no. with a no. with all it's bits "1" except the bits starting from "LSB" to "ith" bit..... that will be our answer...

// Now how to create such mask!!, where all it's digits are "1" except the digits starting from "LSB" to "ith" digit....(think)... for that let the mask be "x" and x = 1 << i+1;  x= x-1; now we obtained a no. where all it's digits are 0 except the digits starting from "LSB to ith" digit... so it's negation is the desired mask!!!

// so!!  x = ~(1<<(i+1)  -1)

// and answer = n & x;


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int removeLSB_to_i(int n, int i)
{
    int x = 1<< (i+1);
    x--;
    x = ~x;

    return n & x;
}


int main(){


    int n ; cin>>n;
    int i ; cin>>i;


    cout<< removeLSB_to_i(n,i) <<endl;

    return 0;
}


