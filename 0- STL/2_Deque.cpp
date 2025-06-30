// NOTE: ALL THE "STL" ARE VERY SIMILAR LIKE  "VECTOR", "STACK", "QUEUE", "PRIORITY_QUEUE", "DEQUEUE", SO FUNCTIONALITIES HAVE VERY SIMILAR NAMES SO THAT IT'S EASIER FOR US TO REMEMBER!

#include<iostream>
#include<deque>         // It is a doubly sided "queue", where both insertion and deletion is 
using namespace std;    // allowed from both ends


int main(){ 

    deque<int> d;

    d.push_back(10);
    d.push_front(1);
    d.push_front(2);
    d.push_back(100);
    d.push_front(3);

    cout<< d.at(1) <<endl;      // Same as it is in vectors...
    cout<< d[4] <<endl;         // Same as it is in vectors...

    for(int i: d)        // Just a way to use for loop :) , to traverse across elements of a queue,
    {                    // (or for that matter, any STL!!)
        cout<< i <<endl;
    }

    cout<< "Front : "<<d.front() <<endl;        // Returns the element in the front
    cout<< "Back : "<<d.back() <<endl;          // Returns the element in the back

    d.pop_front();
    d.pop_back();

    cout<< "Front : "<<d.front() <<endl;        // Returns the element in the front
    cout<< "Back : "<<d.back() <<endl;          // Returns the element in the back

    cout<< d.size() <<endl;
    cout<< d.__capacity() <<endl;       // Its capacity would be very large since it uses complex method, a large group of arrays is used to store elements

    cout <<endl;
    cout <<endl;
    cout <<endl;

    // USING ITERATORS WITH "DEQUE"

    deque<int>:: iterator it= d.begin();
    while(it != d.end())
    {
        cout<< *it <<endl;
        it++;
    }

    // DELETING OF ELEMENTS

    // here, we have erase function, but!, we have to give range, from where to where you want to delete

    cout<< "Before erasing 1 element :"<<d.size() <<endl;


    d.erase(d.begin(), d.begin()+1);        // This will delete only the first element!, (the second index is not included... "[)"  <--  this kind of bracket thing happening.. that's why  "d.end()" points at one index ahead of the last element!!!, so that when we do                 "d.erase(d.begin(),d.end()) then entire deque gets deleted ")

    cout<< "After erasing 1 element :"<<d.size() <<endl;


    cout<<"Is it empty : " <<d.empty() <<endl;        // returns true(1) if empty, else false(0)

    cout<< "max_size : "<<d.max_size() <<endl;


    return 0;  
}

