// Given an array of N distinct elements, find the minimum number of swaps required to sort the array.

// HINT : Note: The problem is not asking to sort the array by the minimum number of swaps. The problem is to find the minimum swaps in which the array can be sorted.


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    // int arr[]= {1,5,4,3,2};              // ans=2
    // int arr[]= { 3, 5, 2, 4, 6, 8};         // ans=3
    // int arr[]= {4, 3, 2, 1};             // ans=2
    int arr[]= {2,5,4,1,3};             // ans=4


    vector<pair<int,int> > vp;

    for(int i=0; i< sizeof(arr)/4 ; i++)
    {
        pair<int,int> pi(arr[i],i);
        vp.push_back(pi);
    }

    sort(vp.begin(), vp.end(), compare);

    int swaps=0;

    for (int i = 0; i < vp.size(); i++)
    {
        while(i != vp[i].second)
        {
            swap(vp[i], vp[vp[i].second]);
            swaps++;
        }
    }
    cout<<"Minimum Swaps : "<<swaps<<endl;

    return 0;
}

