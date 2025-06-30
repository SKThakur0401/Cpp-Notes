#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

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
    cout<<"Answer : "<<swaps<<endl;

    return 0;
}

