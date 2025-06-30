// VECTORS ARE QUITE SIMILAR TO "STACK USING ARRAYS" .... IT HAS "push_back" and "pop_back" function performing similar functions

// ITS SIMILAR TO AN ARRAY... BAS SIZE NAHI DAALNA PADTA.... SIZE KI TENSION NAHI LENI HOTI...COZ JUST LIKE "DYNAMIC STACKS/QUEUES" IT KEEPS DOUBLING ITS SIZE AFTER IT GETS FILLED UP :)

#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> v;
    v.push_back(10);            // "push_back" means add that elements at the back of the previous element....just like we do in arrays :)
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);


    v.pop_back();               //  DELETES THE LAST ELEMENT U INSERTED
    
    cout<< v[1] <<endl;             // THIS CAN BE USED FOR ACCESSING ELEMENTS :)
    cout<< v[2] <<endl;             // U CAN ALSO USE IT FOR "UPDATING VALUE" AT AN INDEX
    cout<< v[7] <<endl;             // HOWEVER...DON'T USE IT FOR ADDING A NEW ELEMENT...PREFER TO USE PUSH_BACK ONLY .... BCOZ IF THE "VECTOR" HAS REACHED ITS SIZE LIMIT.... ITS SIZE IS SUPPOSED TO BE DOUBLED AND THEN THE NEXT ELEMENT SHOULD BE ADDED...(REMEMBER HOW WE DOUBLED THE SIZE OF ARRAY IN STACKS... ITS THE SAME THING)... if u simply do "v[6] = 69" where (imagine capacity of vector=5)... it will not store it at the address ...and will not be a part of this vector... so always use  "push_back"

    cout<< v.at(1) <<endl;      // ITS THE SAME AS THE THREE LINES ABOVE... INFACT, ITS "SAFER"
    cout<< v.at(2) <<endl;      // IN A VECTOR OF 5 ELEMENTS... IF U ASK FOR THE "7th" index... it will give u error  saying "out_of_range"....... but  if u do ..." v[7] " ... it will throw garbage value at your face...so its better/safer to get an error instead of a garbage value thats why "v.at()"  was created :)
    // cout<< v.at(7) <<endl;


    cout<< "SIZE IS : "<< v.size() <<endl;             // THIS TELLS US ABOUT THE SIZE OF THE VECTOR...IE..HOW MANY ELEMENTS WE HAVE PUT IN...(JUST LIKE SIZE FUNCTION OF STACKS)

    cout<< "CAPACITY IS : "<<v.capacity() <<endl;         //TELLS US ABOUT THE CURRENT CAPACITY OF THE "VECTOR" ...i.e. how many elements it can store ...now, if capacity is big and size is small...u can also use "v[x]" to add element...but when size becomes equal to capacity...the function doubles the capacity :) just like our stack..

    vector<int> sexa;

    // for (int i = 0; i < 100; i++)       // u can see when the size gets equal to the capacity.. the capacity doubles itself
    // {
    //     sexa.push_back(i);
    //     cout<<"Size : "<<sexa.size()<<endl;
    //     cout<<"Cap : "<<sexa.capacity()<<endl;
    // }
    cout <<endl;
    cout <<endl;
    cout <<endl;

    cout<< v.front() <<endl;        // RETURNS THE FIRST ELEMENT..
    cout<< v.back() <<endl;         // RETURNS THE LAST ELEMENT..

    // Here, " v.begin() " gives us the starting "iterator" and " v.end() " gives us the ending iterator

    vector<int>:: iterator it= v.begin();

    while(it!= v.end())
    {
        cout<< *it <<endl;
        it++;
    }

    cout <<endl;
    cout <<endl;

    cout<< *(v.begin()) <<endl;
    cout<< *(v.end()) <<endl;   // This actually points at one index ahead of the last index in 
                                // the vector!!! that's why the above while loop, " while(it != v.end()) "  ended up printing "all the elements" in the vector :) remember this!!

    cout <<endl;

    // Deleting the Vector

    v.clear();          // This clears the vector and makes its size "0", BUT! , THIS DOES NOT MAKE 
                        // ANY CHANGES IN THE CAPACITY!!, SO THE CAPACITY WILL STILL REMAIN "8", (AS IT WAS BEFORE)... SO STILL "8-BYTE" IS ALLOCATED TO THE VECTOR though the nos. stored inside are cleared.... TO OVERCOME THAT!, WE CAN SIMPLY use "shrink_to_fit" function...this will change capacity of vector to its size at that moment!! thus optimising space!

    cout<< v.size() <<endl;
    cout<< v.capacity() <<endl;
    v.shrink_to_fit();          // Changes capacity to its current size

    cout<< v.size() <<endl;
    cout<< v.capacity() <<endl;


    // Note:

    // U can also give size of the vector at the time of initialisation!

    vector<int> a(5);       // Now, this vector "a" is of size "5", and u can directly use a[0],a[1],a[2],a[3],a[4], without any tension! ...It actually filled those five integer spaces with "0" so now if you will use "push_back", it will start inserting from the 6th space and not these initial five blocks!  ,,,, but now!! , don't use "push_back!!" bcoz it will start inserting/pushing-back elements after this "5" alloted space!, so be careful! (vector throws SEGMENTATION FAULT ERROR is done such small mistakes)

    vector<int> b(5,1);     // Here, the second paramenter "1" means that initialise those "5" elements with value=1  instead of value=0    Just that;)


    cout<<endl;
    for(int i :b)           // This is giving warning though
    {                       // This is a way to run "for-loop" on the elements of a vector
        cout<< i <<endl;
    }
    cout <<endl;
    for(int i: a)
    {
        cout<< i <<endl;
    }

    a.erase(a.begin(), a.begin()+2);    // Erases element from index 0,1     (the upper limit in 
                                        // not inclusive remember)
    cout<< a.size() <<endl;

    return 0;
}

