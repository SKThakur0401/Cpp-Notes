#include<iostream>
#include<cmath>
using namespace std;

class student
{
    int age;
    char *name;

    public :
    student(int age, char * name)
    { 
        this-> age = age;
        this-> name = name;
    }

    void print()
    {
        cout<< "Name : "<<name<<"   age : "<<age <<endl;
    }
};


int main(){

    char name[]="abcd";
    student s1(29,name);
    s1.print();

    name[3]= 'e';
    student s2(18,name);
    s2.print();
    s1.print();             //SO, THE NAME OF "s1" also changed to "abce" !!! bcoz we used shallow copy,,which stored the address of that character array, so when it's value changed in "main" ,, the value we get from going to that address naturally changed,,, and "s1" changed against our will !!!

    // In next file we will do deep copy to avoid this
    return 0;
}