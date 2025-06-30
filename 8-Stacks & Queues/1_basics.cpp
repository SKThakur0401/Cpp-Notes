// WE ARE GOING TO MAKE A "CLASS" FOR THE "STACK" DATA-STRUCTURE ...WITH EVERY FOLLOWING FILE...WE ARE GOING TO WRITE A BETTER CODE FOR MAKING THE CLASS "STACK"

#include<iostream>
#include<climits>
using namespace std;

class stackUsingArray
{
    private:
    int* data;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray(int totalsize)
    {
        data = new int[totalsize];
        nextIndex=0;
        capacity = totalsize;
    }

    int size()
    {
        return nextIndex;
    }
    void push(int element)
    {
        if(nextIndex== capacity){cout<<"Stack full!!"<<endl;  return;}
        data[nextIndex] =element;
        nextIndex++;
    }
    int pop()
    {
        if(nextIndex==0){cout<< "Stack empty!!!" <<endl; return INT_MIN;}
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if(nextIndex==0){cout<< "Stack empty!!!" <<endl; return INT_MIN;}
        return data[nextIndex-1];
    }

    bool isEmpty()
    {
        return nextIndex==0;
    }
};

// NOTE: ALL THESE FUNCTIONS "push,pop,top,size..etc" are of order "1" (O(1)) time complexity!!


int main(){
    stackUsingArray s(5);
    cout<< s.isEmpty() <<endl;
    cout<< s.size() <<endl;
    cout<< s.top() <<endl;
    s.push(10);
    s.push(10);
    s.push(12);
    s.push(14);
    s.push(16);
    s.push(20);
    s.push(24);
    cout<< s.top() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.isEmpty() <<endl;
    cout<< s.size() <<endl;

    return 0;
}

