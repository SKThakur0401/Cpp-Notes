#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int minStep(int n)          // Basic recursion solution... (poor time complexity)
{
    if(n==1) return 0;
    int s2= INT_MAX;
    int s3= INT_MAX;
    int s1= minStep(n-1);
    if(n%2==0) s2= minStep(n/2);
    if(n%3==0) s2= minStep(n/3);
    return 1+ min(s1, min(s2,s3));
}



int minStep_counter(int n, int *arr)        // Memoisation solution... "top-to-bottom approach"
{
    if(n==1) return arr[n] =0;

    int s1= INT_MAX;
    int s2= INT_MAX;
    int s3= INT_MAX;
    

    if(arr[n-1] != -1) s1=arr[n-1];
    else {s1= minStep_counter(n-1, arr);}

    if(n%2==0)
    {
        if(arr[n/2] != -1) s2= arr[n/2];
        else {s2= minStep_counter(n/2,arr);}
    }

    if(n%3==0)
    {
        if(arr[n/3] != -1) s3= arr[n/3];
        else {s3= minStep_counter(n/3, arr);}
    }

    return arr[n] = 1+ min(s1, min(s2,s3));
}

int MEMO_minSteps(int n)
{
    int *arr= new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i] =-1;
    }
    
    return minStep_counter(n,arr);
}

int DP_minSteps(int n)          // Iterative "DP solution", 'bottom-up' solution
{
    int *arr= new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        if(i==0 || i==1) arr[i]=0;
        else
        {
            int s1=INT_MAX;
            int s2=INT_MAX;
            int s3=INT_MAX;


            s1= arr[i-1]+1;
            if(i%2==0)
            {
                if(arr[i/2] != -1) s2= arr[i/2]+1;
            }
            if(i%3==0)
            {
                if(arr[i/3] != -1) s3= arr[i/3]+1;
            }
            arr[i]= min(s1, min(s2,s3));
        }
    }
    return arr[n];
}


int main()
{
    cout<< MEMO_minSteps(70) <<endl;
    cout<< minSteps(70) <<endl;
    cout<< DP_minSteps(70) <<endl;

    return 0;
}

