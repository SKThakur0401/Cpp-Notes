// "this" is a keyword used in OOPS
// "this" is of pointer data-type

// "this" stores the "address of the object" for which the constructor function is called

#include<iostream>
#include<cmath>
using namespace std;
 
class employee
{
    public : 
    int age;
    int eID;

    employee(){}           //NOTE : IT IS IMPORTANT TO WRITE THIS....OTHERWISE WE GET ERROR IF WE CREATE OBJECT WITHOUT ARGUMENT

    employee(int age)
    {
        // age= age;       //NOW , WE KNOW ABOUT LOCAL AND GLOBAL SCOPE...THIS LINE IS USELESS BCOZ IT WILL EQUATE "age" variable of "student constructor function"   (i.e. local )with "itself !!!"
        // to use the actual "age" variable of "employee class" we will take help from "this"
        // since it stores the "address of the object"... (*this).age = age;    will do our job :)

        this -> age = age;      //for e.g. if this constructor is working for "s1" employee... this line is same as s1.age = age;  (where RHS age is age variable of student constructor i.e. local variable) and " s1.age "  u know :)
    }

    employee(int age, int eID)
    {
        this -> age = age;
        this -> eID = eID;
    }

    // "this" makes the code more readable and easy to understand,,, here instead of using two extra variable names "a" and "e" for age and eID ,,, we simply did it using "this" AND USING THE SAME NAMES TO REDUCE CONFUSION AND ENHANCE READABILITY :)
};

int main(){
    
    employee s1;
    employee s2(22,28392);
    employee s3(20);

    cout<< s2.age <<endl;
    cout<< s2.eID <<endl;
    cout<< s3.age <<endl;

    return 0;
}