//METHOD -2 :Approach -> Sort the smaller of the two arrays USING MERGE SORT (TO GET MINIMUM TIME COMPLEXITY) THEN RUN FOR LOOP ON BIGGER ARRAY, AND CHECK FOR EACH ELEMENT OF BIGGER ARRAY, IF IT IS PRESENT IN THE SMALLER(SORTED) ARRAY OR NOT,, USING BINARY SEARCH (FOR WHICH WE ACTUALLY SORTED THE SMALLER ARRAY :)

// NOTE: HERE WE CANNOT HANDLE DUPLICATE ELEMENTS :(  ... BCOZ IF WE TURN IT TO -1, THE SECOND ARRAY WHICH WAS SUPPOSED TO BE SORTED FOR USING BINARY SEARCH, WILL NOT REMAIN SORTED ANY MORE

// TIME COMPLEXITY = (MERGE SORT) + (FOR LOOP (n2 times) *Binary search(log(n1)))
//                 = n1*(log(n1)) + n2* (log(n1))
//                 = (n1+n2)*log(n2)        //THAT'S WHY WE WANTED TO APPLY MERGE SORT ON SMALLER ARRAY TO GET "log(n(something))" smaller :)







#include<iostream>
#include<cmath>
using namespace std;

int bsearchR(int arr[],int n, int start , int end)      //BINARY SEARCH USING RECURSION
{

    int mid =(start+end)/2;
    if(start >= end && arr[mid] != n){return -1;}
    if(arr[mid] == n){return mid;}
    else if(arr[mid]> n)
    {
        end=mid-1;
        return bsearchR(arr ,n,start,end);
    }
    else if(arr[mid]< n)
    {
        start=mid+1;
        return bsearchR(arr ,n, start,end);
    }
}



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



int intersect2(int ar1[],int ar2[],int arr[], int n1, int n2)
{
    int k=0;
    msort(ar1,0,(n1)-1);

    for (int i = 0; i < n2; i++)
    {
        if(bsearchR(ar1,ar2[i],0,(n1) -1) != -1 )
        {
            arr[k]= ar2[i];
            k++;
        }
    }
    return k;
}



int main(){
    int ar1[]= {1,3,6,9,12,15,18,21,24,27,30};
    int ar2[]= {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
    int n1= sizeof(ar1)/4;
    int n2= sizeof(ar2)/4;
    int arr[n1+n2];



    int count = intersect2(ar1,ar2,arr,n1,n2);
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<"  ";
    } 
    return 0;
}