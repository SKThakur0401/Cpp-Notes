#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    long double start= 0;
    long double end= 20;
    long double step= 1;

    while(start != end)
    {
        cout<< start <<endl;
        start+=step;
    }

    return 0;
}

