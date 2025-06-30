#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
class node
{
    public:
    T data;
    node<T>* next;

    node(T data)
    {
        this->data= data;
        next=NULL;
    }

    ~node()
    {
        delete next;
    }
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
        if(size==0)
        {
            // node<T>* newNode= new node<T>()
            head=new node<T>(element);
            tail=head;
            size++;
        }
        else
        {
            tail->next=new node<T>(element);
            tail=tail->next;
            size++;
        }
    }

    T dequeue()
    {
        if(size==0)
        {
            cout<< "Queue Empty!!!" <<endl;
            return 0;
        }

        else
        {
            node<T>* a= head;
            T ans= a->data;
            head=head->next;
            a->next=NULL;
            delete a;
            size--;
            if(size==0)
            {
                head=NULL;
                tail=NULL;
            }
            return ans;
        }
        
    }


    T front()
    {
        if(head==NULL)
        {
            cout<< "Queue empty!!" <<endl;
            return 0;
        }
        return head->data;
    }

    int getSize() {return size;}
    bool empty() {return size==0;}
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


