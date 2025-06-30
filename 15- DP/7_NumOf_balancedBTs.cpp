// QUESTION:
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so return output modulus 10^9 + 7.


// SOLUTION:
// FIRST REMEMBER WHAT "BALANCED-BINARY-TREE" IS "CLEARLY", THEN ONLY THERE'S A CHANCE OF SOLVING THIS QUESTION.... (BALANCED BINARY TREE... A TREE WHERE DIFFERENCE BETWEEN HEIGHT OF RIGHT SUB-TREE AND LEFT SUB-TREE IS EQUAL TO "0" OR ATMOST EQUAL TO "1")

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int fac(int x) {return (x==0)? 1: x* fac(x-1);}

int C(int n, int r)
{
    return fac(n)/(fac(n-r)*fac(r));
}


int treeCount(int h)        //Wrong solution  :(  ... I DIDN'T KNEW WHAT BALANCED-BINARY-TREE IS
{
    if(h==1) return 1;
    // if(h==2) return 3;

    int w1= treeCount(h-1);


    return (2* w1)+ (w1*w1);
}


int treecount(int h)        // THIS WORKS PERFECTLY FINE!!
{
    if(h==1) return 1;
    if(h==0) return 1;
    // if(h==2) return 3;

    int w1= treecount(h-1);
    int w2= treecount(h-2);

    return 2*(w1)*w2 + w1 * w1 ;
}


int MEMO_solution(int h, int *arr)        // THIS WORKS PERFECTLY FINE!!
{
    if(h==1) return arr[h]=1;
    if(h==0) return arr[h]=1;
    // if(h==2) return 3;
    if(arr[h] != -1) return arr[h];

    int w1= MEMO_solution(h-1, arr);
    int w2= MEMO_solution(h-2, arr);

    return arr[h]= (2* w1 * w2) + (w1 * w1) ;
}

int MEMO_treecount(int h)
{
    int *arr= new int[h+1];
    for (int i = 0; i < h+1; i++)
    {
        arr[i]=-1;
    }
    return MEMO_solution(h, arr);
}

int DP_treecount(int h)
{
    int* arr= new int[h+1];
    for (int i = 0; i < h+1; i++)
    {
        if(i<=1) arr[i]=1;

        else
        {
            arr[i]= 2*(arr[i-1] * arr[i-2]) +  arr[i-1]*arr[i-1];
        }
        
    }
    return arr[h];
}


int main(){

    int n=4;
    // cout<< treeCount(n) <<endl;     // WRONG CODE!
    cout<< treecount(n) <<endl;
    cout<< MEMO_treecount(n) <<endl;
    cout<< DP_treecount(n) <<endl;


    return 0;
}