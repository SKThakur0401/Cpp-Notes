// QUEUE USING LINKED LIST.... IT'S A VERY EASY CODE :)

#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
class node
{
    public:
    T data;
    node<T>* next;
    node(T element): data(element){}
};

template <typename T>
class queue
{ 
    node<T>* head;
    node<T>* tail;
    int size;

    public:

    queue()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    void enqueue(T element)
    {
        node<T>* newNode = new node<T>(element);
        if (head==NULL)
        {
            head=newNode;
            tail=newNode;
            size++;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
            size++;
        }
    }

    T dequeue()
    {
        if(size==1)
        {
            node<T>* a= head;
            head=NULL;
            tail=NULL;
            delete [] a;
            size--;
            return 0;
        }
        node<T>* a= head;
        head=head->next;
        T ans= a->data;
        delete [] a;
        size--;
        return ans;
    }
    T front(){return head->data;}

    int getSize(){return size;}
    bool empty(){return size==0;}

};

int main(){

    queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);

    cout<< q.front() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;
    cout<< q.dequeue() <<endl;

    cout<< q.getSize() <<endl;
    cout<< q.empty() <<endl;
    
    return 0;
}

