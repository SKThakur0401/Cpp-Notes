// A SIMPLE PROGRAM USING OOPS, TO CALCULATE THE SUM OF FRACTION,,, (WE CAN DO ALL OTHER OPERATIONS IN THE SAME WAY)


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

    void add(fraction f2)           //HERE IT WOULD DO "fraction f2 = f2 (of main function)"
                            //INSTEAD WE COULD HAVE WRITTEN "void add(fraction &f2) " , in this way "f2"  would access the real "f2" of the main function.... to add cherry on top, we can do "void add(fraction const & f2)" this way , we can ensure that someone is using the original "f2" , but also he cannot make any changes in ur "f2" :)
                            // THIS IS A VERY DECENT PRACTICE,,, ALWAYS DO IT LIKE THIS...
                            // "void add(fraction const & f2)"
    {
        int lcm = denominator * (f2.denominator);
        int x = (lcm / denominator)* (numerator);
        int y = (lcm / f2.denominator)* (f2.numerator);
        numerator = x+y;
        denominator = lcm;
        simplify();
    }
    
    void print()
    {
        cout<<numerator<<" / "<<denominator<<endl;
    }
};

int main(){
    fraction f1(12,3);
    fraction f2(15,3);
    f1.print();
    f2.print();

    f1.add(f2);         //NOTE : THE ADDED VALUE (I.E. THE SUM WILL BE STORED IN "f1", bcoz we stored the 
                        //numerator and denominator there , in line-> 44 & 45 )
    f1.print();
    f2.print();

    return 0;
}