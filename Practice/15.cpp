#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


template <typename T>
class myStack
{
    T* data;
    int nextIndex;
    int capacity;

    public:

    myStack()
    {
        data= new T(2);
        capacity=2;
        nextIndex=0;
    }

    int size() {return nextIndex;}
    bool empty() {return nextIndex==0;}

    void pusher(T k)
    {
        if(nextIndex == capacity)
        {
            T* newData= new T[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i]= data[i];
            }

            capacity*=2;
            delete [] data;
            data= newData;
            // delete newData;
        }
        data[nextIndex]= k;
        nextIndex++;
    }

    T top() {return data[nextIndex-1];}

    T pop()
    {
        if(nextIndex==0) return 0;
        nextIndex--;
        return data[nextIndex];
    }

};


int main(){


    myStack<int> st;

    st.pusher(1);
    st.pusher(2);
    st.pusher(3);
    st.pusher(4);
    st.pusher(5);
    st.pusher(6);
    st.pusher(7);
    st.pusher(8);
    st.pusher(9);
    st.pusher(10);
    st.pusher(11);
    st.pusher(12);

    while(!st.empty())
    {
        cout<< st.pop() <<endl;
    }

    return 0;
}

