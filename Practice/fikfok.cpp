#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){


    string s= "saUMya";

    reverse(s.begin(), s.begin()+4);
    cout<< s <<endl;

    // string small="";
    // string big="";

    // for(int i=0; i< s.size(); i++)
    // {
    //     if(s[i] >= 97) small+=s[i];
    //     else big+=s[i];
    // }

    // cout<< small <<endl;
    // cout<< big <<endl;

    return 0;
}

