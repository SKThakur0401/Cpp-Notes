#include<iostream>
#include<cmath>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}  

void increment_ptr(int *p){
    p=p+1;
}

void increment_value(int *p){
    (*p)++;
}
 
int main(){
    cout <<endl;


    int i=10;
    int* j= &i;

    print(j);
    cout<< j <<endl;
    increment_ptr(j);
    cout<< j <<endl;        //NO INCREMENT IN "j" ,BCOZ WE ACTUALLY GAVE A COPY TO "increment_ptr" function,,, and whatever it does to that COPY , IT DOES NOT AFFECT THE REAL ONE.
    print(j);

    cout<< "Value of j before increment_value : "<<*j <<endl;
    increment_value(j);
    cout<< "Value of j after increment_value : "<< *j <<endl;       //HERE, WE ARE NOT CHANGING THE ADDRESS BUT THE VALUE STORED INSIDE THE ADDRESS,,, SO AN OUTSIDE FUNCTION CANNOT AFFECT AN ADDRESS ,,, BUT IT CAN CHANGE THE VALUE STORED IN IT (THE VALUE STORED IN THAT FUNCTION WAS INCREMENTED BY 1)


    /*
        CHIT ANALOGY TO UNDERSTAND THIS ---> THERE ARE TWO PEOPLE, A & B , BOTH HAVE A CHIT OF PAPER IN WHICH AN ADDRESS IS WRITTEN(SAME ADDRESS IS WRITTEN) ,,, NOW IF A MAKE SOME CHANGES IN THAT CHIT OF PAPER , IT WILL NOT AFFECT B IN ANY WAY 
        BUT, IF "A" GOES TO THAT ADDRESS AND MAKE SOME CHANGES THERE,,,, THEREAFTER, IF "B" WILL GO TO THAT SAME ADDRESS, HE WILL OBVIOUSLY SEE THE CHANGES

        SAME THING IS HAPPENING HERE , "A" IS (INCREMENT FUNCTION) AND "B" IS MAIN FUNCTION

    */
    return 0;
}