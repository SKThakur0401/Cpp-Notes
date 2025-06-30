// METHOD -3
// WE WILL USE A FUNCTION CALLED REVERSE, WHICH WILL REVERSE THE ENTIRE ARRAY.
// WE WILLL FIRST USE IT FOR THE ENTIRE ARRAY, THEN FOR THE FIRST "N-D" ELEMENTS, AND THE FOR THE LAST "D" ELEMENTS.

 


#include<iostream>
#include<cmath>
using namespace std;

void reverse(int arr[],int n)
{
    for (int i = 0; i < (n/2); i++)
    {
        int temp = arr[i];
        arr[i]= arr[n-1-i];
        arr[n-1-i]= temp;
    }
}

void rotate(int arr[], int n, int d)
{
    reverse(arr,n);
    reverse(arr,n-d);
    reverse(arr+n-d,d);
}

int main(){
    int t;
    cin>>t;
    for(int j=0;j<t; j++){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int D;
        cin>>D;
        rotate(arr,n,D);
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
    return 0;
}