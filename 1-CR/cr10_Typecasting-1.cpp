//     ---TYPECASTING---

#include<iostream>
using namespace std;
int main(){
    int a=45;
    float b=45.46;

    cout<<"Sum of a + b is : "<<a+b<<endl;
    cout<<"Sum of a + int(b) is : "<<a+ int(b)<<endl;    //WE TYPECASTED FLOAT "b" TO INTEGER
    cout<<"Sum of a + (int)b is : "<<a+ (int)b<<endl;    //IS THE SAME THING AS LINE ABOVE....JUST ANOTHER METHOD
    
    int c=46;
    cout<<"a/c is : "<< a/c <<"   #Well both a and c are integer so the answer is given as GIF"<<endl;
    cout<<"a/c actually is : "<< (float)a/c << endl;    //HOWEVER, U CAN'T USE "float(a/c)"......to get the required result......"float(a/c)" will give 0 !!!

}