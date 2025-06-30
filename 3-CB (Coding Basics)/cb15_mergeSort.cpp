//MERGE SORT ALGORITHM

#include<iostream>
#include<cmath>
using namespace std;
 
void merge(int arr[], int si, int mid , int ei)
{
    int n1= mid-si +1;
    int n2= ei-mid ;
    int a[n1];
    int b[n2];
 
    for (int i = 0; i < n1; i++)
    {
        a[i]=arr[si+i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i]=arr[mid+1+i];
    }
    
    int i,j,k;
    i=0;j=0;k=si;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j]){  arr[k]=a[i]; k++;   i++;}
        else if(a[i]>b[j]){  arr[k]=b[j]; k++;   j++;}
        else if(a[i] == b[j]){ arr[k]=a[i]; k++; i++; arr[k]=b[j]; k++; j++;}
    }
    while (i<n1)
    {
        arr[k]=a[i];k++;i++;
    }
    while (j<n2)
    {
        arr[k]=b[j];k++;j++;
    }
}

void msort(int arr[], int si , int ei)
{

    if(si>=ei){return;}
    int mid = (si+ei)/2;

    msort(arr,si , mid);
    msort(arr,mid+1,ei);
    merge(arr, si, mid , ei);
}



int main(){

    int arr[]= {42,12,33,122,34,11,21,88,29,329,929,93,78,98};

    // int arr[]={2,3,1,4,5};
    int n= int(sizeof(arr)/4);
    // cout<< n <<endl;
    msort(arr,0, n-1);


    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
    
    return 0;
}