// DEFAULT CONSTRUCTOR JUST LIKE OTHER CONSTRUCTORS, EXECUTE IMMEDIATELY AFTER AN OBJECT IS MADE.
// "IT FILLS ALL THE PROPERTIES LIKE  age, name , rollNum , eID  with 'GARBAGE VALUE' (IT DOES NOT LEAVE THEM EMPTY!!!) ... AFTER THAT , IF YOU DO s1.age =19 etc... the value gets overwritten

// PARAMETERIZED CONSTRUCTOR ALSO FILLS GARBAGE VALUE FOR AN INSTANT, THEN REPLACE IT WITH THE GIVEN PARAMETERS..... HOWEVER THERE IS A WAY TO PREVENT THE FILLING OF GARBAGE VALUES AND DIRECTLY PUTTING IN THE REQUIRED VALUES

// WE USE "INITIALISATION LIST" TO DO THAT,,,

// student(int a, int rN) : age(a), rollNo(rN) {}

#include<iostream>
#include<cmath>
using namespace std;

class student
{
    public :
    int age;
    int const rollNo;       //now, if u use the default constructor, it will fill garbage value in it, therefore u will get instant error when u create an object

    // so, to stop that , there is only one way, we have to use "parameterized constructor which takes rollNo as one of it's parameter,and to stop the "filling of garbage value" inside this,, WE USE SOMETHING CALLED 'INITIALISATION LIST' so that at the time of creation of object it is filled with the rightful value and no garbage value goes into const int etc

    student(int a, int const ro) : rollNo(ro) , age(a){}        //THIS IS CALLED INITIALISATION LIST, IT HELPS US TO FILL DATA IN CONST (INT/CHAR/STRING) ETC...

    // SYNTAX : its similar to normal parameterized constructor...
    // student(int age, int const admissionNo) : age(age), admissionNo(admissionNo) {this ->c = c; this ->d= d}  however, u cannot use const data-type things within curly braces... it can only be initialized by using initialisation list .... u can have to simply write age(age) ... u don't have to use this-> protocal bcoz it's understood here, :)

    void print(){cout<< "Age : "<<"    "<<"rollNo : "<<rollNo <<endl;}
};


int main(){

    // int const j;    //NOTE: ITS AN ILLEGAL MOVE, BCOZ U CAN'T MAKE A CONSTANT INTEGER WHICH STORES    GARBAGE VALUE!!! ITS USELESS!! SO THIS LINE WILL INSTANTLY GIVE ERROR

    // int & j;         //THIS IS ALSO ILLEGAL, BCOZ U CAN'T CREATE A REFERENCE VARIABLE WITH NO ADDRESS TO REFERENCE TO 

    student s1(19, 8392);
    s1.print();

    return 0;
}
