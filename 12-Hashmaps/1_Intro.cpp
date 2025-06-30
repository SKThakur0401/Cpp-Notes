// Similar to dictionaries in "Python", here we can have our indexes as anything and not just consecutive integers :)

// All keys has to be unique, (although, 2 keys can have same values, but 2 different values cannot have same key, basic mapping....)


// Hashmaps, maps or "Hash-tables" generally mean the same thing...(only slight differences)

// 3 Main functionalities we expect from our "Hashmap" are:
        // 1. insert (key k, value v)
        // 2. get (key k)
        // 3. delete (key k)


// We can implement "Hashmaps" in two ways : 
// 1. Using BST (ordered hashmap) with time complexity O(logn)  for searching, deleting, inserting
// 2. Using STL(built-in unordered_map) with time complexity O(1) !! for searching, deleting, inserting


#include<iostream>
#include<unordered_map>
using namespace std;


int main(){

    unordered_map<string, int> ourmap;
    
    pair<string, int> p("abc",1);

    ourmap.insert(p);

    cout<< ourmap["abc"] <<endl;

    ourmap["def"]= 2;
    ourmap["ghi"]= 3;

    cout<< ourmap["ghi"] <<endl;
    cout<< ourmap["def"] <<endl;
    cout<< ourmap["pqr"] <<endl;    // This line will not give error!! or say "key does not exists"
                                    // Rather, it will create a key "pqr" with default value inside it, the default value is "0"
                                    // This is quite dicey! , even if something does not exists, it creates that thing with default value.... so we can use another output method ' ourmap.at("xyz") '

    cout<< ourmap.at("pqr") <<endl; //Now, this line will not give error bcoz the previous line created "pqr" with default value "0" , so it will simply return "0" bcoz "pqr" key exists now with default value "0"


    // cout<< ourmap.at("xyz") <<endl;         // This will give error "key not found"


    // Best way to access elements


    if(ourmap.count("ghi") >0)          // ourmap.count("key") returns how many times the key has 
                                        // occured, so it will basically return 1 or 0
    {
        cout<< "This is present in our map" <<endl;
    }

    cout<<"Size: "<< ourmap.size() <<endl;

    ourmap.erase("abc");                // Erases/deletes the key

    cout<<"Size: "<< ourmap.size() <<endl;            // Size will be reduced by "1"

    if(ourmap.count("abc") >0)              // Since "abc" has been removed, its count is 0
    {
        cout<< "This is present in our map" <<endl;
    }
    return 0;
}

