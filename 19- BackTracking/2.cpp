#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool ispossible(int arr[], int n, int mid, int cows)
{
    cows--;
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] - arr[j] >= mid)
        {
            cows--; j=i;

            if(cows==0) return true;
        }
    }
    return false;
}

int main(){

    int n,c; cin>>n>>c;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int low= arr[0]; int high= arr[n-1];
    int ans=0;

    while(low <= high)
    {
        int mid= low + (high-low)/2;

        if(ispossible(arr,n, mid, c))
        {
            ans= max(ans, mid);
            low=mid+1;
        }
        
        else high= mid-1;
    }

    cout <<endl;
    cout <<endl;
    cout<<ans <<endl;

    return 0;
}

