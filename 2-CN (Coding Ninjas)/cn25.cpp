//  ---A RECURSIVE CODE TO CHECK WHETHER INT "X" IS THERE IN AN ARRAY OR NOT---

#include<iostream>
#include<cmath>
using namespace std;

bool check_in(int n , int arr[], int x){
    if(n==0){return false;}
    if(arr[0] == x){return true;}
    else{return check_in(n-1,arr+1, x) ;}
}


int main(){
    int n;

    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int x;  cin>>x;

    cout<< check_in(n, arr,x) <<endl;

    return 0;
}
