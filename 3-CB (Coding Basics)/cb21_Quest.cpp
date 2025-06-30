// FILE- 21 TO 27  CONTAINS QUESTIONS ONLY


// Chapter Assignment
// Problem Statement: Check AB
// Problem Level: MEDIUM
// Problem Description:
// Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'

// If all the rules are followed by the given string, return true otherwise return false.
 

#include<iostream>
#include<cmath>
using namespace std;

bool check2(string s)        // This function works just fine! :) "check1 and check2"  , But the "checker1 & checker2" is an interesting way of solving this where two functions call each other recursively and interchangably!!
{
    if(s.empty()){return true;}

    else if(s[0] == 'a'){return check2(s.substr(1));}
    else if(s.size()== 2 && s.substr(0,2)== "bb"){return true;}
    else if(s.substr(0,3) == "bba"){return check2(s.substr(3));}
    
    else{return false;}
}


bool check1(string s)
{
    if(s[0]== 'a'  && check2(s)) return true;
    return false;
}


// Now, we r going to do using an interesting way which I realised later, we r going to call recursively and interchangably 2 functions, "checker1" and "checker2"
// Here, "checker2" will handle the base case of string starting with "a" i.e. condition-1 , it will also be used when we see 2 consecutive "b's", we should have an "a" after that, so when we see 2 consecutive "b's" , we'll call "checker2", 

// "checker1" will handle the rest of cases

bool checker2(string s);

bool checker1(string s)
{
    if(s.empty()) return true;

    if(s[0]== 'b')
    {
        if(s[1]!= 'b') return false;
        return checker2(s.substr(2));
    }

    if(s[0]== 'a') return checker1(s.substr(1));
}

bool checker2(string s)
{
    if(s.empty()) return true;
    if(s[0] != 'a') return false;

    return checker1(s.substr(1));
}




int main(){

    cout<< "Enter string : ";
    string s;
    cin>>s;
    cout<<check2(s)<<endl;    // we used 2 functions..... check1 and check2.....             "check2" was to meet the 2nd and 3rd condition ... and "check1" was to meet the first condition


    cout<<checker2(s)<<endl;


    return 0;
}