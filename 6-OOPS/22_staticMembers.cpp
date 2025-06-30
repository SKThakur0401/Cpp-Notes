//  " :: "  THIS IS CALLED 'SCOPE RESOLUTION OPERATOR'

// STATIC PROPERTY IS A PROPERTY WHICH DO NOT BELONG TO ANY OBJECT BUT TO THE CLASS.....
// STATIC PROPERTY FOR ALL THE OBJECTS WILL BE SAME

// WE CAN ACCESS STATIC PROPERTY BY TYPING :  " cout<<student :: totalStudents <<endl; "   where "student" is the name of the class.... and "totalStudents" is the name of the static property

// WE CAN ALSO PRINT STATIC PROPERTY VALUE BY JUST : "  object_name.static_property  "     e.g. line-43   ,,, just like we do for any other property :)




#include<iostream>
#include<cmath>
using namespace std;

class student
{
    public :
    int age;
    int rollNo;
    static int totalStudents;       // IMP NOTE: writing " static " before the name of a 'variable
                    //   data-type' or before the 'function data-type'... makes that variable or function  belong to the entire class... instead of just a particular 'object' .... so now we can use this variable "totalStudents" as              "  student::totalStudents  " since this variable does not belong to any particular object and is same for all the objects of that class!!, though we can also access it the normal way for objects like (s1, s2, s3 ..etc) like     " s1.totalStudent "  ... the answer will be same for all (s1,s2,s3 or any other object of this class...)

                    // similarly in next folder we will create a function that will belong to the entire class and could be accessed by "class_name::function_name" ... ofcourse, we need to write "static" before data-type of function to make it belong to the entire class...

    student()
    {
        totalStudents++;
    }
    void getTotalStudent(){cout<< totalStudents <<endl;}
};

int student :: totalStudents = 0;       // INITIALISATION OF A STATIC PROPERTY ... (THE STARTING VALUE)



int main(){

    student s1;
    student s2;
    s2.getTotalStudent();               //SINCE WE HAVE MADE ONLY 2 OBJECTS "s1" and "s2" total students=2
    student s3;
    student s4;
    s2.getTotalStudent();               // now we have 4 students s1,s2,s3,s4
    cout<< s3.totalStudents <<endl;     // it does the same thing as line above

    // NOTE : DOESN'T MATTER IF U CALL IT FOR "s1" , "s2" , "s3" or any other object..it is a static property , it is same for all

    cout<< student :: totalStudents <<endl;     // does the same thing as the two line above (this should be the way to print a static property :)
    
    return 0;
}