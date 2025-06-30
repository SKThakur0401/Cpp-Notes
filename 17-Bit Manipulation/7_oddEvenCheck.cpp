#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    int n; cin>>n;

    // Standard (Slower method)

    if(n%2 == 0) cout<< "Even" <<endl;
    if(n%2 == 1) cout<< "Odd" <<endl;


    // Bitwise (Faster method)

    if(n & 1 == 0) cout<< "Even" <<endl;
    if(n & 1 == 1) cout<< "Odd " <<endl;


    // You can also use this method to check divisibility with nos. in "2 ki power something.."

    // if(n & (1<<i) == 0) cout<< "n is divisible by 2^i " <<endl;

    return 0;
}

