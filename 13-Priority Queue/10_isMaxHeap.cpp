#include<iostream>
#include<cmath>
using namespace std;
 
bool isMaxHeap(int arr[],int n, int i=0)
{   
    int lci= 2*i+1;
    int rci= 2*i+2;

    if(lci<n && rci<n)
    {
        if(arr[i]<arr[lci] || arr[i]<arr[rci]) return false;
    }

    else if(lci<n)
    {
        if(arr[i]<arr[lci]) return false;
    }


    if(lci<n)
    {
        bool l= isMaxHeap(arr,n,lci);
        if(l==false) return false;
    }
    if(rci<n)
    {
        bool r= isMaxHeap(arr,n,rci);
        if(r== false) return false;
    }
    return true;
}

int main(){

    int arr[]={57,38,45,32,23,10,46};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<< isMaxHeap(arr,n) <<endl;

    return 0;
}