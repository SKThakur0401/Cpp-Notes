// CODE FOR MAKING "QUEUE" USING ARRAYS

#include<iostream>
using namespace std;
template<typename T>
class queue
{
    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    queue(int capacity)
    {
        this->capacity=capacity;
        size=0;
        data=new T[capacity];
        firstIndex= -1;
        nextIndex=  0;
    }
    void enqueue(int element)
    {
        if(size < capacity)
        {
            data[nextIndex]=element;
            nextIndex= (nextIndex+1)%capacity ;
            size++;
            if(firstIndex == -1){firstIndex=0;}
        }
        else
        {
            cout<< "Queue full !!!" <<endl;
        }
    }

    T dequeue()
    {
        if (size ==0)
        {
            cout<< "Queue Empty!!!" <<endl;
            return 0;
        }

        T ans= data[firstIndex];
        size--;
        firstIndex=(firstIndex+1)% (capacity);
        return ans;
    }

    T front()
    {
        if(size== 0)
        {
            cout<< "Queue Empty!!" <<endl;
            return 0;
        }

        return data[firstIndex];
    }

    int getSize(){return size;}

    bool empty(){return size==0;}
};


int main()
{
    queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<< q.front() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;

    cout<< q.getSize() <<endl;
    cout<< q.empty() <<endl;
    return 0;
}