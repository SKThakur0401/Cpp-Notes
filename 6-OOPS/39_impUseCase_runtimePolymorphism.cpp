// This is an example important use case of runtime Polymorphism: a class "Employee" has 4 children classes "HR", "Manager", "Engineer", "other"

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class Employee
{
    public:
    int Salary;

    virtual int getSalary()         // If we write "Virtual" then it will return 
    {                               // salary of engineer i.e. 200000 , else it will return 0
        return 0;                   // So now u can create a "pointer array" of employee class
    }                               // which will store all the employees i.e. HR, Manager, 
                                    // Engineers, etc... and we can get salary of each member of that array using this function :)
};

class HR: public Employee
{
    public:

    HR()
    {
        Salary= 100000;
    }

    int getSalary()
    {
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

    Engineer somu;

    Employee* e= &somu;

    cout<< e->getSalary() <<endl;

    Employee** empArray= new Employee*[10];
    Manager sbj;
    HR shobha;

    empArray[0]= &somu;

    empArray[1]= &sbj;
    empArray[2]= &shobha;

    // and so on...

    cout<<"empArray[1] : " <<empArray[1]->getSalary() <<endl;

    // SO WE CAN USE CLASSES TO STORE VARIOUS TYPES OF DATA IN A SINGLE ARRAY USING THEIR PARENT CLASS!!!

    return 0;
}

