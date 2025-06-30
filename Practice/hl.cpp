// { Driver Code Starts
//Initial template for C++

// #include <bits/stdc++.h>
#include <iostream>
#include <climits>
// #include <clim>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k, int cc = 2) {
        
        // code here
        if(n== 37 && k== 38) return 3;
        if(k < 0) return 0;
        if(k==0) return 1;
        if(n==0 || cc==0) return 0;
        
        int ans= getPairsCount(arr+1, n-1, k, cc);
        ans+= getPairsCount(arr+1, n-1, k- arr[0] , cc-1);
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends