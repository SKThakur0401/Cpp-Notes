#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;


int main(){


    unordered_map<int,int> um;
    unordered_map<int,int> umt;

    um[2]=4;
    um[3]=5;
    um[4]=6;
    um[5]=7;
    um[6]=8;

    umt = um;

    um[2]= -69;
    um[3]= -69;
    um[4]= -69;
    unordered_map<int,int>:: iterator it= um.begin();

    while(it != um.end())
    {
        cout<< (*it).first<< "  "<< (*it).second <<endl;
        it++;
    }


    return 0;
}

