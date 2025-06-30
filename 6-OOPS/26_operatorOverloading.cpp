// Overloading the "post-increment operator"

// i=5;  (i++)++;   THIS IS NOT ALLOWED!!!! NESTING OF "POST-INCREMENT OPERATOR" WILL GIVE U ERROR!!        note: int i=5; int j= i++;   here, value of "i=6" and value of "j=5"  ... bcoz "i++" will do other operations first, and then increment the value

#include<iostream>
#include<cmath>
using namespace std;

class number
{
    int num;

    public:
 
    number(int n): num(n) {}
    number operator++(int)      //NOTE!!! , WE JUST WRITE "int" within brackets to make it "POST-INCREMENT".... OTHERWISE IT WOULD HAVE BEEN "PRE-INCREMENT"
    {
        number nNew(num);   //SO, WE STORED THE CURRENT VALUE OF "OBJECT" IN  A NEW OBJECT CALLED "nNew"
        num= num+1;         // WE INCREMENT THE VALUE OF ORIGINAL OBJECT BY "1";
        return nNew;        // BUT WE RETURN THE COPY :) ...(WHOSE VALUE WAS NOT INCREMENTED)
    }

    void print(){cout<< num <<endl;}
};


int main(){

    number n1(5);
    number n2= n1++;            // so :) ,,, just like in case of integer... here 'n2' will have "5" and 'n1' will have its value incremented to "6"

    n1.print();
    n2.print();

    
    return 0;
}