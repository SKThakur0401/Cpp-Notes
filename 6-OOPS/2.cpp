#include<iostream>
#include<cmath>
using namespace std;

 
class employee
{
    public :
    int eID;
    char name[100];
    int year;
    char grades;
};

int main(){

    employee cc1;
    cc1.eID = 8183;
    // cc1.name = 'Saumya';
    cc1.grades = 'B';
    cc1.year= 2;


    cout<< cc1.eID <<endl;
    cout<< cc1.grades <<endl;
    cout<< cc1.year <<endl;

    cout <<endl;

    employee * skt = new employee;

    skt -> eID = 3829;
    skt -> grades = 'A';
    skt -> year = 5;

    cout<< skt -> eID <<endl;
    cout<< skt -> grades <<endl;
    cout<< skt -> year <<endl;

    cout <<endl;

    employee *simp = new employee;

    (*simp).eID = 29832;
    (*simp).grades = 'B';
    (*simp).year = 3;

    cout<< (*simp).eID <<endl;
    cout<< (*simp).grades <<endl;
    cout<< (*simp).year <<endl;


    return 0;

}