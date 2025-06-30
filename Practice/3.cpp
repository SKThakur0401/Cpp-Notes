#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int hexToDec(string s)
{
    int ans=0; int k=1;
    for(int i= s.size()-1; i >= 0; i--)
    {
        if(s[i] >= 'a' && s[i] <= 'f')
        {
            ans+= (s[i] - 'a' + 10)*k;
            k*=16;
        }
        else
        {
            ans+= ((s[i]- '0'))*k;
            k*=16;
        }
    }
    return ans;
}

int decToBin(int n)
{
    // 7 = 1 + 2 + 4
    string s= "";

    while(n)
    {
        if(n%2) s= '1'+ s;

        else s= '0' + s;

        n/=2;
    }
    return stoi(s);
}

int decToOct(int n)
{
    string s="";
    while(n)
    {
        s= char(n%8 + '0') + s;
        n/=8;
    }

    return stoi(s);
}

string decToHex(int n)
{
    string s="";
    while(n)
    {
        if(n%16 < 10) s= char(n%16 + '0') + s;
        else s= char(n%16 - 10 + 'a') + s;
        n/=16;
    }

    return s;
}

int main(){

    // string s; cin>>s;6

    // int s; cin>>s;

    // // cout<< hexToDec(s) <<endl;
    // // cout<< decToBin(s) <<endl;
    // cout<< decToOct(s) <<endl;
    // cout<< decToHex(s) <<endl;
    

    string s= "abcde";

    s[1]= 'z';
    cout<< s.front() <<endl;
    s.push_back('x');
    cout<< s <<endl;

    string a = "s";
    cout<< a <<endl;

    return 0;
}

