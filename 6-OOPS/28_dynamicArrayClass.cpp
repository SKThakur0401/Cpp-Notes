#include<iostream>
#include<cmath>
using namespace std;

class dynamicArray
{
    int capacity;                       // Note : U can access private members of some other object 
    int *data;                          // of the same class in a class
    int nextIndex;                      // For example, when we created our own copy constructor(line-63), we "dynamicArray const & arr2" , here "arr2" is a different object of the same class, and we can print/ access its properties like "capacity" , "nextIndex", and the entire array here, but we CAN'T ACCESS THOSE THINGS IN THE MAIN FUNCTION    

    public:

    dynamicArray()
    {
        capacity=5;
        data= new int[5];
        nextIndex=0;
    } 
    

    void add(int element)
    {
        if(nextIndex == capacity)
        {
            int *newData = new int[capacity*2];         //REMEMBER THAT "newData is a pointer" ..it will
            for (int i = 0; i < capacity; i++)          // very much stay alive even if we come out of 
            {                                           // this loop or go anywhere...even in main
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity*=2;
        }

        data[nextIndex] =element;
        nextIndex++;
    }

    void printAll()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout<<data[i]<<"  ";
        } 
        cout <<endl;
    }

    int get(int index)              //U give it index... and it will return element at that index
    {
        if(index> nextIndex)
        {return -1;}

        else{return data[index];}
    }

    void replace(int index, int element)      //Inserts the element u give on the index u decide
    {
        data[index] = element;
    }

    // NOW, IF YOU WANT TO USE "COPY CONSTRUCTOR" OR "COPY ASSIGNMENT OPERATOR" ... WE KNOW IT DOES SHALLOW COPY :(   ....SO IF U MAKE CHANGES TO THE COPY ...IT WILL AFFECT THE REAL ONE... THEREFORE, WE R GOING TO USE OUR OWN COPY CONSTRUCTOR AND NOT THE DEFAULT ONE :)

    dynamicArray(dynamicArray const &arr2)
    {
        this->capacity=  arr2.capacity;
        this->data=  arr2.data;
        this->nextIndex=  arr2.nextIndex;

        // this->data = arr2.data ;             //but we know, this is shallow copy and not deep copy :(

        this->data = new int[capacity];
        for (int i = 0; i < arr2.nextIndex; i++)
        {
            this->data[i] = arr2.data[i];
        }
    }


    // NOW, LETS MAKE OUR OWN COPY ASSIGNMENT OPERATOR... NOW, COPY ASSIGNMENT OPERATOR IS CREATED BY OVERLOADING THE "="  SIGN ... SO WE HAVE TO DO THAT ONLY :)  ... bcoz the default one does shallow copy..

    void operator=(dynamicArray const & arr2)
    {
        this->capacity=  arr2.capacity;
        this->data=  arr2.data;
        this->nextIndex=  arr2.nextIndex;

        // this->data = arr2.data ;             //but we know, this is shallow copy and not deep copy :(

        this->data = new int[capacity];
        for (int i = 0; i < arr2.nextIndex; i++)
        {
            this->data[i] = arr2.data[i];
        }
    }

};


int main(){

    dynamicArray arr;

    arr.add(2);
    arr.add(53);
    arr.add(24);
    arr.add(34);
    arr.add(346);
    arr.add(23);
    arr.add(234);
    arr.add(21);
    arr.add(265);

    dynamicArray d2(arr);


    arr.replace(0,100);         //after copying "arr" in "d2" ... we are making changes in "arr"


    d2.printAll();              // THE CHANGES WE MADE IN "arr" is not reflected here!! deep copy worked!
    arr.printAll();             

    // arr.printAll();
    // cout<<arr.get(0)<<endl;     //RETURNS THE SECOND INDEX ELEMENT :)

    d2 = arr;                  //USING OUR OWN 'COPY ASSIGNMENT OPERATOR' .. WE ARE DEEPLY COPYING
    d2.printAll();

    return 0;
}