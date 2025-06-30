// SHALLOW COPYING : IT MEANS COPYING THE ADDRESS, AND THEN PRINTING THE DATA BY USING THAT ADDRESS
// DEEP COPYING    : HERE, WE MAKE AN EXTRA CHARACTER ARRAY AND STORE THE DATA OF THINGS FROM "MAIN" FUNCTION in that array,,, i.e. we are making our own proper copy :) ... which won't be affected, even if the original (in main function) is subjected to changes...


#include<iostream>
#include<cmath>
using namespace std;

class student
{
    int age; 
    char *name;
    public :
    student(int age, char *name)
    {
        this ->age= age;
        // this ->name= name;      //SHALLOW COPYING,This is actually copying the address of "name we enter in main...",,, so now, if we make any change in name of main function....and then call this function,,,then the changes will be reflected here :(  ... We don't want that right? So we should always practice "Deep copying" 

        //  ---DEEP COPYING---
        this -> name = new char[strlen(name) +1];
        strcpy(this -> name,name);      //DEEP COPYING : THIS SHOULD BE PRACTISED, RATHER THAN SHALLOW COPYING

        // SO, NOW IF WE MAKE CHANGES IN "name" of main function and then print s1, the changes will not be reflected in our name :) 
    }

    void print()
    {
        cout<< "Age is : "<<age <<endl;
        cout<< "name is : "<<name <<endl;
    }
};

int main(){


    char name[]= "abcd";
    student s1(19,name);
    s1.print();

    cout <<endl;


    name[3]= 'e';       //SO, NOW THE "name" of main function is changed to "abce" ..but this won't affect
    s1.print();         // the value of "s1" bcoz we used "deep copy" :)


    return 0;
}
