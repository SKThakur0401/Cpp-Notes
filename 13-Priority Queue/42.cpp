#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){


    for (int i = 50; i < 5000; i++)
    {
        if(i%2 != 0 && i%3 !=0 && i%5 !=0 && i % 7 !=0 && i%11 ==0)
        {
            cout<< i <<endl;
        }
    }
    

    return 0;
}

