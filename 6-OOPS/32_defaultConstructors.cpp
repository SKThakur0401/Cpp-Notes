// Here we see how creating and object of a child class is different...(in short : a child class before calling its own constructor... calls the constructor of its parent class)

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class vehicle
{
    private:
    int maxSpeed;

    protected:

    public:

    vehicle()
    {
        cout<< "Default constructor call of Vehicle class" <<endl;
    }


    ~vehicle()
    {
        cout<< "Default destructor call of Vehicle class" <<endl;
    }

};

class Car: public vehicle
{
    private:

    protected:

    public:

    Car()
    {
        cout<< "Default constructor call of Car class" <<endl;
    }


    ~Car()
    {
        cout<< "Default destructor call of Car class" <<endl;
    }
    
};

class hondaCity: public Car
{
    private:

    protected:

    public:


    hondaCity()
    {
        cout<< "Default constructor call of hondaCity class" <<endl;
    }


    ~hondaCity()
    {
        cout<< "Default destructor call of hondaCity class" <<endl;
    }
    
};


int main(){

    hondaCity myCar;

    // So, when we call a constructor of a child class.... say, 'C' class is child of 'B' class, and 'B' class is child of 'A' class ... so when we create an object of 'C' class... before running its own constructor... it will run the constructor of "B" class... & "B" class also.. before running its own constructor will run constructor of "A" class.... so first constructor of "A" class will be called then "B" and then "C"



    

    // Here, when we write this code for constructor --v

    hondaCity(){

    }


    // whats happening is --v

    hondaCity() : Vehicle(){        // this is actually initialisation list... here Vehicle     
                                    // class constructor is being called... now this happens implicitly :) , so its not a problem even if we dont write it :)
                                    // BUT!! If we want to create a parameterised constructor of some other class then we need to explicitly write it like this :)

                                    // hondaCity(int x) : Vehicle(int x){
                                    // }

                                    // OR
                                    // hondaCity(int x, int y) : Vehicle(int x){
                                    //      int numGears= y
                                    // }
    }

    return 0;
}

