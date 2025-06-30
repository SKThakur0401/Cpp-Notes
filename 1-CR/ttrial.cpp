#include<iostream>
#include<climits>
#include<math.h>

using namespace std;

long long fac(int n)
{
    return (n == 1)? 1 : n* fac(n-1);
}

long long factorial(int n)
{
    long long sum=1;
    for(int i=1 ; i<=n ; i++)
    {
        sum*=i;
    }
    return sum;
}

void rev(int arr[], int n)
{
    for (int i = 0; i < n/2; i++)
    {
        int temp = arr[i];
        arr[i]= arr[n-1-i];
        arr[n-1-i]= temp;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<endl;
    }
}

int main()
{
    // cout<<"Enter First integer : ";
    // int n;
    // cin>>n;

    // cout<<"Factorial of first integer is : "<< fac(n)<<endl;
    // cout<<"Factorial of first integer is : "<< factorial(n)<<endl;

    cout<< "How many elements you want in array : " <<endl;
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    print(arr,n);
    rev(arr,n);
    print(arr,n);
}

