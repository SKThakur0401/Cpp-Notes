#include<iostream>
#include<cmath>
using namespace std;

class student
{
    public :
    int age;
    int rollNum;
 
    student(){}                 //CONSTRUCTOR-1

    student(int age)            //CONSTRUCTOR-2
    {
        this -> age=age;
    }
    student(int age,int rollNum)    //CONSTRUCTOR-3
    { 
        this -> age=age;
        this -> rollNum=rollNum;
    }
};

int main(){

    student s1;         //CONSTRUCTOR-1 WILL BE CALLED
    student s2(12);         //CONSTRUCTOR-2 WILL BE CALLED
    student s3(12,38929);         //CONSTRUCTOR-3 WILL BE CALLED

    student s4(s2);     //COPY CONSTRUCTOR WILL BE CALLED ( AND NOT ANY OF THE ABOVE 3)

    s1= s2;             //THIS IS "COPY ASSIGNMENT OPERATOR", IT'S NOT A CONSTRUCTOR, ITS AN OPERATOR WHICH   COPIES ALL DATA OF "s2" in "s1"  ....EVEN WHEN "s1" might be having some data earlier...that data will be overwritten by data of "s2" ....and "s1" will have the data which is in "s2"

    student s5=s3;      //NOW, THIS IS A SPECIAL CASE , U ARE USING "COPY ASSIGNMENT OPERATOR" ON AN
                        //EMPTY OBJECT...SO IT WILL NOT RUN COPY ASSIGNMENT OPERATOR 
                        //IT WILL RUN "COPY CONSTRUCTOR" !!!! , AND WILL READ IT AS " student s5(s3) "     ....ONLY BCOZ "s5" is an empty object and "copy assignment operator" is for filled object to overwrite their data ...here there is no overwriting but filling of data in the first place into a new object...WHICH IS SAME AS COPY CONSTRUCTOR!!! :)

    student s6;
    s6=s3;          //THIS IS THE SAME AS LINE-34.... WILL DO THE SAME THING :)
    return 0;
}


// NOTE: THE DEFAULT "COPY CONSTRUCTOR" AND "COPY ASSIGNMENT OPERATOR" (WHICH WE ARE USING HERE :) BOTH ALWAYS DO "SHALLOW COPY"