#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxFrequency(int arr[], int n)
{
    vector<int> collection;
    unordered_map<int, int> counting;

    for (int i = 0; i < n; i++)
    {
        if(counting.count(arr[i]))
        {
            counting[arr[i]]+=1;
            continue;
        }
        counting[arr[i]]=1;
        collection.push_back(arr[i]);
    }
    
    int max=0;
    int ans;
    for (int i = 0; i < collection.size(); i++)
    {
        if(counting[collection[i]]  > max) 
        {
            max= counting[collection[i]];
            ans= collection[i];
        }
    }
    return ans;
}


int main()
{

    int n; cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }


    cout<< maxFrequency(arr, sizeof(arr)/sizeof(arr[0])) <<endl;
    return 0;
}