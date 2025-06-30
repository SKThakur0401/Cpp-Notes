#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class student{

    public:

    void print()
    {
        cout<< "I am a student :)" <<endl;
    }
};


class teacher{

    public:

    void print()
    {
        cout<< "I am a teacher :)" <<endl;
    }
};


class TA: public teacher, public student{

    public:
    // Now! TA class has inherited properties of both teacher and student class, but! when we create an object of TA class ... and apply print function on it like...

    // TA somu;
    // somu.print();        // what will it do?? will it use print function of teacher class or student class??      Answer: it will not use print function of any of the two classes and will show error,,, to use "print" function of a specific class u need to use scope resolution!

    // somu.student::print()        // This will use "print" function of 'student' 
                                    // class

    // Now! , if TA class have "print" function of its own then "  somu.print()  " will not give any error and will use "print" function of "TA" class

    void print()
    {
        cout<< "I am a TA XD" <<endl;
    }
};


int main(){

    TA somu;
    // somu.print()             // This will give error! Bcoz it doesn't have a 
                                // print function of its own AND! , both its parents have a print function so it does not know which print function to use :)

    somu.teacher::print();
    somu.student::print();
    somu.print();

    return 0;
}

