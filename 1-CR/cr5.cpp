#include<iostream>
using namespace std;
int main(){

    //  "cout<<a++;"    will print the existing value of "a" but after printing...it will increase the value of "a" by 1.....so if next time you print "a" , u will end up getting "a+1"
    //  "cout<<++a"     will increase the value of "a" by 1 first,,, and then print ....  the printed thing will be "a+1"


    int a=4 , b=5;
    cout<<"(a == b) && (a != b) is equal to : "<<((a==b)&&(a!=b))<<endl;
    cout<<"(a==b) is equal to : "<<(a==b)<<endl;
    cout<<"a++ is equal to : "<<a++<<endl;
    cout<<"a++ is equal to : "<<a++<<endl;
    cout<<"++a is equal to : "<<++a<<endl;
    cout<<"a++ is equal to : "<<a++<<endl;
    cout<<"Now the current value of \'a\' is : "<<a<<endl;
    
}