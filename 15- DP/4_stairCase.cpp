// Problem Description:
// A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;



int wayCount(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;

    int w1=0;
    int w2=0;
    int w3=0;

    w1= wayCount(n-1);
    if(n>=2) w2= wayCount(n-2);
    if(n>=3) w3= wayCount(n-3);

    return w1+w2+w3;
}

int MEMO_solution(int n, int * arr)
{
    if(n==1) return arr[n] = 1;
    if(n==2) return arr[n] = 2;
    if(n==3) return arr[n] = 4;

    if(arr[n]!= -1) return arr[n];

    int w1 = 0;
    int w2 = 0;
    int w3 = 0;
    if(arr[n-1] != -1) w1= arr[n-1];
    else w1= MEMO_solution(n-1, arr);
    if(n>2)
    {
        if(arr[n-2] != -1) w2= arr[n-2];
        else w2= MEMO_solution(n-2, arr);
    }


    if(n>3)
    {
        if(arr[n-3] != -1) w3= arr[n-3];
        else w3= MEMO_solution(n-3, arr);
    }

    return w1 + w2 + w3;
}

int MEMO_wayCount(int n)
{
    int *arr= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i]= -1;
    }
    
    return MEMO_solution(n, arr);
}

int DP_wayCount(int n)
{
    int *arr= new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        if(i==1) arr[i]=1;
        else if(i==2) arr[i]=2;
        else if(i==3) arr[i]=4;
        else
        {
            arr[i]= arr[i-1]+ arr[i-2]+ arr[i-3];
        }
        
    }
    return arr[n];
}

int main(){

    cout<< wayCount(10) <<endl;
    cout<< MEMO_wayCount(10) <<endl;
    cout<< DP_wayCount(10) <<endl;
    

    return 0;
}