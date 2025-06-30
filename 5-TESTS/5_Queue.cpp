// Chapter TEST
// Problem Statement: Dequeue
// Problem Level: MEDIUM
// Problem Description:
// You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
// You don't need to double the capacity.
// You need to implement the following functions -
// 1. constructor
// You need to create the appropriate constructor. Size for the queue passed is 10.
// 2. insertFront -
// This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
// 3. insertRear -
// This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
// 4. deleteFront -
// This function removes an element from the front of queue. Print -1 if queue is empty.
// 5. deleteRear -
// This function removes an element from the end of queue. Print -1 if queue is empty.
// 6. getFront -
// Returns the element which is at front of the queue. Return -1 if queue is empty.
// 7. getRear -
// Returns the element which is at end of the queue. Return -1 if queue is empty.


#include<iostream>
using namespace std;

template<typename T>
class queue
{
    T *data;
    int size;
    int capacity;
    int firstIndex;
    int nextIndex;
    public:

    queue()
    {
        capacity= 10;
        size=0;
        data= new T[capacity];
        firstIndex=5;
        nextIndex=5;
    }

    void insertFront(T element)
    {
        if(size== capacity){cout<< "Queue Full!!!" <<endl;return;}
        data[firstIndex]= element;
        if(nextIndex== firstIndex){nextIndex++;}
        firstIndex=(firstIndex-1)%10;
        size++;
    }
    void insertRear(T element)
    {
        if(size== capacity){cout<< "Queue Full!!!" <<endl;return;}
        data[nextIndex]= element;
        if(nextIndex== firstIndex){firstIndex--;}
        nextIndex=(nextIndex+1)%10;
        size++;
    }
    void deleteFront()
    {
        if(size==0){cout<<"Empty Queue" ;return;}
        firstIndex=(firstIndex+1)%10;
        size--;
    }
    void deleteRear()
    {
        if(size==0){cout<<"Empty Queue" ;return;}
        nextIndex=(nextIndex-1)%10;
        size--;
    }
    void print()        //Prints the entire queue
    {
        int n= firstIndex+1;
        for (int i = 0; i < size; i++)
        {
            cout<< data[n] <<" ";
            n=(n+1)%10;
        }
    }

    void getFront(){cout<< data[firstIndex+1] <<endl;}
    void getRear(){cout<< data[nextIndex-1] <<endl;}
};

int main(){

    queue<int> q;
    q.insertFront(10);
    q.insertFront(5);
    q.insertFront(0);
    q.insertRear(15);
    q.insertRear(20);
    q.insertRear(25);
    q.deleteFront();
    q.deleteFront();
    q.deleteFront();
    q.insertRear(30);
    q.insertFront(9);
    q.insertFront(8);
    q.insertFront(7);
    q.print();
    cout <<endl;


    return 0;
}