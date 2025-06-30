// Return the "K" smallest elements in an array... you need to return "K no. of elements" ... which are smallest

// Method 1 : sort the array..then return the initial "k" elements, time complexity: O(n* log(n))

// Method 2 : There's a better solution with time complexity O(n* log(k))!! That's using priority queue... solution is at the end incase u forgot

 
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> kSmallest(int arr[], int n, int k)
{
    priority_queue<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        ans.push(arr[i]);
        ans.pop();
    }
    return ans;
}


int main(){


    int arr[]={1111,599,224,518,62,99,66,931,953,995};

    int n=10; int k=3;

    priority_queue<int> ans= kSmallest(arr, n, k);

    for (int i = 0; i < k; i++)
    {
        cout<< ans.top() <<endl;
        ans.pop();
    }
    

    return 0;
}

// Solution: e.g. if we need to find the smallest element, we'd go through the array once and return the smallest, same thing we r gonna do but using a priority queue, which will hold "k" elements at the same time (the starting 'k' elements initially) and then insert one element, and delete the largest element out of those (k+1) hence maintaining the total k.

// At the end it will have "k" elements and the smallest "k" elements;
