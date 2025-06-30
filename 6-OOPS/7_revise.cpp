#include<iostream>
#include<cmath>
using namespace std;

class student
{
    public :
    int rollNum;
    int bday;
 
    private :
    int marks;
    string password;

    public: 
    void EnterMarks(int marks)
    {
        cout<< "Enter passcode" <<endl;
        int passcode;
        cin>>passcode;
        if(passcode == 123){this -> marks = marks;}
    }

    void Display()
    {
        cout<< "My marks are : "<<marks <<endl;
        cout<< "My Password is : "<<password <<endl;
    }
    void EnterPassword()
    {
        cout<< "Enter what u want to set as ur password" <<endl;
        string password;
        cin>>password;
        this -> password = password;
    }
    student(){}
    student(int marks, string password){
        this -> marks = marks;
        this -> password = password;
    }
};

int main(){

    student s1;
    s1.EnterMarks(96);

    s1.Display();
    s1.EnterPassword();
    s1.Display();

    student s2(88, "fdjksl");
    s2.Display();

    return 0;
}

// As soon as we create our constructor, the default constructor gets destroyed

// THERE ARE FOUR TYPES OF INBUILT CONSTRUCTORS :
// 1. DEFAULT CONSTRUCTOR (WHICH WE HAVE DONE)
// 2. COPY CONSTRUCTOR
// 3. COPY ASSIGNMENT OPERATOR
// 4. DESTRUCTOR
