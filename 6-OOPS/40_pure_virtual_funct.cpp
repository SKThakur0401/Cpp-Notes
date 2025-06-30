// In the previous file, we discussed an example, there we had getSalary() function in the "employee" class also, although it made no sense bcoz salary depends on the type of employee it is... , so we made that function virtual

// We can do something better than that... we can make it "pure virtual function", which means that it is an incomplete function        "   virtual func_dataType funcName()  = 0  "        so instead of putting curly braces, we simply did "  =0  ", now its a "pure virtual function"

// A "pure virtual function" is considered an 'incomplete' function, because it cannot do anything

// IF A CLASS HAS A "PURE-VIRTUAL-FUNCTION" THEN THAT CLASS IS CONSIDERED AN " ABSTRACT CLASS "
// Abstract class: We cannot create an object of this class, it will show error, because an abstract class is considered incomplete class (because it has an incomplete function)... NOW, children classes of this ABSTRACT class, will be ABSTRACT if they do not complete the "pure-virtual-function", so If we create "getSalary" of employee as a "pure-virtual-function", then we must write "getSalary" function (proper function) on all its children classes so they do not turn out to be ABSTRACT too!!




#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;




class Employee                      // This is an abstract class now!, bcoz "getSalary" is 
{                                   // incomplete function
    public:
    int Salary;

    virtual int getSalary()= 0;     // Pure-virtual-function  :)

};


class HR: public Employee       // Now this will become an abstract class!, if we don't complete
{                               // that incomplete function
    public:

    HR()
    {
        Salary= 100000;
    }

    int getSalary()                 // This child class would have been abstract... if we hadn't
    {                               // completed this function
        return Salary;
    }
};



class Manager: public Employee
{
    public:

    Manager()
    {
        Salary= 500000;
    }

    int getSalary()
    {
        return Salary;
    }
};



class Engineer:public Employee
{
    public:

    Engineer()
    {
        Salary= 200000;
    }

    int getSalary()
    {
        return Salary;
    }
};



class Others: public Employee
{
    public:

    Others()
    {
        Salary= 70000;
    }

    int getSalary()
    {
        return Salary;
    }
};



int main(){



    return 0;
}

