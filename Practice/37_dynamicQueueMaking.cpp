#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

template <typename T>
class Queue
{
    public:
    T* data;
    int firstIndex;
    int nextIndex;
    int size; int capacity;

    public:

    Queue()
    {
        firstIndex=-1;
        nextIndex=0;
        size=0; capacity=5;
        data= new T[capacity];
    }

    void push(T element)
    {
        if(size== capacity)
        {
            T* newData= new T[capacity*2];

            int j=0; int i= firstIndex;
            while(j<capacity)
            {
                newData[j]= data[i];
                i= (i+1)%capacity;
                j++;
            }
            data= newData;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
        }

        data[nextIndex]= element;
        nextIndex= (nextIndex+1)%capacity;
        size++;
        if(firstIndex==-1) firstIndex=0;
    }

    T pop()
    {
        if(size== 0) {cout<<"empty!!"<<endl; return 0;}

        T ans= data[firstIndex];
        firstIndex= (firstIndex+1)%capacity;
        size--;
        return ans;
    }

    bool empty() {return size==0;}
    int getSize(){return size;}
    T front()
    {
        if(size==0)
        {
            cout<< "Empty!!" <<endl;
            return 0;
        }

        return data[firstIndex];
    }
};

int main(){

    Queue<int> skt;

    skt.push(1);
    skt.push(3);
    skt.pop();
    skt.pop();
    skt.push(5);
    skt.push(7);
    skt.push(9);
    skt.push(9);
    skt.push(9);
    skt.push(9);
    skt.push(9);


    while(!skt.empty())
    {
        cout<< skt.pop() <<" The size now is  "<<skt.size<<endl;
    }

    // cout<< skt.size <<endl;


    return 0;
}
