// Just Read the inference first!! LINE: 16 onwards!
// Implementing Min Priority Queue (IN STL):
// A priority queue is just like a normal queue data structure except that each element inserted is associated with a “priority”.
 
// In STL, priority queues take three template parameters:
// template <class T,
// class Container = vector<T>,
// class Compare = less<typename Container::value_type> >

// class priority_queue;
// • The first element of the template defines the class of each element. It can be user-defined classes or primitive data-types. Like in you case it can be int, float or double.
// • The second element defines the container to be used to store the elements. The standard container classes std::vector and std::dequeue fulfil these requirements. It is usually the vector of the class defined in the first argument. Like in your case it can be vector<int>, vector<float>, vector<double>.
// • The third element is the comparative class. By default it is less<T> but can be changed to suit your need. For min heap it can be changed to greater<T>.


// INFERENCE
// So the "priority_queue" in STL, can take 3 parameters,
// first : data-type of elements to be stored
// Second: In which data-structure u will hold those elements...(can be vector , dequeue ..etc)
// Third : Which type of "priority_queue" u want? the default is "max-heap" you can keep/continue using max heap if you put the third parameter as   "less<int>"  ... but if you want a "min-heap", make the third parameter "greater<int>"


#include<iostream>
#include<queue>
using namespace std;

int Kth(int arr[],int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;  //First parameter "int", so we will store 
                                    // int here, second parameter "vector<int>" so we r gonna use vector to store elements in the back-end, third parameter "greater<int>" so the smallest element will be poped-out first! therefore its a "min-heap"
    
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        pq.push(arr[i]);
        pq.pop();
    }
    return pq.top();
}

int main(){

    // NOTE: the solution in which we merge-sort the array and then return the "K_th" largest element has time-complexity "O(n* log_n)"

    // But our solution using "priority_queue" has time-complexity "O(n* log_k)" ... here alot of times... "k" is very small in comparison to "n", so "log_k" could be very small!!, and can be neglected... so the time complexity "can be" tending to "O(n)"

    int arr[]={9,4,8,7,11,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<< Kth(arr,n,k) <<endl;

    return 0;
}

