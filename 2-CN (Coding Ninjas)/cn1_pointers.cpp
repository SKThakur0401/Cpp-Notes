// GENERAL NOTE : WHEN WE MAKE A POINTER, WE HAVE TO WRITE---> (DATA-TYPE)* (VARIABLE) = (VALUE);
//                WE HAVE TO WRITE THAT WHICH DATA-TYPE THE POINTER IS POINTING TO BCOZ,,, SO THAT WHEN
//                WE DEREFERENCE THE POINTER,,, IT WILL KNOW HOW MANY "BITS" IT HAS TO READ ;
//                FOR EXAMPLE, IF WE DEREFERENCE AN INTEGER POINTER, IT WILL KNOW THAT IT HAS TO READ THE
//                "FOUR CONSECUTIVE BITS" STARTING WITH  " &(VARIABLE_NAME) " AND A CHARACTER POINTER WILL READ ONLY ONE BIT WHEN WE DEREFERENCE IT :)
 

#include<iostream>      //IT'S CALLED PRE-PROCESSOR DIRECTIVE
using namespace std;
 

int main(){

                            //SIZE OF A POINTER IS "8-BITS" ,,, EXCEPT IN CASE OF A POINTER WHICH IS HOLDING AN ARRAY (THERE IT DEPENDS ON THE SIZE OF THE ARRAY)
    int i=10;
    cout<<*(&i)<<endl;      //THIS WILL RETURN "i" itself,,, obviously, we are dereferencing the address of i(that is "&i" )

    int* j= &i;
    int**k= &j;
    int ***l=&k;

    cout<< ***l <<endl;
    
    return 0;
}
