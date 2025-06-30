// ---GO THROUGH "FUNCTION OVERLOADING NOTES URSELF" ,SHORT TOPIC, NOT COVERED HERE----

#include<iostream>
using namespace std;


class employee
{
    private:
        int a,b,c;
    public:
        int d,e;
        void setData(int a1,int b1,int c1);
        void getData(){
            cout<<"The value of a is : "<<a<<endl;
            cout<<"The value of b is : "<<b<<endl;
            cout<<"The value of c is : "<<c<<endl;
            cout<<"The value of d is : "<<d<<endl;
            cout<<"The value of e is : "<<e<<endl;
        }
};

int main(){
    

    return 0;
}