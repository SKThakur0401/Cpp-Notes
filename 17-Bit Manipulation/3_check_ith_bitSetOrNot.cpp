#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void check(int n, int i)
{
    int x=1;
    x = x<<(i-1);

    int z = n & x;
    if(z) cout<< 1 <<endl;
    if(!z) cout<< 0 <<endl;
}


int main(){

    int n = 16;
    int i = 1;

    check(n,i);     // Returns 0 if " ith " bit is 0 and returns 1 if " ith " bit is 1

    return 0;
}

