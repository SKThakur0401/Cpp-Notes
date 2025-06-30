// HERE, WE R GOING TO CREATE QUEUE, SIMILAR TO PREVIOUS QUEUE.. USING ARRAY... BUT THIS TIME WITHOUT SIZE CONSTRAINTS... WE CAN FILL AS MANY ELEMENTS WE WANT

// U HAVE TO KEEP IN MIND SEVERAL VARIABLES WHILE HANDLING THE CASE OF "QUEUE SIZE EXPANSION" ...SO TRY TO BE THOROUGH AND TRY URSELF...

#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
class queue
{
    T* data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;

    public:
    queue(int capacity)
    {
        this->capacity=capacity;
        size=0;
        firstIndex=-1;
        nextIndex= 0;
        data= new T[capacity];
    }

    void enqueue(T element)
    {
        if(size == capacity)
        {                                   // in the "data" array... elements may have been filled in
                                            // "haywire" order...like queue may be starting from 3rd index then 4th then 5th and then suddenly 1st and 2nd.... but we would like to store elements in the new array starting from index "0" and in the linearly ascedning order..(coz our new array has double size.. so technically it wouldn't have formed a circle or this "haywire" if it would have been of that size from the start :)

            T* newData= new T[capacity*2];
            int j=0;                        // to fill elements in new array ... starting from index "0"
            int i= firstIndex;              // to travel in the correct manner in the array "data"
            while(j<capacity)
            {
                newData[j]= data[i];        // so,elements will start filling from "0th" index in new arr
                i=(i+1)%capacity;           // to travel in the correct manner in the array "data"
                j++;
            }
            firstIndex=0;                   // for the new array "newData" this is the first index
            nextIndex=capacity;             // for the new array "newData" this is the last index..for now
            newData[nextIndex] = element;
            capacity*=2;

            nextIndex=(nextIndex+1)%capacity;
            delete [] data;
            data= newData;
            size++;
        }

        else
        {
            data[nextIndex]= element;
            nextIndex= (nextIndex+1)% capacity;
            size++;
            if(firstIndex== -1){firstIndex=0;}
        }
    }

    T dequeue()
    {
        if (size==0)
        {
            cout<< "Queue Empty!!!" <<endl;
            return 0;
        }
        T ans= data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        return ans;
        if (size==0)            // THIS IS NOT AT ALL MANDATORY.... IN THE CASE WHERE QUEUE TURNED 
        {                       // EMPTY... WE R JUST AGAIN PUTTING FIRST INDEX AND NEXT INDEX ON THE POSN
            firstIndex=-1;      // THEY WERE INITIALLY ON..
            nextIndex=0;
        }
    }

    bool empty(){return size==0;}
    T front(){return data[firstIndex];}
    int getSize(){return size;}
};


int main(){

    queue<int> q(5);

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