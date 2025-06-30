// METHOD -2
// THIS TIME WE WILL NOT HAVE TO PERFORM ROTATION "D" TIMES, WE WILL DO IT ONLY ONCE :) AND SAVE SOME TIME COMPLEXITY..... HOWEVER WE WILL THIS TIME END UP USING SOME EXTRA SPACE COMPLEXITY (THAT'S THE PRICE FOR REDUCING TIME COMPLEXITY)

// IF THE ROTATION IS SUPPOSED TO HAPPEN "D" TIMES, , WE WILL TAKE THE FIRST "D" ELEMENTS AND STORE IT IN A THIRD ARRAY (THE SPACE COMPLEXITY INCREASE WHICH I WAS TALKING ABOUT) THEN MOVE ALL THE OTHER ELEMENTS "D" UNITS LEFT-WARDS...AND AT THE END, NOW "D" SPACES ARE EMPTY , WHERE WE WILL PLACE THE ELEMENTS WHICH ARE STORED IN THE THIRD ARRAY.
 


#include<iostream>
#include<cmath>
using namespace std;


void rotate(int arr[],int n, int D)
{
    int d[D];
    for (int i = 0; i < D; i++)
    {
        d[i]= arr[i];
    }
    for (int i = 0; i < n-D; i++)
    {
        arr[i]=arr[i+D];
    }
    for (int i = n-D; i < n; i++)
    {
        arr[i]= d[i-n+D];
    }
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