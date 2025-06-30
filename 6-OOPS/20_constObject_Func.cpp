// JUST LIKE "int const x;" ... WE CAN ALSO HAVE "CONSTANT" OBJECTS!!
// INSTEAD OF "fraction f3"... u can also do  "fraction const f3"              //now, this is a constant object of class fraction

// WE, MAKE CONSTANT OBJECT TO ENSURE THAT NO ONE CAN MAKE CHANGES IN THAT PARTICULAR OBJECT, AND EVERYTHING STOERD IN IT IS SAFE :)

// NOW, YOU CANNOT MAKE CHANGES IN ANY OF ITS PROPERTIES!!! (like age, name, rollNo, marks ...etc)

// U CAN USE THE VARIOUS "FUNCTIONS" OF FRACTION / STUDENT /EMPLOYEE (ETC..) CLASS...(WHICH DO NOT MAKE CHANGES IN THESE PROPERTIES) ...... HOWEVER, U HAVE TO WRITE "CONST" AFTER ALL THOSE FUNCTION'S  NAMES...ONLY THEN THEY WILL BE ELIGIBLE FOR USE WITH CONSTANT OBJECTS :)
  
// IF U TRY TO ACT SMART AND WRITE CONSTANT AFTER A FUNCTION WHICH MAKE CHANGES IN IT'S PROPERTIES LIKE MARKS,AGE,NAME ETC...... THEN, THE FUNCTION WILL START EXECUTING,,,, BUT IT WILL GIVE ERROR AT THE VERY INSTANT U TRY TO MAKE CHANGES IN A PROPERTY ::: BCOZ CONSTANT FUNCTIONS CANNOT MAKE CHANGES!!!!


#include<iostream>
#include<cmath>
using namespace std;


class fraction
{
    int numerator;
    int denominator;

    public :

    fraction(int numerator, int denominator)
    {
        this-> numerator = numerator;
        this-> denominator = denominator;
    }
    void simplify()
    {
        int n= min(numerator, denominator);
        int hcf=1;
        for (int i = 1; i <= n; i++)
        {
            if(numerator % i==0 && denominator % i==0)
            {
                hcf=i;
            }
        }

        numerator= numerator/hcf;
        denominator= denominator/hcf;
    }

    void add(fraction f2)       // even if we write const here, its of no use, bcoz it 
                                // will give error the instant we try to change its properties (numerator and denominator)
    {
        int lcm = denominator * (f2.denominator);
        int x = (lcm / denominator)* (numerator);
        int y = (lcm / f2.denominator)* (f2.numerator);
        numerator = x+y;
        denominator = lcm;
        simplify();
    }
    void print()  const             //instead of "void print()" ... 
                                    // we r doing "void print() const" , so that it becomes eligible with constant objects also :)
    {
        cout<<numerator<<" / "<<denominator<<endl;
    }
};


int main(){

    const fraction f1(4,2);
    f1.print();                 //THIS WILL RUN FINE :) ...ONLY BCOZ WE ADDED A CONST AFTER PRINT FUNCTION


    // SO, IT IS A GOOD PRACTICE TO WRITE "CONST"  WHEREVER POSSIBLE,,, SO THAT MORE AND MORE FUNCTIONS LIKE "print" CAN BE ACCESSED BY A CONSTANT OBJECT :)

    return 0;
}
