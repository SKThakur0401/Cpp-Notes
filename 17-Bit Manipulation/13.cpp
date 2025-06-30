#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int fac(int x)
{
    return (x==1)? 1 : fac(x-1) * x;
}

int main(){


    // // cout<< 27|22;
    // int a=27; int b=22;
    // int c= a^b; cout<< c <<endl;
    cout<< fac(5) <<endl;


    return 0;
}

