#include<iostream>
using namespace std;
int c= 45;
int main(){
    int a,b,c;
    cout<<"Enter 1st integer : ";
    cin>>a;
    cout<<"Enter 2nd integer : ";
    cin>>b;
    c=a+b;
    cout<<"The value of c is : "<<(::c)<<endl;  //USING "::c" INSTEAD OF "c" MEANS WE ARE CALLING THE GLOBAL VARIABLE
    cout<<"The value of c is : "<<(c)<<endl;    //HERE WE ARE USING THE LOCAL VARIABLE :)
    return 0;
}
