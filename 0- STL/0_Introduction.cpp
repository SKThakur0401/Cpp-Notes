// STL : stands for Standard Template Library

// Its a set of pre-written code for implementation of various "Data-structures"

// E.g. Vectors, stack, queue, priority_queue, dequeue, unordered_map, unordered_set, Linked-list,etc.... you can create all these data-structures/containers on your own! , but why to create our own if we have a highly optimised code already written for us :)


// NOTE : All these STL data-structures/containers have very similar function names, its done so that it is easy for us to remember them

// STL data structures like "stack" and "queue" are not present here, since they have been thoroughly covered in their separate folder.

// There is a STL called "array", which is not discussed here, since its not useful, its just the array we use, with all the STL functions at our disposal, (it has a fixed size, just like the normal array, so there's no point in studying that)


// COMMONLY USED STL FUNCTIONS.. WHICH ARE APPLICABLE FOR ALMOST ALL DATA-STRUCTURES:

    // IN "STL", we have "iterators" instead of "pointers"
    // "iterator" is basically a "pointer" to the address of some data, so if  "it" is an iterator, then (*it) will return the value it is pointing at

    //  stl.begin() --> gives us the iterator of the beginning index of Data-structure.
    //  stl.end() --> gives us the iterator of the index just ahead  of the ending index of Data-structure.

    // 
    // e.g.  vector<int> v;
    // e.g.  vector<int>:: iterator it= v.begin();
    // e.g.  while(it != v.end()){ cout<< *it <<endl;   it++;}

    // The above code prints each and every element in vector "v", bcoz v.end() points at one index ahead of the last element in vector, that is the only reason it was able to print all element :)

    // vector<int> v(5);        // Initialising size of vector... now this vector has size 5, and there are 5 elements stored in vector which are equal to "0"

    // vector<int> v2(6,1)      // Initialising vector of size "6", but with each element initiated 
                                // with "1" instead of "0"

    // v2.empty()
    // v2.size()

    // v2.top()         // stl.front()      //  stl.back()

    // v2.push_back(69)     // stl.push(69)     // stl.push_front(69)

    // v2.pop_back()        // stl.pop()        // stl.pop_front()


    // stl.erase(stl.begin() , stl.begin()+3)       // Deletes elements at index 0,1,2 in the STL,  
                                                    // (the upper limit is not inclusive in erase, always remember!!)

    // stl.erase(stl.begin(), stl.end())        // since stl.end() points at one index AHEAD of the 
                                                // last element, this will perfectly delete all elements :)

    // NOTE: for some "STLs", 'erase' function does not take 2 parameters

// Apart from these data structures, it also have some "utility algorithms", like "sort", "binary_search" etc


// These STL codes are often more optmised than what we write, so its a good idea to use them


#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"Hii, I am revising C++!!"<<endl;

    vector<int> myVector;

    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);

    vector<int>::iterator myVecIter = myVector.begin();

    // while(myVecIter != myVector.end()){
    //     cout<< *myVecIter <<endl;
    //     myVecIter++;
    // }

    cout<< *myVecIter <<endl;

    // myVecIter.erase(myVecIter.begin(), myVecIter.begin()+2)

    // cout<< myVector.begin() <<endl;

    vector<vector<int> > vii(5, vector<int>(3,7));

    for(int i=0; i< vii.size(); i++){
        for(int j=0; j<vii[i].size(); j++){
            cout<< vii[i][j]<< "  ";
        }
        cout <<endl;
    }

}