#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// bool binarySearch(vector<int>& vi, int target){
//     int si =0;
//     int ei = vi.size()-1;
//     while(si <= ei){
//         int mid = si + (ei-si)/2;
//         if(vi[mid] == target) return true;

//         else if(vi[mid] < target) si = mid+1;
//         else ei = mid-1;
//     }

//     return false;
// }

int fac(int x){
    return (x == 0)? 1 : x*fac(x-1);
}

// Fibonacci
// 0 1 1 2 3 5 8 13 21 34 55

int fibo(int n){
    if(n < 2) return n;
    if(n== 2) return 1;

    // return fibo(n-1) + fibo(n-2);

    int prev = 1;
    int curr = 1;
    for(int i=3; i <= n; i++){
        int temp = curr;
        curr = curr + prev;
        prev = temp;
    }

    return curr;
}

int main(){

    int n=5;

    // vector<int> vi;
    // while(n--){
    //     int x; cin>>x;
    //     vi.push_back(x);
    // }
    // cout <<endl;

    

    // bool b = binary_search(vi.begin(), vi.end(), 4);
    // cout<< b <<endl;
    
    cout<< fibo(10) <<endl;
    

    return 0;
}

