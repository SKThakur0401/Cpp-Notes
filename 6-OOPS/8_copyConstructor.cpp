// IT HELPS US TO COPY THE DATA OF ONE OBJECT TO ANOTHER... FOR EXAMPLE , "S2" HAS SAME AGE AND ROLL NUMBER AS "S1" THEN YOU CAN SIMPLY USE COPY CONSTRUCTOR INSTEAD OF TYPING "S1.AGE = S2.AGE;" ETC... HOWEVER IT COPIES EVERY DATA 



// IN SHORT, READ THE FOLLOWING :)
// student a(b);
// student a(*b);
// student *a= new student(b);
// student *a= new student(*b);
 
#include<iostream>
#include<cmath>
using namespace std;
 
class student
{
    public :
    int age;
    string name;
    student(){}
    student(int age, string name)
    {
        this -> age = age;
        (*this).name = name;            //same as the line above...just a different way
    }

    void display()
    {
        cout<< "Age of student is : "<<age <<endl;
        cout<< "name of student is : "<<name <<endl;
    }
};

int main(){
    student s1(17, "sahaj");
    s1.display();

    student s2(s1);
    s2.display();        //THIS WILL GIVE THE SAME RESULT AS "s1.display" bcoz same data is stored in both

    student *s3 = new student(19, "saumya");        //Dynamically creating an object with parameterized constructors :)

    // now, let's make copy of "s3" in "s4" and "s5"  ... statically and dynamically respectively
    // bcoz "s3" is a pointer, we need to use "*s3" to refer to the object inside

    student s4(*s3);                        //stroing data of "s3" in "s4"

    student *s5 = new student(*s3);         //storing data of "s3" in "s5"

    student *s6 = new student(s1);          //bcoz "s1" is in static memory... we will simply write "s1" and not "*s1"
    s6->display();



// IN SHORT, READ THE FOLLOWING :)
// student a(b);
// student a(*b);
// student *a= new student(b);
// student *a= new student(*b);



    // COPY ASSIGNMENT OPERATOR
    // SIMILAR TO COPY CONSTRUCTOR,,, BUT IT'S USED WHEN BOTH "si1" and "si2" has some values filled and still u want  values of "si1" to be equal to values of "si2", by changing the values of "si2" 
    
    student si1(12,"dhundhun");
    student si2(8,"Munmun");

    si2= si1;           //NOW, "si2" has the same data as "si1" and it's previous data is over written
    si2.display();      //returns same values as "si1"
    return 0;
}

