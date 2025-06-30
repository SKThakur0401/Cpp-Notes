//--- A RECURSIVE FUNCTION TO RETURN THE LOCATION  OF AN ELEMENT IN AN ARRAY (IF THAT ELEMENT IS REPEATED,,, "FINDER" WILL GIVE LOCATION OF THE "LEFT-MOST" OCCURENCE AND "FINDER_R2L" WILL GIVE LOCATION OF "RIGHT-MOST" OCCURENCE :)----

#include<iostream>
#include<cmath>
using namespace std;


int finder(int n, int arr[], int x, int ans=0){
    if(n==0){return -1 ;}               //THIS IS OUR BASE CASE,,, WHEN SIZE BOILS DOWN TO "0" THAT MEANS ELEMENT IS NOT PRESENT IN ARRAY
    if(arr[0]==x){return ans;}
    ans++;
    return finder(n-1, arr+1, x, ans);
}

int finder_r2l(int n, int arr[], int x){
    if(n==0){return -1;}
    if(arr[n-1] == x){return n-1;}
    return finder_r2l(n-1, arr, x);
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
    cout<< finder(n,arr,x) <<endl;
    cout<< finder_r2l(n,arr,x) <<endl;

    return 0;
}

