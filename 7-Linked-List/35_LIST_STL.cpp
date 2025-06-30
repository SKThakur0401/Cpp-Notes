#include<iostream>
#include<list>          // It is actually a doubly linked list, with both front and back pointers, so inserting elements from either side is O(1) ... but however, just like other "Linked-lists", accessing any random element inside this "list" is O(n)

using namespace std;

// Important functions : l.push_back(), l.push_front(), l.pop_back(), l.pop_front(), l.empty(),     l.size(), l.front(), l.back(), l.clear(l.begin())

int main(){


    list<int> l;

    l.push_back(10);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(10);

    list<int> n(l);     // Copy constructor!, all elements of "l" will be copied to "n"

//  n[2] = 69;          // This is an illegal move, we can't simply access random elements in "LL"

    

    list<int> fk(5);    // this will create a list "fk", and initialise it's size to 5; And all its 
                        // '5' elements will be filled with "0" by default :), now push_front and push_back will insert in front or behind these 5 zeroes :)

    fk.push_front(56);
    fk.push_back(69);

    for(int i: fk)
    {
        cout<< i <<endl;
    }


    list<int> fk2(7, 3);        // This also creates list of size "7", the only difference is all 
                                // its values are initiated with "value=3" and not "value=0" when no second argument given, it is by default "0" like in case of "fk"



    // DELETING ELEMENT

    fk2.erase(fk2.begin());     // Here "erase" has time complexity of "O(n)" ..bcoz it will need 
                                // to go to that element to erase it, and going there takes "O(n)"


    for(int i: fk2)
    {
        cout<< i <<" ";
    }


    return 0;

}

