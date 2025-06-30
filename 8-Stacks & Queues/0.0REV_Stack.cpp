// STACKS USING ARRAY... THE OPTIMISED CODES ARE WRITTEN HERE FOR REVISION

#include<iostream>
using namespace std;

template <typename T>
class stackUsingArray                 // Stacks Using array (For all data types)
{
    T* data;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray(int size)
    {
        data = new T(size);         // RED ALERT!!! THIS FUNCTION WILL NOT WORK PROPERLY... BCOZ
        capacity=size;              // THIS IS NOT THE RIGHT WAY TO CREATE AN "ARRAY" IN THE DYNAMIC
                                    // MEMORY ... . IT SHOULD HAVE BEEN " data = new T[size] "
                                    // yes, we should have used "rectangular brackets"... and always remember this... it will give wrong outputs for some cases if we write it the way we have written now
        nextIndex=0;
    }
    void push(T element)
    {
        if(nextIndex== capacity)
        {
            T* newT= new T(capacity*2);     // SAME PROBLEM.... SHOULD HAVE USED THE "RECTANGULAR
                                            // BRACKETS"
            for (int i = 0; i < capacity; i++)
            {
                newT[i]= data[i];
            }
            newT[capacity]= element;
            capacity*=2;
            nextIndex++;
            delete [] data;
            data= newT;
        }

        else
        {
            data[nextIndex]= element;
            nextIndex++;
        }
    }

    T top(){return data[nextIndex-1];}
    int getSize(){return nextIndex;}
    bool empty(){return nextIndex==0;}

    T pop()
    {
        if(nextIndex==0){return 0;}
        nextIndex--;
        return data[nextIndex];
    }
};

template <typename T>
class node                            // For stacks using Linked_List
{
    public:
    T data;
    node<T>* next;
    node(T data): data(data){}
};

template <typename T>
class stackUsing_LL                   // Stack using Linked_List... (for all data types)
{
    int size;
    node<T>* head;
    public:
    stackUsing_LL()
    {
        head= NULL;
        size=0;
    }
    void push(T element)
    {
        node<T>* newNode= new node<T>(element);

        if(head== NULL)
        {
            head=newNode;
            size++;
        }
        else
        {
            newNode->next= head;
            head=newNode;
            size++;
        }
    }

    T pop()
    {
        if(head != NULL)
        {
            size--;
            node<T>* a= head;
            T thing_to_return = head->data;
            head=head->next;
            delete [] a;
            return thing_to_return;
        }
        else{return 0;}
    }

    T top(){return head->data;}
    int getSize(){return size;}
    bool empty(){return size==0;}
};

int main()
{
    stackUsing_LL<int> s;       // U CAN TEST BOTH "stackUsingArray" and "stackUsing_LL" class here... all their functions are same... just remember to write parameter( i.e. initialisation size of array... when using "stackUsingArray" after name of object)
    // s.push(70);
    // s.push(75);
    // s.push(80);
    // s.push(85);
    // s.push(71);
    // s.push(81);
    // cout<< s.empty() <<endl;
    // cout<< s.getSize() <<endl;
    // cout <<endl;

    // cout<< s.pop() <<endl;
    // cout<< s.pop() <<endl;
    // cout<< s.pop() <<endl;
    // cout<< s.top() <<endl;
    // cout<< s.top() <<endl;
    // return 0;
    stackUsingArray<int> st(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);
    st.push(12);

    while(!st.empty())
    {
        cout<< st.pop() <<endl;
    }
}