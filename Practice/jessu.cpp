#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#define ll long long int
using namespace std;


int main(){

    // int d=2;
    // int e=5;
    // cout<< (double)d/e <<endl;
    string s= "110101001010101000110100001011100";
    int charCount=0;
    int oneCount=0;
    // for(char i:s)
    // {
    //     charCount++;
    //     if(i== '1') oneCount++;
    // }

    ll n= 8139172936;
    ll v=1;
    
    for (int i = 0; i < 61; i++)
    {
        if(v & n)
        {
            oneCount++;
        }
        v= (v<<1);
    }
    

    cout<< charCount <<endl;
    cout<< oneCount <<endl;

    return 0;
}

