#include<iostream>
using namespace std;

template <typename T>
class stack
{
    int nextIndex;
    T *data;
    int capacity;

    public:
    stack(int size)
    {
        capacity=size;
        data= new T[size];
        nextIndex=0;
    }
    
    void push(T element)
    {
        if(nextIndex==capacity)
        {
            T* newData= new T[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i]= data[i];
            }
            newData[capacity]= element;
            delete [] data;
            data= newData;
            capacity*=2;
            nextIndex++;
        }
        else
        {
            data[nextIndex]= element;
            nextIndex++;
        }
    }

    int size(){return nextIndex;}
    bool isEmpty(){return nextIndex==0;}
    T top(){return data[nextIndex -1]; }
    T pop()
    {
        nextIndex--;
        return data[nextIndex];
    }
};

int main(){

    stack <char> p1(3);
    p1.push(100);
    p1.push(101);
    p1.push(112);
    p1.push(113);
    p1.push(114);
    p1.push(105);
    p1.push(106);
    p1.push(107);           //NOTE: SINCE THIS IS A "CHARACTER" TYPE STACK... ALL THE NUMBERS ARE AS "ASCII-VALUES"

    cout<< p1.size() <<endl;

    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;
    cout<< p1.pop() <<endl;

    return 0;
}