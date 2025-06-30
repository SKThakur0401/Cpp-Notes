//RETURNING AN ARRAY COMPRISING OF ALL THE SUB-ARRAYS OF "arr"

#include<iostream>
#include<cmath>
using namespace std;

//  IF YOU ITERATE IN A STRING AND "arr[i]" IS AN ELEMENT IN THAT STRING then ,,, arr[i] is actually a "char" data-type since it is a single alphabet here

int main(){

    int n; 
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int ans[(n*(n+1))/2];
    int index=0;

    for (int i = 0; i < n; i++)
    {
        int k=0;
        for (int j = 0; j < n; j++)
        {
            if (i+j < n)
            {
                k=k+ arr[i+j];
                ans[index]= k;
                index++;
            }
        }
    }
    
    for (int i = 0; i < (n*(n+1))/2 ; i++)
    {
        cout<< ans[i] <<" ";
    }
    
    return 0;
}