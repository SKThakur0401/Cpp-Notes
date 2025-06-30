// LIKE CONSTRUCTOR, THERE IS ALSO "DEFAULT DESTRUCTOR FUNCTION" WHICH RUNS AT THE END OF EXECUTION OF THE MAIN FUNCTION..... HOWEVER WE CAN ALSO EXPLICITLY REDEFINE DESTRUCTOR USING "~student()"  instead of "student()" 
// IT HAS SAME NAME AS OUR CLASS, NO INPUT ARGUMENT & NO RETURN TYPE, THERE CAN ONLY BE "1" DESTRUCTOR...BCOZ IT DOESN'T TAKE ANY ARGUMENTS :)

// JUST LIKE IN CASE OF CONSTRUCTORS... IF WE MAKE OUR OWN DESTRUCTOR..THE DEFAULT DESTRUCTOR WILL NO LONGER BE ACCESSIBLE
#include<iostream>
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

    ~student(){
        cout<< "We called our own destructor!!!" <<endl;
    }

};

#include<iostream>
#include<cmath>
using namespace std;


int main(){

    student s1(23,"somu");
    student s2(83,"jesu");
    student *s3= new student(56,"dhundhun");

    // HOWEVER, WE CREATED 3 VARIABLES, S1 S2 AND S3, BUT DESTRUCTOR OPERATED ONLY TWICE
    // BCOZ THIRD ONE IS STORED IN HEAP SO WE NEED TO USE "delete s3"

    delete s3;      //BCOZ OF THIS LINE, THE DESTRUCTOR WILL BE RUNNING FOR "s3" also :)

    // WHEN PROGRAM COMES TO AN END, DESTRUCTOR DELETES ALL THE OBJECTS, HOWEVER "s3" is not present in the static memory.... so we have to use "delete s3" to delete the heap memory
    return 0;
}

