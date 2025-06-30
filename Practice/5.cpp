#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int stairs(int n, int *arr)
{
    if(n <0) return 0;
    if(n==0) return arr[n] = 1;
    if(arr[n] != -1) return arr[n];
    return arr[n] = stairs(n-1, arr) + stairs(n-2, arr) + stairs(n-3, arr);
}

int main(){

    int n; cin>>n;
    int* arr = new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        arr[i]=-1;
    }
    
    cout<< stairs(n, arr) <<endl;

    return 0;
}

