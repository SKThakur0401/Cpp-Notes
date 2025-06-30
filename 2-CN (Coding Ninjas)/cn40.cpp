//CALCULATING TOTAL NUMBER OF LOCAL MAXIMA IN AN ARRAY OF NUMBERS,,, HERE, LOCAL MAXIMA= (NUMBER GREATER THAN ALL IT'S PRECEEDING NUMBERS) AND (ALSO GREATER THAN THE(ATLEAST THE IMMEDIATE) NUMBER FOLLOWING IT)     NOTE: FOR THE FIRST AND LAST ELEMENT 1ST AND 2ND STATEMENTS ARE MEANINGLESS RESPECTIVELY

#include<iostream>
#include<cmath>
using namespace std;


int main(){ 
    int n;
    cin>>n; 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int max=0;
    int rbd=0;
    for (int i = 0; i < n; i++)
    {
        if(i<n-1)
        {
            if(arr[i]> max && arr[i]> arr[i+1]){max= arr[i]; rbd++;}
        }
        else if(arr[n-1]>max){rbd++;}
    }

    cout<< rbd <<endl;
    return 0;
}