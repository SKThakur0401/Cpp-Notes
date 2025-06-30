// COMPILE TIME POLYMORPHISM


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class vehicle
{
    public:
    int maxSpeed;
    int wheelCount;
};

class car: public vehicle{

    public:

    int gearCount;

    car()
    {
        wheelCount=4;
    }
};

int main(){

    car c;

    vehicle *v1= new vehicle;

    vehicle *v2;        // This creates a pointer of the vehicle class pointing at 
                        // some garbage value...

    // NOW NOTE! , pointer of a base class can point to an object of its children class..

    v2= &c;       // This move is legal!!!

    // NOTE: But "v2" can only access those properties of "c" which are also present in 'vehicle' class ... Even if a same-name-function is present in "car" and "vehicle" classes.... v2 will call the function of "vehicle" class and not "car" class :) ... although there is a method to make it call the same-name-function of the child class ... we use "virtual" keyword before function name of parent class... which declares that whether this function will run or the same-name-function in child class will be decided in runtime... further discussed in next file

    vehicle* v5= new car;    // Even this is legal :)

    return 0;
}

