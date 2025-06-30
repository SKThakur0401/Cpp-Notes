// ---MATH FUNCTION AND IT'S USES ----

#include<iostream>
#include<cmath>
using namespace std;

// HERE, U HAVE ALL THE FUNCTIONS IN "MATH" MODULE ---> https://www.programiz.com/cpp-programming/library-function/cmath



int main(){
    cout<<sqrt(81)<<endl;
    cout<<round(4.3)<<endl;             //ROUNDS OFF THE NUMBER
    cout<<round(4.8)<<endl;
    cout<<ceil(4.3)<<endl;
    cout<<floor(4.3)<<endl;

    cout<<fmax(10,34)<<endl;            //RETURNS BIGGER NUMBER,,,NOTE IT CAN TAKE ONLY 2 NUMBERS
    cout<<fmin(10,34)<<endl;
    cout<<endl;

    cout<<sin(3.14/2)<<endl;            //SIN OF ANGLE IN RADIAN
    cout<<tan(3.14/2)<<endl;
    // cout<<deg(3.14)<<endl;
    cout<<cbrt(343)<<endl;
    cout<<(abs(2.234) == 2.234)<<endl;
    cout<<copysign(23,-01)<<endl;       //RETURNS FIRST NUM, WITH SIGN OF SECOND NUM,,, NOTE: 0 AND -0 ARE BOTH CONSIDERED POSITIVE NUMBERS :)

    cout<<exp(1)<<endl;
    cout<<exp2(4)<<endl;
    cout<<exp2(2)<<endl;
    cout<< int(22.234) <<endl;
    
    
    cout<< fdim(23,34) <<endl;
    return 0;
}
