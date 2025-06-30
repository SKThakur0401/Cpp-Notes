// QUESTION : GUESS OUTPUT OF THE CODE BELOW....IF THE CODE GIVE ERROR,,, WHAT IS THE REASON FOR IT ?



#include<iostream>
#include<cmath>
using namespace std;

class Student {
    int rollNumber;

    public :

    int age; 

    Student(int r){
        rollNumber = r;
    }

    int getRollNumber(){
        return rollNumber;
    }

};


int main()
{
    Student s1(101);
    s1.age = 20;

    Student const s2 = s1;
    cout << s2.getRollNumber();
}

