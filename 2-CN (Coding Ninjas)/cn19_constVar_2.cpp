#include<iostream>
#include<cmath>
using namespace std;


int main(){

    int a=11;
    int b=33;
    int const* pt;     //ACTUALLY, READ IT BACKWARDS ,,, "pt pointer to constant integer"                                           //NOTE::: THIS DOES NOT MEAN "the pointer 'pt' is constant !!!!" ,, IT MEANS "pt" IS POINTING TOWARDS AN INTEGER WHICH IS CONSTANT(ATLEAST FROM IT'S PATH)
    pt= &a;
    pt= &b;            //THIS MOVE IS COMPLETELY LEGAL BCOZ ;; "pt" is not a constant ,,, it can change ,,, however the value it is holding or the address it is pointing cannot have it's value changed through "pt"


    int i=10;
    int j=50;
    int* const p=&i;    //READ IT BACKWARDS AGAIN ,,, "p is a constant pointer to integer" ,,HERE "p" is a constant pointer,,,i.e. it will always point at that address,,, and address stored inside "p" cannot be changed
                        //ALTHOUGH THE VALUE OF INTEGER  "p" IS HOLDING/CONTAINING CAN BE CHANGED THIS TIME :) ,,,BCOZ POINTER IS "CONSTANT" NOT THE VALUE IT IS HOLDING
                        //HERE,, "p" IS A CONSTANT,,, SO IT'S VALUE HAS TO BE ASSIGNED IN THE SAME LINE, OTHERWISE IT WILL GIVE ERROR
                        
    (*p)++;
    cout<< *p <<endl;

//  p=&j;               //ILLEGAL MOVE




//---------------------NEXT----------------------
    int j=50;
    int const * const p2= &j;       //HERE BOTH ARE CONSTANT,,,ADDRESS OF  "p2" CAN'T BE CHANGED AND IT HAS TO POINT TO THAT ADDRESS ONLY ,,, THE VALUE AT THAT ADDRESS CAN'T BE CHANGED EITHER
    
    return 0; 
}