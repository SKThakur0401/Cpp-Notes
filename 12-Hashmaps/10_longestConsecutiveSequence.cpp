#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
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

void upper(int arr[],int n)
{
    msort(arr,0,n-1);
    int max=0;
    int count=0;
    int lower=INT_MIN;
    int upper;
    int index;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]== arr[i-1]+1)
        {
            count++;

            if(count>max)
            {
                max=count;
                index=i;
                upper=arr[i];
            }
        }
        else
        {
            count=0;
        }
    }
    while(arr[index]== arr[index-1]+1)
    {
        index-=1;
        if(index==0) break;
    }
    lower=arr[index];

    cout<< lower<<"  "<<upper <<endl;
}

int solution(int arr[], int n)      //This is not working!!!
{
    unordered_map<int,bool> om;
    for (int i = 0; i < n; i++)
    {
        om[arr[i]]=true;
    }
    int s=0;
    int maxLen=0;

    for (int i = 0; i < n; i++)
    {
        if(om[arr[i]]==false) continue;
        int len=1;
        int x=1;
        om[arr[i]]= false;

        while(om.count(arr[i] +x ))
        {
            len++;
            if(len>maxLen)
            {
                maxLen=len;
            }
            x++;
            om[arr[i]+x]= false;
        }
        x=1;
        while (om.count(arr[i]-x))
        {
            len++;
            if(len>maxLen)
            {
                maxLen=len;
                s=arr[i]-x;
            }
            x++;
            om[arr[i]-x]=false;
        }
    }
    return s;
}


void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }
}

int main(){

    // int n; cin>>n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    int n=5;
    int arr[]= {1,3,5,2,4};
    cout <<endl;
    upper(arr,n);

    
    print(arr,n);
    int s= solution(arr,n);     // THIS IS NOT WORKING
    cout<< s <<endl;

    return 0;
}
