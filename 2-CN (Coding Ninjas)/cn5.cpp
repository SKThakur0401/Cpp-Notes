#include<iostream>
#include<cmath>
using namespace std;


int main(){

    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0]<<endl;
 
 
    char b[] = "xyz";
    char *c = &b[0];
    cout<< c <<endl;
    c++;

    cout << c << endl;
    c++;
    cout<< c <<endl;
    c++;
    cout<< c <<endl;        //BLANK LINE DUE TO \0
    c++;
    cout<<c<<endl;          //GARBAGE VALUE


    return 0;
}