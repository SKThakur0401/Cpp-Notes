// Given an array, remove duplicate elements

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> dupify(int arr[],int n)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < n; i++)
    {
        if(seen.count(arr[i])>0)
        {
            continue;
        }

        seen[arr[i]]= true;
        output.push_back(arr[i]);
    }

    return output;
}

int main(){

    int arr[]= {1,2,2,2,3,4,5,36,11,1,2,5,25,2};
    vector<int> ans = dupify(arr, sizeof(arr)/sizeof(arr[0]));

    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] <<"  ";
    }
    
    return 0;
}