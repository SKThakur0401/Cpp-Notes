// "Iterator" helps us iterate in a map

// "unordered_set" is similar to "unordered_map" , (it's just that we don't have pairs of keys and values)

// "Iterator" is used for both sets and maps

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;



int main(){
    unordered_map<int,int> ourmap;
    ourmap[1] =1;
    ourmap[4] =2;
    ourmap[9] =3;
    ourmap[16]=4;
    ourmap[25]=5;
    ourmap[36]=6;
    ourmap[49]=7;
    ourmap[64]=8;



    unordered_map<int,int>:: iterator it= ourmap.begin();
    
    while(it != ourmap.end())
    {
        cout<< "KEY : "<< it->first <<endl;
        cout<< "VALUE : "<< it->second <<endl;

        it++;           // Moves the "iterator" to the next pair of the hashmap, NOTE: These 
                        // "hashmap-pairs" are unordered, so they can be returned in any random order   |||--___--|||

        cout <<endl;
    }


    vector<int> v;

    v.push_back(5);
    v.push_back(9);
    v.push_back(11);
    v.push_back(14);
    v.push_back(19);
    v.push_back(23);
    v.push_back(95);


    vector<int>:: iterator it2 = v.begin();

    while(it2 != v.end())
    {
        cout<< *it2 <<endl;
        it2++;
    }


    // When we do " ourmap.find('key') "  it actually returns an 'iterator' pointing to that key :)

    unordered_map<int,int>:: iterator it3 = ourmap.find(int(25));

    // ourmap.erase(it3);      // SO, this "erase function" can also take "address as input!!" ,, so u 
                            // can give both address or key as input to this


    // ourmap.erase(it3, it3 + 4);  // Deletes element at--> it3 , it3+1 , it3+2  ,  it3+3
                                 // Illogical move for 'maps' , but in case of vectors...data is ordered... there this deletion method can prove helpful!
    
    // vector<int>:: iterator it6= v.find(11);

    // v.erase(it6,it6+3);

    // while(it6 != v.end())
    // {
    //     cout<< *it6 <<endl;
    //     it6++;
    // }

    return 0;
}

