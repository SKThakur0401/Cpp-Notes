// QUESTION : Flip "ith" bit of a number, if the ith bit is 0 then make it 1 and if its 1 then make it 0 ;)


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


// SOLUTION :

// Here we are going to use "XOR gate" , try to understand this thoroughly,

// 1 ^ 1 = 0
// 1 ^ 0 = 1
// 0 ^ 1 = 1
// 1 ^ 1 = 0

// "XOR" of 2 same bits is always "0" and 2 opposite bits is always "1";

// Noticable facts ... "XOR" of any number with 0 will return the number itself!!(Check it urself !)


// Noticable facts ... "XOR" of any number with 1 will return the negation of that number !!(Check it urself !)

// So to flip a no., we can do Bitwise "XOR" of that no. with a no. with ith bit =1 (& rest 0) ... so all rest bits of the original no. will remain same whereas the "ith" bit will be flipped!!

int main(){

    int n; int i;
    cin>>n>>i;

    int z = 1<<i;


    int ans = n ^ z;
    cout<< ans<<endl;

    return 0;
}

