// Chapter Assignment
// Problem Statement: Return all codes - String
// Problem Level: HARD
// Problem Description:
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :
// A numeric string 

// Constraints :
// 1 <= Length of String S <= 10

// Sample Input:
// 1123 

// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw


#include<iostream>
#include<cmath>
using namespace std;

void func(string s, string output)
{
    string f = "0abcdefghijklmnopqrstuvwxyz";
    if(s.empty()){cout<<output<<" ";}
    if(s.size()>=2)
    {
        output= output + f[ s[0] - '0'];
        func(s.substr(1), output);
        int x =output.size();
        output= output.substr(0,x-1);

        int ap = (s[0] - '0')*10 + (s[1]- '0');     //simply doing       (s[0]+s[1]) - '0'    will not work bcoz s[0]+s[1] has two characters now,,, which means it is not of character data-type anymore so subtracting '0' will give error :) .... therefore, I separately subtracted '0', from ten's and one's place characters and stored the required number in "ap" :)


        output= output + f[ap];
        func(s.substr(2), output);
        
    }
    if(s.size() ==1)
    {
        output= output + f[s[0]- '0'];
        func(s.substr(1), output);
    }
}


int main(){

    string s;
    cout<<"Enter numeric-string : ";
    cin>>s;
    string output = "";
    func(s, output);
    return 0;
}