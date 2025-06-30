//QUICK SORT
#include<iostream>
#include<cmath>
using namespace std;
 
int partition(int arr[], int si, int ei)
{
    int x = arr[si];
    int count=0;
    for (int i = si+1; i <= ei ; i++)
    {
        if(arr[i]<x){count++;}
    }
 
    int temp=arr[si];
    arr[si]=arr[si+count];
    arr[si+count]= temp;

    int i,j;
    i=si;j=ei;

    while(i<count+si  &&  j> count+si)
    {

        if(arr[i]> arr[si+count]  &&  arr[j]<arr[si+count])
        {
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        else if(arr[i] > arr[si+count])
        {
            j--;
        }
        else if (arr[j]<arr[si+count])
        {
            i++;
        }

        else{i++;j--;}
    }
    return count;
}

void qs(int arr[], int si, int ei)
{
    if(si>=ei){return;}
    
    int c= partition(arr,si,ei);

    qs(arr,si,si+c-1);
    qs(arr,si+c+1,ei);
}

int main(){
    int arr[]={3,4,21,2,23,23,54,28,29,53,6,45,4,76};
    int n= sizeof(arr)/4;   //RETURNS NO. OF ELEMENTS IN ARRAY
    qs(arr,0,n-1);          //  qs(arr, starting_index , ending_index)

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }

    return 0;
}