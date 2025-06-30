// A "k-sorted array" is an array whose elements are "atmost" 'k' units away from their rightful position.

#include<iostream>
#include<queue>
using namespace std;

void Ksort(int arr[],int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    { 
        pq.push(arr[i]);
    }

    int j=0;
    
    for (int i = k; i < n; i++)
    {
        arr[j]= pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    for (int i = 0; i < k; i++)
    {
        arr[j+i]=pq.top();
        pq.pop();
    }
}

int main(){

    int arr[]={10,12,6,7,9};
    int n=5; int k=3;

    Ksort(arr,n,k);

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<endl;
    }

    return 0;
}