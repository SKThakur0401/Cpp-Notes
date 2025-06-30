#include<iostream>
#include<cmath>
using namespace std;


#define PI 3.14     //WE COULD HAVE SIMPLY MADE "double pi=3.14" ,,, but this is better bcoz(it has global effect , and no one can ever change it's value by doing "p=p+1" etc... AND IT SIMPLY REPLACES "3.14" AT EVERY INSTANCE YOU CAN SEE "PI" (BEFORE THE COMPILE TIME, MAKING IT VERY EASY ON THE PROCESSOR))
 


int glo=33;         //THIS IS A GLOBAL VARIABLE,,, IT CAN BE USED IN ALL THE FUNCTIONS,,, IN "int" and all the other functions u create ;;; u make changes in this variable in one function ,,, it will reflect those changes in another function (u don't even have to use referencing!) bcoz it's global!!! everyone knows this variable :)


void gloinc(){
    glo++;
}


int main(){
    int x;
    cout<< "Enter radius of ur circle : " <<endl;
    cin>>x;
    cout<<"Area of ur circle is : "<< PI*x*x<<endl;
    cout<<"Perimeter of ur circle is : "<< 2*PI*x<<endl;


    cout<< "Value of glo before inc : "<< glo<<endl;
    gloinc();
    cout<< "Value of glo after inc : "<< glo<<endl;

    return 0;
}