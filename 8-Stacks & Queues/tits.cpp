#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

template <typename T>
class Queue
{
    T* data;
    int fi; int ni;
    int capacity; int size;

    public:

    Queue(int s=5)
    {
        capacity=s;
        size=0;
        fi=-1;
        ni=0;
        data= new T[capacity];
    }

    void push(T element)
    {
        if(size== capacity)
        {
            T* newData= new T[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i]= data[fi];
                fi=(fi+1)%capacity;
            }
            newData[capacity]= element;
            delete [] data;
            data= newData;
            fi=0;
            ni= capacity+1;
            size++;
            capacity*=2;
            return;
        }

        data[ni]= element;
        ni= (ni+1)%capacity;
        if(fi== -1) fi=0;
        size++;
    }

    T pop()
    {
        if(size==-1) return -1;

        T ans= data[fi];
        fi= (fi+1)%capacity;
        size--;
        
        return ans;
    }

    int sizer() {return size;}
    bool empty() {return size==0;}
    T top()
    {
        if(size==0) return -1;
        return data[fi];
    }

    int cap(){return capacity;}
};


int main(){

    Queue<int> q;

    q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(11);
    q.push(13);
    q.push(15);
    q.pop();
    q.pop();
    q.push(11);
    q.push(13);
    q.push(15);

    cout<< q.cap() <<endl;

    while(!q.empty())
    {
        cout<< q.pop() <<endl;
    }

    return 0;
}



