// There are two type of sets, "ordered set", and "unordered set"

// Ordered set is implemented using "BST"

// "unordered_set" is implemented just like we created our custom made unordered_map / hashmap

 
// ORDERED "SET" : TIME COMPLEXITIES OF VARIOUS Functions, (u can know this by common sense,)
// insertion is  O(logn)        // Since we r using BST
// deletion  is  O(logn)
// find      is  O(logn)
// count     is  O(logn)

// size        O(1)
// empty       O(1)
// s.begin()   O(1)       // gives us the starting iterator
// s.end()     O(1)

// In case of "unordered_set", it would have been O(1) for all the above operations, but here, we r gonna study "ordered_set" or just "set"

// Elements are stored in "ordered" manner, ascending order (obviously since we r using BST)


#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(50);
    s.insert(390);
    s.insert(30);
    s.insert(40);
    s.insert(40);
    s.insert(40);
    s.insert(10);
    s.insert(10);
    s.insert(10);

    cout<< s.size() <<endl;

    for(int i: s)
    {
        cout<< i <<" ";
    }
    cout <<endl;

    set<int>:: iterator it= s.begin();

    s.erase(s.begin());                         // This deletes the first element
    // s.erase(s.begin(), s.end());             // Deletes the entire set, Can be used for unordered_set also!
    // s.clear()                                // Does the same thing as line above,

    // s.erase(s.begin()+2);                    // This gives error error


    // s.erase(s.begin(), s.begin()+2);         // This gives error, happens in case of several 
                                                // data-structures, "s.begin() + int" in itself is the cause of the error perhaps


    // FIND FUNCTION

    // "s.find(integer_value)" --> returns the address of that 'integer_value', so...
    set<int>:: iterator x = s.find(50);
    // here, "x" will be the iterator pointing at "50"
    

    // Question : How to delete an element from a set?
    // Answer : First find the iterator pointing to that element then call erase func on that, e.g. lets do it for 69

    set<int>::iterator sixtyNine = s.find(69);      // NOTE: This also works for unordered_set
    s.erase(sixtyNine);
    



    for(int i:s)
    {
        cout<< i <<" ";
    }

    // so for example if u wanna delete the second element in "set", u can do the following steps:

    set<int>:: iterator itr= s.begin();      // it is pointing to 1st element

    itr++;       // "it" pointing to second element...

    s.erase(itr);

    // COUNT FUNCTION
    // s.count(enter_value_whose_count_in_set_u_wanna_know)

    cout<< s.count(10) <<endl;      // Since in a set, each value is either present once, or not at all, it does not take multiple instances of the same "value" or integer in our case, so         " s.count(10) " will either return "1"(if element is present) or "0" (if not present)


    cout<< "Value present at x -->"<< *x <<endl;
    return 0;
}
