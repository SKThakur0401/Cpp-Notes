#include<iostream>
// #include "Students.cpp"     //THIS IS A PRE-WRITTEN CODED FILE BY ME,,, WHICH CONTAINS THE CLASS "STUDENT" AND IT'S VARIOUS PROPERTIES AND  FUNCTIONS(WHICH CAN BE USED TO MAKE CHANGES TO IT'S VARIOUS PROPERTIES)......

using namespace std;

// IN A CLASS, THERE ARE 3 TYPES OF "ACCESS MODIFIERS"... PRIVATE , PUBLIC AND PROTECTED
// A CLASS IS PRIVATE BY DEFAULT... WHICH MEANS NO ONE OUTSIDE THE CLASS CAN ACCESS IT
// IF YOU WANT SET SOMETHING TO "PUBLIC"..SO THAT YOU CAN USE IT AT OTHER PLACES..YOU NEED TO SET THE "ACCESS MODIFIER" TO PUBLIC 
 
class student{
    // NOW ANYTHING WE WRITE IN THIS CLASS IS "PRIVATE BY DEFAULT "
    
    public :        //I CHANGED THE ADDRESS MODIFIER TO PUBLIC SO,,I CAN USE IT AT OTHER PLACES
    int rollNum;
    int age;
    private :
    char grade;     //Grade is a private data of this class
};

int main(){ 
//  STATIC ALLOCATION;
    int a;          // HERE, "a" is called a variable and "int" is it's data type
    student s1;     // HERE, "s1" is 'similar' to a variable, and is called the "OBJECT" and student is it's "CLASS" (something like the data type) .....U CAN USE THE ANALOGY TO UNDERSTAND THINGS

    student s2,s3,s4;

// Storing Data in "s1" object.... allocated memory
    s1.age = 19;
    s1.rollNum= 55;


//  DYNAMIC ALLOCATION
    int *p = new int[4];    //DYNAMIC ALLOCATION OF AN INTEGER ARRAY


    student *s6 = new student; // SO, A POINTER OF 8-BYTE WILL BE THERE IN STACK, AND EVERY PROPERTY OF THE CLASS, LIKE STUDENT'S AGE,ROLL_NO, GRADES ETC... WILL BE STORED IN THE HEAP

    (*s6).age=18;               //THIS COULD ALSO BE WRITTEN IN A DIFFERENT WAY "s6 -> age = 18"
//  (*s6).rollNum =68;       // "->" it first dereferences the object and then puts a "."

    s6 -> rollNum =68;   //SAME AS THE LINE ABOVE


    return 0;
}


