#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int fibo(int n)     // Iterative solution of "FIBONACCI", this is fibonacci 
                    // using "DYNAMIC-PROGRAMMING" , it is a "bottom-up" approach.
{
    int * arr= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        if(i==0 || i==1) arr[i] =i;
        else arr[i]= arr[i-1]+ arr[i-2];

    }
    return arr[n];
}



int main(){


    cout<< fibo(10) <<endl;
    cout<< fibo(11) <<endl;
    cout<< fibo(12) <<endl;

    return 0;
}

// 0 1 1 2 3 5 8 13 21 34 55 89 144



// So when we use MEMOISATION: IT IS A RECURSIVE SOLUTION (AND IS TOP-DOWN APPROACH)

// So when we use DYNAMIC PROGRAMMING: IT IS AN ITERATIVE SOLUTION (AND IS BOTTOM-UP APPROACH)

// QUESTION : NOW, WHICH ONE IS BETTER ?
// ANSWER : BOTH ITERATIVE AND RECURSIVE SOLUTION HAVE THE SAME TIME AND SPACE COMPLEXITY, THE ONLY DIFFERENCE IS, (IN CASE OF COMPETETIVE PROGRAMMING), RECURSIVE SOLUTION FAIL SOMETIMES, BECAUSE THE "RECURSION STACK" HAS A LIMITED CAPACITY!, AND CAN'T HOLD VALUES BEYOND THAT, WE CALL IT "STACK-OVERFLOW" (THEY GENERALLY HAVE  A STACK CAPACITY OF 10^4 (FOR CP).... WHICH IS NOT ENOUGH FOR SO QUESTIONS, SO PEOPLE TEND TO USE MATRIX/ BOTTOM-UP APPROACH)
// HOWEVER, IN JOB INTERVIEWS, EVEN YOU CAN USE BOTH MEMOISATION AND DP(BOTTOM-UP) APPROACH, BOTH ARE CONSIDERED EQUALLY GOOD!!


// Using only "recursion" to solve these questions is "BRUTE-FORCE APPROACH!!"
// AND USING MEMOISATION/ BOTTOM-UP IS PROPER SOLUTION
