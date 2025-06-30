// 5 functions : push,pop,top,isEmpty,size

#include<iostream>
#include<climits>
using namespace std;

template <typename T>
class stack
{
    T * data;
    int capacity;
    int nextIndex;

    public:
    stack(int capacity)
    {
        this->capacity= capacity;
        data= new T[capacity];
        nextIndex=0;
    }

    void push(T element)
    {
        if (nextIndex== capacity)
        {
            T* newData= new T[capacity*2];
            for (int i = 0; i < nextIndex; i++)
            {
                newData[i]= data[i];
            }
            delete [] data;
            data= newData;
            data[nextIndex]= element;
            nextIndex++;
            capacity*=2;
        }

        else
        {
            data[nextIndex]=element;
            nextIndex++;
        }
    }

    T pop()
    {
        if (nextIndex==0)
        {
            cout<< "Stack Empty!!";
            return INT_MIN;
        }

        else
        {
            nextIndex--;
            return data[nextIndex];
        }
    }

    bool empty(){return nextIndex==0;}
    T top()
    {
        if(nextIndex==0){cout<< "Stack empty!!!" <<endl;    return INT_MIN;}
        return data[nextIndex-1];
    }
    int size(){return nextIndex;}
};



int main(){

    stack<int> s(3);
    s.push(11);
    s.push(121);
    s.push(1331);
    s.push(222);
    s.push(333);
    s.push(444);
    cout<< s.top() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.size() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    s.push(11);
    s.push(121);
    s.push(1331);
    s.push(222);
    s.push(333);
    s.push(444);
    s.push(11);
    s.push(121);
    s.push(1331);
    s.push(222);
    s.push(333);
    s.push(444);
    s.push(11);
    s.push(121);
    s.push(1331);
    s.push(222);
    s.push(333);
    s.push(444);
    cout<< s.size() <<endl;

    return 0;
}