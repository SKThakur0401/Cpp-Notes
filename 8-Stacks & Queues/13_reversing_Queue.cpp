// QUITE SIMILAR TO REVERSING A "STACK" ...HOWEVER WE R NOT USING THE INBUILT "QUEUE" ..... WE ARE MAKING OUR OWN "QUEUE USING ARRAY(DYNAMIC WITH NO SIZE CONSTRAINTS)" JUST FOR REVISION :)

// OUR QUEUE REVERSING CODE WORKS ACROSS ALL DATA-TYPES...

#include<iostream>
using namespace std;

template <typename T>
class queue
{
    T* data;
    int size;
    int capacity;
    int firstIndex;
    int nextIndex;

    public:
    queue(int capacity)
    {
        this->capacity=capacity;
        size=0;
        firstIndex=-1;
        nextIndex=0;
        data= new T[capacity];
    }

    void enqueue(T element)
    {
        if(size== capacity)
        {
            T* newData= new T[capacity*2];
            int i= firstIndex;
            int j=0;
            while(j< capacity)
            {
                newData[j]=data[i];
                j++;
                i=(i+1)%capacity;
            }
            newData[capacity]=element;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
            nextIndex=(nextIndex+1)%capacity;
            size++;
            delete [] data;
            data= newData;
        }
        else
        {
            data[nextIndex]=element;
            nextIndex=(nextIndex+1)% capacity;
            if(firstIndex== -1){firstIndex=0;}
            size++;
        }
    }

    T dequeue()
    {
        if(size ==0){cout<< "Queue Empty!!!" <<endl; return 0;}

        T ans= data[firstIndex];
        firstIndex=(firstIndex+1)% capacity;
        size--;
        return ans;
    }

    int getSize(){return size;}
    bool empty(){return size==0;}
    T front(){return data[firstIndex];}
};

template <typename T>
queue<T> reverse(queue<T> q)
{
    queue<T> q2(5);

    if (q.getSize()==1)
    {
        return q;
    }
    
    int x = q.dequeue();
    q= reverse<T>(q);
    q.enqueue(x);
    return q;
}

int main(){

    queue<char> q(3);
    q.enqueue(100);
    q.enqueue(101);
    q.enqueue(103);
    q.enqueue(104);

    q= reverse<char>(q);          // THIS FUNCTION IS REVERSING THE QUEUE :)
                                //   INTERESTING :)  , SO WE CAN NOT ONLY USE TEMPLATES WITH "CLASSES" BUT ALSO WITH OUR FUNCTIONS :)

    
    int n = q.getSize();
    for (int i = 0; i < n; i++)
    {
        cout<< q.dequeue() <<endl;
    }

    return 0;
}