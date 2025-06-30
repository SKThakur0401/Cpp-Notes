#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

pair<int,int> counting(vector<int> &A, int mid)
{
    int student=1;
    int sum=0;
    int maxSum=0;
    for(int i=0; i< A.size(); i++)
    {
        if(sum+ A[i] <= mid)
        {
            sum+= A[i];
            maxSum= max(sum, maxSum);
        }
        
        else
        {
            student++;
            sum= A[i];
            maxSum= max(sum, maxSum);
        }
    }
    pair<int, int> pi(student, maxSum);
    return pi;
}

int books(vector<int> &A, int B) {
    
    int high=0;
    for(int i=0; i< A.size(); i++) {high+=A[i];}
    
    int low= A[0];
    int ans= INT_MAX;
    
    while(low <= high)
    {
        int mid= (high+low)/2;
        // int mid= low + (high-low)/2;
        
        pair<int,int> pi = counting(A, mid);
        
        if(pi.first <= B)
        {
            ans= min(ans, pi.second);
            low = mid+1;
        }
        
        else {high= mid-1;}
    }
    
    return ans;
}


int main(){

    vector<int> a;
    int n; cin>>n;

    for (int i = 0; i < n; i++)
    {
        int k; cin>>k;
        a.push_back(k);
    }

    int b; cin>>b;

    cout<< books(a, b) <<endl;

    return 0;
}


// 4
// 12 34 67 90
// 2

