// QUEUES USING ARRAY && LL ... THE OPTIMISED CODES ARE WRITTEN HERE FOR REVISION
// IF U DON'T REMEMBER THINGS.. THEN GO TO FILES "8 & 9" ... THE CODES ARE WELL EXPLAINED THERE WITH COMMENTS


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


//              ----------IMPLEMENT QUEUE USING ARRAY--------
template <typename T>
class myQueue_UsingArray
{
    T* data;
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;

    public:

    myQueue_UsingArray()
    {
        capacity=5; size=0;
        data= new T[capacity];
        firstIndex=-1; nextIndex=0;
    }

    void enqueue(T element)
    {
        if(size == capacity)
        {
            T* newData= new T[capacity*2];

            for (int i = 0; i < capacity; i++)
            {
                newData[i]= data[firstIndex];
                firstIndex= (firstIndex+1)%capacity;
            }
            firstIndex=0; nextIndex=size;
            capacity*=2;
            delete [] data;
            data= newData;
        }
        data[nextIndex]= element;
        nextIndex= (nextIndex+1)%capacity;
        size++;
        if(firstIndex== -1) firstIndex=0;
    }

    int Qsize() { return size; }
    bool empty() {return size==0;}

    T front()
    {
        if(firstIndex != -1) return data[firstIndex];
        return INT_MIN;
    }

    T dequeue()
    {
        T returnable = data[firstIndex];
        firstIndex=(firstIndex+1)%capacity; size--;

        if(!size) {firstIndex=-1; nextIndex=0;}       //NOT NECESSARY TO WRITE...

        return returnable;
    }
};




//              ----------IMPLEMENT QUEUE USING LINKED LIST--------

template <typename T>
class node
{
    public:
    T data;
    node<T>* next;

    node(T data)
    {
        this->data = data;
        next= NULL;
    }
};

template <typename T>
class myQueue_UsingLL
{
    node<T>* head;
    node<T>* tail;
    int size;

    public:
    myQueue_UsingLL()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    void enqueue(T element)
    {
        if(head)
        {
            tail->next= new node<T>(element);
            tail=tail->next;
            size++;
        }

        else if(!head)
        {
            node<T>* newNode= new node<T>(element);
            head= newNode;
            tail= newNode;
            size++;
        }
    }

    int Qsize() {return size;}
    bool empty() {return size==0;}

    T front()
    {
        if(head) return head->data;
        return 0;
    }

    T dequeue()
    {
        if(head)
        {
            node<T>* a= head;
            T returnable= a->data;
            head=head->next;
            a->next=NULL;
            delete a;
            size--;
            // if(size == 0) tail=NULL;

            return returnable;
        }
        return 0;
    }
};

int main(){

    myQueue_UsingLL<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);

    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);

    // cout<< q.front() <<endl;

    while(!q.empty())
    {
        cout<< q.front() <<"   size : "<< q.Qsize()<<endl;
        q.dequeue();
    }
    cout <<endl;
    cout <<endl;
    cout <<endl;
    // q.enqueue(1);
    // q.enqueue(1);
    // q.enqueue(1);
    // q.dequeue();
    // q.dequeue();
    // cout<<q.nextIndex<<endl;
    // cout<<q.firstIndex<<endl;

    return 0;
}

