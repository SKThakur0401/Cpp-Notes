// IF WE PUT STATIC-PROPERTY IN THE "PRIVATE" ACCESS AREA ,,, THEN WE CANNOT USE IT DIRECTLY.... WE JUST NEED TO MAKE FUNCTIONS LIKE WE DID FOR NORMAL PRIVATE INTEGERS...


#include<iostream>
#include<cmath>
using namespace std;

class employee
{
    static int eCount;      //THIS TIME, WE ARE MAKING THE STATIC-PROPERTY, A PRIVATE PROPERTY :)

    public :

    int age;
    employee(){eCount++;}

    // since eCount is private this time... let's make a function to access it in main :)

    static void get_eCount()        // NOTE: we wrote "static" before function data-type
    {                               // so that this function can now belong to the
        cout<< eCount <<endl;       // entire class and not just all the objects...
                                    // so you can access this function using " employee::get_eCount()"  instead of just using it with objects like (e1,e2), 
                                    // you can also use it with objects ofcourse like we do normally
                                    // "e1.get_eCount()"

                                    // in similar way we used "static int eCount", to make eCount belong to the entire class.. so that we can use it like 
                                    //  "class_name::variableName"
    }

};

int employee :: eCount =0;

int main(){


    employee a1;
    employee b1;
    employee c1;
    employee d1;

    // cout<< employee :: eCount <<endl;        //THIS LINE WILL GIVE ERROR... BCOZ 'eCount' IS A PRIVATE PROPERTY NOW !!!  U CAN'T ACCESS IT

    // cout<< a1.eCount <<endl;         //SAME REASON, COZ IT'S A PRIVATE PROPERTY, U CAN'T ACCESS IT
    // cout<< b1.eCount <<endl;         // LIKE THIS
    // cout<< c1.eCount <<endl;
    // cout<< d1.eCount <<endl;

    // To access a private property,, we know we need to use functions which are public properties

    employee :: get_eCount();       //since, this is void data type.. we don't put "cout"


    a1.get_eCount();
    b1.get_eCount();
    c1.get_eCount();
    d1.get_eCount();

    return 0;
}