//SELECTION SORT : A METHOD OF SORTING WHERE WE TRAVERSE IN ARRAY AND FIND THE LEAST VALUE, THEN SWAP IT WITH "0" INDEX ELEMENT ,,,, THEN REPEAT THIS PROCESS IGNORING THE FIRST INDEX "i.e. 0"  AND FOR THE REST OF THE ARRAY

#include<iostream>
#include<cmath>
using namespace std;
 
void sortR(int arr[], int n)        //SELECTION SORT ALGORITHM(RECURSIVE)
{
    if(n==1){return;}
    else{
        int min=arr[0];
        int mindex=0;
        for (int i = 0; i < n; i++)
        {
            if(min> arr[i]){min = arr[i];   mindex=i;}
        }
        int temp;
        temp= arr[0];
        arr[0]=arr[mindex];
        arr[mindex]= temp;
        return sortR(arr+1, n-1);
    }
}

void sort(int arr[], int n)         //SELECTION SORT WITHOUT THE USE OF RECURSION
{
    for(int j=0; j<n-1;j++)
    {

        int min= arr[j] ;
        int mindex=j;
        for (int i = j; i < n; i++)
        {
            if(min> arr[i])
            {
                min = arr[i];
                mindex=i;
            }
        }

        int temp= arr[j];
        arr[j]=arr[mindex];
        arr[mindex]= temp;
    }
}

int main(){
    int n=7;
    int arr[7]= {7,8,1,2,5,9,6};
    int apple[8]={8,3298,892,92,222,23,121,123};
    sortR(arr,n);
    sort(apple,n);
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
    for (int i = 0; i < n; i++)
    {
        cout<< apple[i]<<" ";
    }
    
    return 0;
}