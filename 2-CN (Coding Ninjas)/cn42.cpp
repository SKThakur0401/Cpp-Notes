#include<iostream>
#include<cmath>
using namespace std;


int main(){
 
    char a='f';
    char b='g';
    string x= to_string(a);     // It's not beneficial for conversion from "char" to "string" bcoz.....it actually takes in the ASCII value of that character and stores it in string
    cout<< "Somu" + x <<endl;    // It simply added "Somu" + "102" == "Somu102"


    //  TO TURN A SINGLE CHARACTER INTO STRING I USE THE FOLLOWING WAY --


    string s="";    //CREATE AN EMPTY STRING

    char cha = 69;

    s=s+ cha + a+b;        // ALL THESE THINGS WILL BE ADDED AS CHARACTERS AND U WILL GET THE DESIRED RESULTS :)
    cout<< s <<endl;

    char ap= 68;
    cout<< ap <<endl;

    return 0;
}