// "Iterator" helps us interate in a map

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


    // unordered_map<int,int>:: iterator it3 = ourmap.find(36);
    unordered_map<int,int>:: iterator it3 = ourmap.begin();


    ourmap.erase(it3, it3 + 2); // Ye line error de rahi hai, agar kewal "ourmap.erase(it3)"           Solution Note: you can only do "it3++" its the only way to move iterators... doing "it3+3" or doing "it=it+5" will give error


    return 0;
}

