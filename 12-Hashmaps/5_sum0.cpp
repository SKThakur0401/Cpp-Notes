// We made a generalized code for sum of 2 numbers = "k" 
// We find how many pairs can have sum= k

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int sumo(int arr[], int n, int k=0)         // U can change value of "k"
{
    unordered_map<int,int> ourmap;
    int ans=0;

    for (int i = 0; i < n; i++)
    {
        int b= k-arr[i];
        if(ourmap[b])
        {
            ans+= ourmap[b];
        }
        ourmap[arr[i]]++;
    }
    
    return ans;
}

int main(){

    int n; cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout <<endl;

    cout<< sumo(arr,n) <<endl;
    
    

    return 0;
}