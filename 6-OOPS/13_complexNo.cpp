// NOTHING NEW, JUST A PRACTICE PROBLEM SIMILAR TO FRACTION_CLASS,,, WRITE AN OOP PROGRAM FOR ADDITION AND MULTIPLICATION OF COMPLEX NUMBERS

#include<iostream>
#include<cmath>
using namespace std;

class complexNumber
{
    int real;
    int imaginery; 

    public :

    complexNumber(int real, int imaginery)
    {
        this-> real = real;
        this-> imaginery = imaginery;
    }

    void add(complexNumber const & c2)
    { 
        real = real+ c2.real;
        imaginery = imaginery+ c2.imaginery;
    }

    void multiply(complexNumber const & c2)
    {
        int xreal= real*(c2.real) - imaginery*(c2.imaginery);
        int yimaginery = real*(c2.imaginery) + imaginery*(c2.real);

        real= xreal;
        imaginery=yimaginery;
    }

    void print(){cout<< real<<" + "<<imaginery<<"j" <<endl;}
};


int main(){

    complexNumber f1(4,5);
    complexNumber f2(1,2);
    f1.print();
    f2.print();
    // f1.add(f2);
    f1.multiply(f2);

    f1.print();

    return 0;
}