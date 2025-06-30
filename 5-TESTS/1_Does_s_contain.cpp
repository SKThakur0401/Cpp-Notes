// Chapter TEST
// Problem Statement: Does s contain t ?
// Problem Level: EASY
// Problem Description:
// Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
// Return true or false.
// Do it recursively.
// E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
// Input Format :
// Line 1 : String s
// Line 2 : String t

// Output Format :
// true or false

// Sample Input 1 :
// abchjsgsuohhdhyrikkknddg
// coding

// Sample Output 1 :
// true

// Sample Input 2 :
// abcde
// aeb

// Sample Output 2 :
// false


#include<iostream>
#include<cmath>
using namespace std;
int fi(string s, char ans)
{
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == ans){return i;}
        if(i == n-1  && s[i] != ans){return -1;}
    }
}

bool checker(string si, string ci)
{
    int arr[ci.size()];
    for (int i = 0; i < ci.size(); i++)
    {
        arr[i]= fi(si,ci[i]);
    }
    for (int i = 0; i < ci.size()-1; i++)
    {
        if(arr[i]<arr[i+1]){continue;}
        else if(arr[i]> arr[i+1]){return false;}
    }

    return true;
}

int main(){


    string s= "saumyaKumarThakur";
    string c= "sKTha";

    string si= "abchjssuohhdhyrikkknddg";
    string ci= "coding";
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout<<checker(s,c)<<endl; 
    cout<<checker(si,ci)<<endl; 
    return 0;
}