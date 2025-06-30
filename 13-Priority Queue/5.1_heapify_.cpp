// "Heapify" is an important function which you should know, it is used to transform an array of random integers into an array of integers..which are stored in "heap-structure", so it will convert a useless array into an array where elements are stored like in heap!!!

#include<iostream>
#include<queue>
using namespace std;


 
bool isMaxHeap(int arr[],int n, int i=0)        // This is program which detects whether a given 
                                    // array is a heap or not, no need to see this code now!! , it is done later also, here it is only used as an utility function to check whether "heapify" is working properly or not...
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

void heapify(int arr[],int n,int pi)
{
    int max_Index= pi;        // It will hold the "index" of the element which is greatest amongst "lci", "rci" and "pi" ... we simply initialised it as "pi" and later if "index- lci" holds a greater value, then "max_Index" will be changed to "lci" and... "rci" if rci holds an even greater value :)

    int lci= 2*pi +1;
    int rci= 2*pi +2;

    if(lci<n && arr[max_Index]< arr[lci])
    {
        max_Index =lci;
    }

    if(rci<n && arr[max_Index]< arr[rci])
    {
        max_Index =rci;
    }
                                                            
    if(max_Index != pi)
    {
        swap(arr[max_Index] ,arr[pi]);

        heapify(arr, n, max_Index);
    }
}


int main(){

    int arr[]={9,32,246,3,99,636,125,2,5,25,24,2452};
    int n= sizeof(arr)/sizeof(arr[0]);
    int last_non_LeafNode= (n/2) -1;            // All leaf nodes are already heaps! (bcoz they don't have any children...they don't have any criteria to fulfill.... so we need to start checking from the first NON-LEAF node!)


    for (int i = last_non_LeafNode; i >=0; i--)
    {
        heapify(arr,n,i);
    }
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    
    cout<< isMaxHeap(arr,n) <<endl;

    return 0;
}

