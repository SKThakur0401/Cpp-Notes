// OVERLOADING "+=" OPERATOR... (TRY URSELF... ITS AN EASY CODE)



    // int i=10;
    // int j=20;
    // (i+=j)+=j;
    // cout<< i <<endl;     //THIS CODE RETURNS "50"!!! , SO NESTING IS ALLOWED IN "+=" OPERATOR
    
    // SO WE MUST KEEP RETURN TYPE OF OUR "+=" OVERLOADER AS THE CLASS NAME AND NOT VOID.... BCOZ VOID WILL PERFORM THE OPERATION FIRST TIME.... BUT IT RETURNS NOTHING...SO IT WILL GIVE ERROR THE INSTANCE IT SEES ANOTHER "+=" SYMBOL

    // SO KEEP RETURN TYPE AS "CLASS_NAME &" ...TO RETURN THE ORIGINAL COPY :)
    // ALL REASONS ARE SAME AS   FILE: "25"
 



#include<iostream>
#include<cmath>
using namespace std;

class number
{
    public:
    int n;

    public:
    number(int n): n(n){}
    void print(){cout<<"The number is : "<<n<<endl;}

    number& operator+=(number n2)
    {
        this->n = n2.n + this->n ;

        return *this;       
    }
};


int main(){


    number n1(24);
    number n2(46);
//  n1+=n2;     // works fine :)

    (n1+=n2)+=n1;         // We kept the return type as "number&" instead of void we could do this!


    n1.print();         //WORKS PERFECTLY FINE :)

    return 0;
}