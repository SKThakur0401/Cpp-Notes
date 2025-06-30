// Find how many pairs can have a net sum= num, return the total number of such pairs

#include<iostream>
#include<cmath>
using namespace std;
// Method 1 : run 2 for loops, for each element, add it to all the elements in the array, and in all the cases where sum is equal to "num" add "1" to the output . ...Time complexity = O(n^2)

// Method 2 : (Which we are going to use here) (Figure out urself)
  //IF NOT ABLE TO FIGURE OUT :::> FIRST SORT IN ASCENDING ORDER..THEN TRAVERSE IN ARRAY FROM BOTH SIDES USING "i and j" when their sum is greater than the required number.. do j--  else i++

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



int sumPair(int arr[], int n, int num)
{
    msort(arr,0,n-1);

    int i,j,k;
    i=0;k=0; j=n-1;
    while(i < j)
    {
        if(arr[i]+arr[j] > num){j--;}
        else if(arr[i]+arr[j] < num){i++;}
        else if(arr[i]+arr[j] == num)
        {
            int same_i=1; int same_j=1;     // we r using "same_i" and "same_j" to know how many consecutive "i's" have same value and how many consecutive j's have same value, for example, the given sum is = "5" , and we have the given array as = {1,2,2,3,3,3,99};   so here, 5 can be formed using "2 & 3" but there are 2 two's and 3 three's !! , so there is actually, 2*3 = 6 combinations possible which can make 6 !

            while(arr[i] == arr[i+1]    && (i+1)<j)     // for counting the number of times "arr[i]"
            {                                           // repeats itself,
                same_i++;
                i++;
            }

            while(arr[j] == arr[j-1]   &&  (j-1) >i)    // for counting the number of times "arr[j]"
            {
                same_j++;
                j--;
            }
            int mul = same_i*same_j;
            k+=mul;
            i++;j--;
        }
    }
    return k;
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
        int num;
        cin>>num;
        int ap =sumPair(arr,n,num);
        cout<< ap <<endl;
    }
    

    return 0;
}
