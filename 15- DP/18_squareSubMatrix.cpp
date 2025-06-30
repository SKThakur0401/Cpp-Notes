// Different type of implementaion, intelligent but logical way of optimisation (I couldn't have  ever come up with something like this!)   // If not able to solve!!,recommended to watch the video Again! , coz after watching, it would be crystal clear

// Chapter Assignment
// Problem Statement: Maximum Square Matrix With All Zeros
// Problem Level: MEDIUM
// Problem Description:
// Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
// Input format :
// The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

// Second-line onwards, the next 'N' lines or rows represent the ith row values.

// Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).

// Output Format:
// Print the size of maximum square sub-matrix.

// Constraints :
// 0 <= N <= 10^4
// 0 <= M <= 10^4

// Time Limit: 1 sec

// Sample Input 1:
// 3 3
// 1 1 0
// 1 1 1
// 1 1 1

// Sample Output 1:
// 1

// Sample Input 2:
// 4 4
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0

// Sample Output 2:
// 4



#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int DP_matrixSize(int **arr, int m, int n)
{
    int ** memo= new int*[m];
    for (int i = 0; i < m; i++)
    {
        memo[i]= new int[n];
    }

    int max_in_Matrix = 0;      // This is our answer,  Initially "0" assuming that there are no "zero's" in the matrix;

    // Base case initialisation (i.e. first row and column initialisation)
    for (int i = 0; i < m; i++)
    {
        if(arr[i][0] ==0 )
        {
            memo[i][0] =1;

            if(memo[i][0] > max_in_Matrix) max_in_Matrix= memo[i][0];
        }
        if(arr[i][0] ==1 ) memo[i][0] =0;
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[0][i] ==0 )
        {
            memo[0][i] =1;

            if(memo[i][0] > max_in_Matrix) max_in_Matrix= memo[i][0];
        }
        if(arr[0][i] ==1 ) memo[0][i] =0;
    }
    // --------------------------------------------------------------------------


    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(arr[i][j] ==1) memo[i][j]=0;

        if(arr[i][j] ==0) memo[i][j] = 1 + min(memo[i-1][j-1] , min(memo[i][j-1], memo[i-1][j]));

            if(memo[i][j] > max_in_Matrix) max_in_Matrix= memo[i][j];
        }
    }

    return max_in_Matrix;
}


int main(){

    int m,n;
    cin>>m>>n;
    int ** arr= new int*[m];
    for (int i = 0; i < m; i++)
    {
        arr[i]= new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    cout<< DP_matrixSize(arr, m, n) <<endl;
    

    return 0;
}

