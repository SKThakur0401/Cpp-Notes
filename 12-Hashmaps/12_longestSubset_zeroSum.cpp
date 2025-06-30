#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int longestSubArray(int arr[],int n)
{
    int count=0;
    unordered_map<int,int> om;
    int s=0;
    for (int i = 0; i < n; i++)
    {
        s+=arr[i];
        if(s==0) return i+1;
        if(om.count(s))
        om[s]=1;
    }
    
}

int main()
{

    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<longestSubArray(arr,n)<<endl;



    return 0;
}

