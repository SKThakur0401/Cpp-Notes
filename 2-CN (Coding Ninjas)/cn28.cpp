#include<iostream>
#include<cmath>
using namespace std;
// int index[];

int out(int n,int arr[], int x,int adr=0,int ind=0){
    if(n==0){return ind;}
    if(*arr== x){ ind++;}
    adr++;
    return out(n-1,arr+1,x,adr,ind);
}
 

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<< out(n,arr,x) <<endl;

    return 0;
}