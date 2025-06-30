#include<iostream>
#include<cmath>
using namespace std;

class fraction
{
    int numerator;
    int denominator;
 
    public:
    fraction(int n,int d): numerator(n) , denominator(d){}

    void print(){cout<<numerator<<" / "<<denominator<<endl;}

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


    // NOW NEW THINGS AHEAD...

    fraction add(fraction const & f2){       //earlier we did "void add(fraction const &f2)" ....bcoz we 
                                            //did not return anything... we just put the sum of "f1 and f2"  in  "f1".... now our return type is fraction :) so we r gonna return a third fraction
    
        int lcm = denominator * (f2.denominator);
        int x = (lcm / denominator)* (numerator);
        int y = (lcm / f2.denominator)* (f2.numerator);

        fraction fnew(x+y, lcm);        //WE CREATED A NEW FRACTION CLASS..WITH NUME AND DENO AS THE NUMBER EQUAL TO THE SUM OF "F1 AND F2"

        fnew.simplify();             //TO GET "fnew" fraction in its simplest form

        return fnew;        //SO, WE ARE RETURNING A NEW FRACTION CLASS
                            // WE CAN SIMPLY STORE THIS IN AN EMPTY OBJECT... LIKE,    "  fraction f3 = f1.add(f2)  "  , "f3" will hold the sum
    }

    // however, writing f1.add(f2) for a simple addition looks "CREEPY" !!!
    // WHAT IF WE CAN USE SIMPLE OPERATIONS LIKE "f3 = f1+f2"  ??
    // WELL, OPERATORS LIKE "+ - * /"  ARE ONLY PREDEFINED FOR DATATYPES LIKE INT AND DOUBLE.... BUT!!!  WE CAN DO "OPERATOR OVERLOADING !!!"  WE CAN MAKE OUR OWN OPERATORS TO WHATEVER WE WANT !!! :)
    // INSTEAD OF "  fraction add(fraction const & f2)  ".... we have to do  
    //   "  fraction operator+(fraction const &f2)  " ... now "fraction f3 = f1 + f2" will store sum in f3 :)
    // whatever u write after operator... is the overloaded
    // LETS MAKE THE ADDITION CODE USING OPERATOR OVERLOADING...



    fraction operator+(fraction const & f2){    // (same as f1.add(f2) code above.... just using "+" operator)
    
        int lcm = denominator * (f2.denominator);
        int x = (lcm / denominator)* (numerator);
        int y = (lcm / f2.denominator)* (f2.numerator);

        fraction fnew(x+y, lcm);

        fnew.simplify();

        return fnew;                        
    }



    bool operator==(fraction f2)
    {
        return (numerator== f2.numerator  && denominator== f2.denominator);
    }

    // so, we overloaded "==" operator and now it will return bool "1" if both f1 and f2 are exactly equal...and "0" if they are not equal
};


int main(){

    fraction f1(4,2);
    fraction f2(6,2);


    fraction f3 = f1.add(f2);
    fraction f4 = f1+f2;
    f3.print();
    f4.print();         //SO, BOTH F3 AND F4 ARE RETURNING THE SAME VALUE :) ,,BUT "f4" looks more logical to the eyes for an addition operator


    if(f3 == f4) 
    {
        cout<<"Yes!! the two Objects are exactly the same !?! "<<endl;
    }
    else{ cout<< "No, they are not equal" <<endl;}

    return 0;
}

// NOTE: IN ALL THE PLACES WHERE I HAVE CALLED "fraction f2"  as a parameter in a function... I SHOULD HAVE DONE "fraction const & f2"  .... it wouldn't affect the output of my code... but using reference is better to avoid unnecessary creations of duplicates ... coz it doubles space requirement.... now,since we are using our original "f2" using reference variable ... some stupid person can make changes in "f2" which in this case will affect the previously created object "f2".... so we should also put "const" to avoid that.