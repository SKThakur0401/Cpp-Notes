// Here we try to achieve runtime polymorphism

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class vehicle
{
    public:

    virtual void print(){
        cout<< "This is print function of VEHICLE class" <<endl;
    }
};

class car: public vehicle{

    public:

    void print(){
        cout<< "This is print function of CAR class" <<endl;
    }
};


int main(){

    vehicle *v1= new car;

    v1->print();        // Returns "This is print function of VEHICLE class" if we 
                        // haven't written "virtual" before function name
                        // If we have written "virtual", it says "This is print function of CAR class"  bcoz... writing virtual tells the compiler to decide which function to use at "runtime" and not compile time! , so at runtime computer sees that its actually pointing to a "car" so it uses 'print' function of "car" class :)
                        // So, virtual functions can be used to achieve "runtime polymorphism" & this is example of that


        // So whenever we want the decision of whether parent class function is to be used or child class function to be taken during "runtime", we use "virtual" keyword before function...

        // NOTE: Assume if car class didn't have any print function.... in that case it would have just used the "print" function of "vehicle" class.

    

    return 0;
}

