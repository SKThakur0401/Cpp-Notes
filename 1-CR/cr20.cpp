#include<iostream>
using namespace std;


// SEE NOTES : https://www.codewithharry.com/videos/cpp-tutorials-in-hindi-15

int sum(int a,int b);    //NOTE WE WROTE THIS TO TELL THE COMPUTER THAT THERE IS A FUNCTION NAMED SUM...BCOZ WE WROTE WHAT THE FUNCTION DOES AFTER THE "main" WE NEED TO TYPE THIS TO AVOID ERROR.... we can also type it as

// int sum(int, int);

 
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<"Sum of a and b is : "<<sum(a, b)<<endl;
 
    return 0;
}


int sum(int a, int b){
    int c =a+b;
    return c;
    };