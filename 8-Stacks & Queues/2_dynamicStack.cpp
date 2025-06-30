#include<iostream>
#include<climits>
using namespace std;

class stack     //this stack can hold infinite no. of elements... we customized the "push" function rest is same....
{
    int *data;
    int capacity;
    int nextIndex;

    public:
    stack(int size)
    {
        capacity= size;
        data= new int[size];
        nextIndex=0;
    }

    int size(){return nextIndex;}
    bool isEmpty(){return nextIndex==0;}
    int pop()
    {
        if(nextIndex==0){cout<< "Stack is empty!!!" <<endl;return INT_MIN ;}
        nextIndex--;
        return data[nextIndex];
    }

    int top(){return data[nextIndex -1];}

    void push(int element)
    {
        if(nextIndex== capacity)
        {
            int *newData = new int[capacity*2];
            for(int i=0;i<capacity;i++)
            {
                newData[i]= data[i];
            }
            newData[capacity]=element;
            nextIndex++;
            delete [] data;
            data= newData;
            capacity*=2;
        }
        else
        {
            data[nextIndex]=element;
            nextIndex++;
        }
    }

};

int main(){

    stack s(3);
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
