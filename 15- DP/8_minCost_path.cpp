// WATCH "0" OF "DP-2", TO UNDERSTAND THE QUESTION "(min cost path)", or read it below

// Important Question:
// Coding Problem
// Problem Statement: Min cost Path
// Problem Level: MEDIUM
// Problem Description:
// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
// From a cell (i,  j), you can move in three directions:
// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"

// The cost of a path is defined as the sum of each cell's values through which the route passes.
// Input format :
// The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

// The second line onwards, the next 'M' lines or rows represent the ith row values.

// Each of the ith row constitutes 'N' column values separated by a single space.

// Output format :
// Print the minimum cost to reach the destination.

// Constraints :
// 1 <= M <= 10 ^ 2
// 1 <= N <=  10 ^ 2

// Time Limit: 1 sec

// Sample Input 1 :
// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1

// Sample Output 1 :
// 13

// Sample Input 2 :
// 3 4
// 10 6 9 0
// -23 8 9 90
// -200 0 89 200

// Sample Output 2 :
// 76

// Sample Input 3 :
// 5 6
// 9 6 0 12 90 1
// 2 7 8 5 78 6
// 1 6 0 5 10 -4 
// 9 6 2 -10 7 4
// 10 -2 0 5 5 7

// Sample Output 3 :
// 18







// SOLUTION:

// TRY, TO DO THIS YOURSELF (WAS ABLE TO DO IT COMPLETELY MYSELF)



#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int minCost(int **arr, int r, int c, int cr=0, int cc=0)
{
    if(cr==r && cc==c) return arr[cr][cc];

    int ar = INT_MAX;
    int ac = INT_MAX;
    int arc= INT_MAX;

    if(cr<r) ar= minCost(arr, r, c, cr+1, cc);
    if(cc<c) ac= minCost(arr, r, c, cr, cc+1);
    if(cc<c && cr<r) arc= minCost(arr, r, c, cr+1, cc+1);

    return (arr[cr][cc] + min(ar, min(ac,arc))) ;
}



int MEMO_solution(int **arr, int r, int c, int cr, int cc, int **memo)
{
    if(cr==r && cc==c) return arr[cr][cc];

    if(memo[cr][cc] != -1) return memo[cr][cc];

    int ar = INT_MAX;
    int ac = INT_MAX;
    int arc= INT_MAX;

    if(cr<r) ar= MEMO_solution(arr, r, c, cr+1, cc, memo);
    if(cc<c) ac= MEMO_solution(arr, r, c, cr, cc+1, memo);
    if(cc<c && cr<r) arc= MEMO_solution(arr, r, c, cr+1, cc+1, memo);

    return memo[cr][cc]= (arr[cr][cc] + min(ar, min(ac,arc))) ;
}

int MEMO_minCost(int **arr, int r, int c)
{
    int **memo= new int*[r];
    for (int i = 0; i < r; i++)
    {
        memo[i]= new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            memo[i][j]= -1;
        }
    }
    return MEMO_solution(arr, r-1, c-1, 0 , 0, memo);
}

int DP_minCost(int **arr, int r, int c)
{
    int **memo= new int*[r];
    for (int i = 0; i < r; i++)
    {
        memo[i]= new int[c];
    }
      // See on pen-paper the filling order on our memo( I mean the nested for loops after this comment), our code is filling it in the right order... but there could be other orders also, like CN taught... filling last element first(which we also did) then filling the last row entirely-(which happened in our case too!) and then!, filling the "last column entirely" (which we didn't do) ... and then they used nested loop from (i=r-2 to i=0   && j=c-2 to j=0) ... we instead, used the nested loop for the entire matrix!!!


    for (int i = r-1; i >= 0; i--)
    {
        for (int j = c-1; j >=0; j--)
        {
            if(i== r-1 && j== c-1) memo[i][j]= arr[i][j];

            else if(i== r-1 && j< c-1) memo[i][j]= arr[i][j]+ memo[i][j+1];
            else if(i<  r-1 && j==c-1) memo[i][j]= arr[i][j]+ memo[i+1][j];
            else if(i<  r-1 && j <c-1)
            {
                int w1= memo[i+1][j];
                int w2= memo[i][j+1];
                int w3= memo[i+1][j+1];
                memo[i][j]= arr[i][j]+ min(w1,min(w2,w3));
            }
        }
    }
    return memo[0][0];
}


int main(){


    int r; cin>>r; int c; cin>>c;

    int **arr= new int*[r];

    for (int i = 0; i < r; i++)
    {
        arr[i]= new int[c];
    }
    

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout <<endl;
    cout <<endl;

    cout<< minCost(arr,r-1,c-1) <<endl;
    cout<< MEMO_minCost(arr,r,c) <<endl;
    cout<< DP_minCost(arr,r,c) <<endl;

    return 0;
}



// COMPLEXITIES:

// Recursion Approach:time complexity(as u can imagine) is somewhat "O(3^n) || O(3^m)" depending upon whichever is bigger between m & n


// Memoisation    Approach     :    TIME : O(m*n)      space : O(m*n)
// Dynamic Programming Approach:    TIME : O(m*n)      space : O(m*n)
