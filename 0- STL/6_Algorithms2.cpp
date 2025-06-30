#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){ 

    // SWAP

    int a= 6;
    int b= 2;
    swap(a,b);      // can be used to swap any 2 things, even 2 containers!, like stacks, 
                    // linked-lists, queues , vectors, arrays
    cout<< a <<endl;
    


    // REVERSE

    string st= "abcde";
    reverse(st.begin(), st.end());          // now 'st' is reversed and it's new value is = "edcba"
    reverse(st.begin(), st.begin()+2);      // now 'st' is reversed from index 0 to 1, i.e. only e and d are reversed so now value of "st" is "decba"
    cout<< st <<endl;



    // ROTATE

    vector<int>  vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    vi.push_back(5);

    rotate(vi.begin(), vi.begin()+2, vi.end());     // The 1st argument is starting index and 3rd 
                            // argument is ending index for rotation, the argument in the middle is the index till which rotation is supposed to happen, its "vi.begin()+2" here, so index "0 and 1" would be rotated and thrown at the back.

    
    for (int i = 0; i < vi.size(); i++)
    {
        cout<<vi[i]<<" ";
    }
    cout <<endl;
    
    return 0;
}

