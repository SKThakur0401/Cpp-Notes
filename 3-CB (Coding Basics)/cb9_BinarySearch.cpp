//BINARY SEARCH

#include<iostream>
using namespace std;
 
int bsearchR(int arr[],int n, int start=0 , int end=5)      //BINARY SEARCH USING RECURSION
{ 

    int mid =(start+end)/2;
    if(start == end && arr[mid] != n){return -1;}
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


int bsearch(int arr[],int n, int start=0, int end=5)
{
    while(1)
    {
        int mid;
        mid= (start+end)/2;
        if(arr[mid]==n){return mid;}
        else if(start == end && arr[mid] != n){return -1;}
        else if(arr[mid]>n)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    // return -1;          //IF THE ELEMENT IS NOT PRESENT IN ARRAY , THEN THE THING WILL COME OUT OF WHILE LOOP "EMPTY HANDED" AND WILL RETURN "-1" AFTER COMING HERE
}


int main(){
    int arr[6]= {5,7,8,10,20,30};
    int n=9;
    cout<< bsearchR(arr,n) <<endl;
    cout<< bsearch(arr,n) <<endl;
    return 0;
}