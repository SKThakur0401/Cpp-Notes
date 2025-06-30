#include<iostream>
using namespace std;


int main(){
    int marks[]={9,5,6,7,3,4};      //NOTE,,, HERE IF YOU cout "marks" you will get the address of the first element of the "marks" array
    int *p=marks;                  //THIS SIMPLY STORES THE ADDRESS OF FIRST ELEMENT OF "marks" in "p" ... bcoz marks was anyway a pointer,,, you wouldn't do "&marks"

    //HERE "p" stores the 'address' of first element of marks i.e. = 9 ,,, if we print *p ,,, it will return 9
    //AND IF WE DO *(p+1) it will go to the next element's address and return 5 ,,, note: its an array of integers (and each integer consumes 4 bits (u can revise their sizes from "cr8"))....so the address p+1 will be 4 spots next to p


    cout<<"Address of p is : "<<p<<endl;
    cout<<"Address of p+1 is : "<<p+1<<endl;    //NOTE: IT'S EXACTLY JUST 4 MORE THAN ADDRESS OF "p"
 
 
    cout<<"The value of *p is : "<<*p<<endl;
    cout<<"The value of *(p+1) is : "<<*(p+1)<<endl;
    cout<<"The value of *(p+2) is : "<<*(p+2)<<endl;
    cout<<"The value of *(p+3) is : "<<*(p+3)<<endl;
    cout<<"The value of *(p+4) is : "<<*(p+4)<<endl;


    return 0;
}
