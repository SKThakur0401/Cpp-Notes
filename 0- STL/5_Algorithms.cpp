#include<iostream>
#include<vector>
#include<set>
#include<algorithm>         // This contains various helpful 'algorithms', like 
                            // binary search, sort
using namespace std;


int main(){

    // BINARY SEARCH    NOTE: U NEED TO HAVE A SORTED ARRAY TO USE THIS INBUILT FUNCTION

    vector<int> v;

    v.push_back(5);
    v.push_back(10);
    v.push_back(18);
    v.push_back(25);
    v.push_back(35);
    v.push_back(45);
    v.push_back(55);

    cout<< binary_search(v.begin(), v.end(), 5) <<endl;     // HERE 1ST AND 2ND PARAMETER IS THE RANGE IN WHICH WE HAVE TO SEARCH... AND THIRD PARAMETER IS THE "VALUE", IF THE VALUE IS PRESENT IN THE GIVEN RANGE , IT RETURNS TRUE(1) ELSE FALSE(0)

    cout<< binary_search(v.begin(), v.end(), 19) <<endl;      // since 19 is not present, returns 0
    
    // Now, binary_search can tell whether an element is present or not... but what if we need the address of an element!?

    // We have 2 functions "upper_bound" and "lower_bound", which returns the pointer(in case of arrays) and iterator(in case of vectors)

    // These 2 functions take same parameters as "binary_search"

    // In "lower_bound" the value itself is included, which means, if u call lower_bound on "18", and "18" is present in the vector then it will return the address of "18", however, if 18 is not present, then it will return the immediate greater value present in vector... (so if 18 was not present in our vector.. it would have returned 25 :)

    // In "upper_bound", the value itself is not included, so if we call "upper_bound" on 18, then it will search for immediate larger value than 18!!, which is 25 here, so this will return 25

    // If we had called "upper_bound" on '55', (since its the largest no.), it will return the iterator pointing just ahead of it, which is equal to "v.end()"



    vector<int>:: iterator it= lower_bound(v.begin(), v.end(), 18);

    cout<< *it <<" : lb18"<<endl;

    vector<int>:: iterator lb20 = lower_bound(v.begin(), v.end(), 20);
    vector<int>:: iterator ub25 = upper_bound(v.begin(), v.end(), 25);

    cout<< *lb20<< " : lb20" <<endl;
    cout<< *ub25 << " : ub25"<<endl;

    // NOTE: lower & upper bound functions have "O(logN)" time complexity (SINCE INTERNALLY IT IS USING BINARY SEARCH) for "sorted" containers(array/vector).... and has "O(N)" time complexity if the container is not sorted!! remember this,


    // This concept of lower_bound and upper_bound can also be used for "sets" and "maps" 

    // But! , in case of sets and maps (ordered) , if u try to find upper and lower bound like we did with vectors... it will run in "O(N)" time complexity!!! (Many people get TLE bcoz of this and does not realize why this is happening:) , it is happening bcoz even though sets and maps are sorted, they r running in "O(N)" bcoz internally, it is using "tree-traversal" and NOT "binary search" for finding lower & upper bound

    set<int> s;
    s.insert(4); 
    s.insert(41);
    s.insert(34);
    s.insert(44);

    set<int>:: iterator ix = lower_bound(s.begin(), s.end(), 34);       // Time complexity : O(n)
    set<int>:: iterator ix2= s.lower_bound(34);                        // Time complexity : O(logn)

    // always use this second method--^

    cout<< *ix <<endl;
    cout<< *ix2 <<endl;
    return 0;
}

