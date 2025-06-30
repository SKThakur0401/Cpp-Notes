// METHOD -3 : SORT THE 2 ARRAYS... THEN STORE THE COMMON ELEMENTS IN THE THIRD ARRAY BY PARALLEL TRAVERSING IN TWO ARRAYS :)

// TIME COMPLEXITY = n1*(log(n1)) + n2*(log(n2)) + n1 + n2

// AN EVEN BETTER METHOD IS USING HASHMAPS ... WE WILL COVER IT LATER

 

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



int intersect3(int ar1[],int ar2[], int arr[], int n1, int n2)
{
    msort(ar1,0, n1 -1);
    msort(ar2,0, n2 -1);
    int i,j,k;
    i=0,j=0;k=0;
    while(i<n1 && j< n2)
    {
        if(ar1[i]<ar2[j]) {i++;}
        if(ar1[i]>ar2[j]) {j++;}
        if(ar1[i] == ar2[j]) {arr[k]= ar1[i]; k++;i++;j++;}
    }
    return k;
}

int main(){
    int ar1[]= {30,27,24,21,18,15,12,9,6,3,1};
    int ar2[]= {30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,1};
    int n1= sizeof(ar1)/4;
    int n2= sizeof(ar2)/4;
    int arr[n1+n2];


    int k =intersect3(ar1,ar2,arr,n1,n2);
    for (int i = 0; i < k; i++)
    {
        cout<<arr[i]<<"  ";
    }
    

    return 0;
}