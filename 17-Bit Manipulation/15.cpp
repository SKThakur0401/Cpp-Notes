#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// typename template<T>
class darray
{
    int nextIndex;
    int capacity;
    int* arr;

    public:

    darray()
    {
        nextIndex=0; capacity=5;
        arr= new int[5];
    }

    void insert(int k)
    {
        if(nextIndex == capacity)
        {
            int* newArray = new int[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newArray[i]= arr[i];
            }
            newArray[nextIndex] = k;
            nextIndex++;
            capacity*=2;
            delete [] arr;
            arr= newArray;
        }

        else
        {
            arr[nextIndex] = k;
            nextIndex++;
        }
    }

    void printer() const
    {
        for(int i=0; i<nextIndex; i++)
        {
            cout<< arr[i] <<" ";
        }
        cout <<endl;
    }

    int get(int index) const
    {
        if(index > nextIndex) return -1;

        return arr[index];
    }


    void insert(int index, int k)
    {
        arr[index] = k;
    }

    // CONSTRUCTOR

    darray(darray const & d2)
    {
        this->capacity = d2.capacity;
        this->nextIndex= d2.nextIndex;

        this->arr = new int[d2.capacity];

        for (int i = 0; i < nextIndex; i++)
        {
            this->arr[i] = d2.arr[i];
        }
    }

    void operator=(darray const & d2)
    {
        this->capacity = d2.capacity;
        this->nextIndex= d2.nextIndex;

        this->arr = new int[d2.capacity];

        for (int i = 0; i < nextIndex; i++)
        {
            this->arr[i] = d2.get(i);
        }
    }

    int size()
    {
        return nextIndex;
    }

};


int main(){

    darray *somu = new darray;
    
    somu->insert(10);
    somu->insert(20);
    somu->insert(30);
    somu->insert(40);
    somu->insert(50);
    somu->insert(60);
    somu->insert(60);
    somu->insert(60);
    somu->insert(60);
    somu->insert(60);
    somu->insert(60);
    somu->insert(70);
    somu->insert(6,61);
    somu->insert(7,62);
    somu->insert(8,63);
    somu->insert(9,64);
    somu->insert(10,65);
    somu->insert(11,66);

    somu->printer();
    // cout<< somu->arr[3] <<endl;
    // cout<< somu->size() <<endl;
    // cout<< somu-> <<endl;

    return 0;
}

