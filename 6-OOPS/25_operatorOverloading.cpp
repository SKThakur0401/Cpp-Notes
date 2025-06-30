// "++i"   this is called 'pre-increment' operator
// "i++"   this is called 'post-increment' operator

// i=5;  ++(++i);  now i=7   ....we did nesting of "++" operator....We are going to "overload this operator in this file"  ...note : int i=5;  int j= ++i;  here both i & j have their values ="6"

// TO UNDERSTAND WHY WE USED "fraction& operator++()" INSTEAD OF "fraction operator++()" ON ' LINE:31 '

// Watch OOPS-2 , Operator Overloading-2 video from -> 21:45

// EXPLANATION: When we do "fraction operator++()" this means the return data type is a fraction... and we are returning " *this "  so it means we are returning the same object....but!!! it actually creates a copy of that object (At some other address)...and that is returned!! (bcoz return type is "fraction" and not "&fraction")  .... in case of "&fraction" it returns the same Original object :)


// IN CASE OF PASS BY VALUE-     (fraction operator++())
// so when we do ... " ++f1 " ... then its no problem... but if we do "  ++(++f1) "then it will give same result as" ++f1  "if we don't pass by reference :(  ... .and there's a reason for that...
// when we did "++f1" , it did increment value of "f1" by '1' , but after that it returned a duplicate of "f1" and the second time when "++" happened... it happened on the duplicate... so the actual f1 did not increment the second time!!! that is why no matter how many times u do "  ++(++(++f1))  " ... f1 will be incremented only once!!!!

// IN CASE OF PASS BY REFERENCE-  : THE SAME FRACTION OBJECT IS CALLED EACH TIME... SO ALL INCREMENTS WILL BE REFLECTED :)


#include<iostream>
#include<cmath>
using namespace std;
class fraction
{
    int numerator;
    int denominator;

    public:
    fraction(int n, int d): numerator(n), denominator(d) {}

    fraction& operator++()
    {
        numerator= numerator+ denominator;
        return *this ;
    }

    void print(){cout<<numerator<<" / "<<denominator<<endl;}

};



int main(){

    fraction f1(4,1);
    fraction f3 = ++(++(++f1));
    ++(++f3);
    f1.print();
    f3.print();

    return 0;
}

