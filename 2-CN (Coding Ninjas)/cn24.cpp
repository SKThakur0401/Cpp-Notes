//      ----SUM OF ELEMENTS OF AN ARRAY USING RECURSION----

#include<iostream>
#include<cmath>
using namespace std;

int sum(int arr[], int size){
    if(size==1){return arr[0];}

    else{return arr[0] + sum(arr+1, size-1) ;}
}


int main(){
    int n;
    cin>>n;
    cout<< "Now enter space separated terms : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<< sum(arr,n) <<endl;

    return 0;
}