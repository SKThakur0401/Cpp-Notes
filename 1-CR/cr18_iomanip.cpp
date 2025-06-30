#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a=4,b=13,c=7843,d=29834;

    cout<<"The value of a without setw is : "<<a<<endl;
    cout<<"The value of b without setw is : "<<b<<endl;
    cout<<"The value of c without setw is : "<<c<<endl;
    cout<<"The value of d without setw is : "<<d<<endl;
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";

 

    cout<<"The value of a with setw is : "<<setw(5)<<a<<endl;   //setw(no. of blank spaces) is a function of "iomanip"
    cout<<"The value of b with setw is : "<<setw(5)<<b<<endl;  //it leaves five blank spaces and then fill them in reverse order.
    cout<<"The value of c with setw is : "<<setw(5)<<c<<endl; //if the integer is greater than 5 digits...then it will flow out...just like in the last case :)
    cout<<"The value of d with setw is : "<<setw(5)<<d<<endl;
    cout<<"The value of d with setw is : "<<setw(5)<<88888888<<endl;
    
}