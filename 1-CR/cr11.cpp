#include<iostream>
using namespace std;
int main(){

    //   ____HERE WE ARE JUST SEEING HOW MANY BITS EACH DATA-TYPE CONSUME____
    long x1 =2;
    cout<<"Size of long is : "<<sizeof(x1)<<endl;
    short x2=2;
    cout<<"Size of short is : "<<sizeof(x2)<<endl;
    double x3=2;
    cout<<"Size of double is : "<<sizeof(x3)<<endl;
    float x4=2;
    cout<<"Size of float is : "<<sizeof(x4)<<endl;
    int x5=2;
    cout<<"Size of integer is : "<<sizeof(x5)<<endl;
    long long x6=21;
    cout<<"Size of long long is : "<<sizeof(x6)<<endl;

    int a =3;       //HERE WE INITIATED A VARIABLE "a"
    a=40;           //HERE WE REWRITE THE VALUE OF "a" or change the value of "a"
    const int b =5; //HERE WE INITIATE A "CONSTANT VARIABLE "....which means we cannot change the value of "b" ever in this program!!!
    // b=20;           //THIS STEP WILL GIVE ERROR BCOZ IT WAS A CONST VARIABLE


    string s= "Saumya is a good boy";
    cout<<"Subset of s is :"<<(s.substr(1,10))<<endl;
    cout<<"Length of string \'s\' is : "<<s.length()<<endl;
}