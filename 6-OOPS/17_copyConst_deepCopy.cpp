// THE COPY CONSTRUCTOR WHICH WE HAVE USED TILL NOW IS THE DEFAULT ONE,,, AND THAT COPY CONSTRUCTOR DOES SHALLOW COPYING.... IN CASE WE NEED THE "COPY CONSTRUCTOR" TO DO DEEP COPY... WE NEED TO MAKE OUR OWN COPY CONSTRUCTOR AND DITCH THE DEFAULT ONE.
// WE CAN MAKE OUR OWN COPY CONSTRUCTOR JUST LIKE WE MAKE "PARAMETERIZED CONSTRUCTORS" FOR 1 OR 2 ARGUMENTS...


#include<iostream>
#include<cmath>
using namespace std;

class student
{
    public : 
    int age;
    char * name; 

    student(int age, char * name)
    {
        this -> age= age;
        this -> name = new char[strlen(name) + 1];              //WE ADD "1" FOR NULL CHARACTER '\0'
        strcpy(this->name, name);
    }

    void print(){cout<<"Name of student : "<<name<<"    age of student : "<<age<<endl;}
};


class employee
{
    public :
    int age;
    char * name;

    employee(int age, char * name)
    {
        this -> age= age;
        this -> name = new char[strlen(name) + 1];              //WE ADD "1" FOR NULL CHARACTER '\0'
        strcpy(this->name, name);
    }

    void print(){cout<<"Name of employee : "<<name<<"    age of employee : "<<age<<endl;}


    // MAKING OUR OWN COPY CONSTRUCTOR (THIS WILL REPLACE THE EXISTING COPY CONSTRUCTOR, WHICH DOES SHALLOW COPY)
    employee(employee &e)
    {
        this ->age = e.age;
        // this ->name = name;             //this is exactly what the default copy constructor do... but we don't have to do that... otherwise changes made to the newly created copy... will also be reflected in the original!!!! (this is shallow copy)

        this ->name = new char[strlen(e.name) +1];
        strcpy(this->name, e.name);
    }
};



int main(){

    char name[]= "abcd";
    student s1(19,name);
    s1.print();

    name[3] = 'e';
    student s2(21,name);
    s2.print();
    s1.print();         //SO THIS TIME, NAME OF "s1" remained intact :)

    // PLAYING WITH COPY-CONSTRUCTOR

    student s3(s1);         //NOW, "s3" will have all the data same as "s1" :)

    s3.name[3] = 'f';       //SO, WE CHANGED THE NAME OF "s3"  TO "abcf" NOW LET'S PRINT s3

    s3.print();             // so, "s3" changed to "abcf" :)
    s1.print();             // "s1" also changed it's name to "abcf" !!!!

    // this happened bcoz of copy constructor!!! .. it does shallow copying (i.e. bcoz name is a char pointer, copy constructor just copied it's address..... so, if s1.name is affected, it will affect    s3.name   and vice-versa, we can't use the default copy constructor here !!!)

    // so, lets make another class employee and use our copy constructor in that :)

    char name2[] = "priya";
    employee e1(69,name2);

    e1.print();

    employee e2(e1);

    e2.name[5]='2';         //SO, WE CHANGED NAME OF "e2" to "priya2" :)

    e2.print();             //SO, ITS NAME CHANGED TO "PRIYA2"
    e1.print();             // AND IT REMAINED "priya" :)  therefore, deep copy worked !!!!

    return 0;
}