//      -----REFERENCING AND PASS BY REFERENCE----

#include<iostream>
#include<cmath>
using namespace std;


int main(){

 
    int i=10; 
    int j=i;
    i++;                //NOW " i = 11 "
    cout<< j <<endl;    //OBVIOUSLY j=10 ; i is increased doesn't mean j will too ;;; bcoz j is pointing to a different address whose value is 10;
                        //SAME THING HAPPENED IN "CR-21" SWAP FUNCTION ,,, THE COMPILER INTERPRETS int a & b; of swap function as different from int a and b of main function and there we were basically saying was ----> main.a = swap.a   ;;; so if we later make changes in one, it will definitely not affect the other, just like in case of i & j

                        //BUT WE CAN CREATE "j" in such a way that it will be affected by i ;;; by making the address of "j" also equal to address of "i"
                        //WE CALL IT REFERENCE VARIABLE , LETS STUDY WITH EXAMPLE OF "x and y"

    int x=88;
    int &y= x;          //"int &"   MEANS, CREATE AN INT VARIABLE , BUT DON'T GIVE IT AN ADDRESS!!! ; SO IT WILL SHARE/HAVE THE ADDRESS OF WHAT IT IS EQUAL TO (HERE IT IS "x")
//  int &y;       //NOTE : THIS WILL NOT WORK, YOU ARE ASKING THE COMPILER TO CREATE FOUR SPACE INTEGER, BUT YOU ARE ASKING IT TO NOT ALLOT ANY ADDRESS !!! THIS WILL SHOW ERROR
//  y=x;
    x++;
    cout<< y <<endl;    //SEE, BOTH ARE AFFECTED,,, OBVIOUSLY THIS IS HAPPENING BCOZ THEY ARE POINTING TO THE SAME ADDRESS AND IF THAT VALUE IS CHANGED , IT DID FOR BOTH
                        //IT'S BASICALLY SAYING "EK ADMI KE 2 NAAM HAI , E.G. --> JESU AND SAHAJ" TUM KISI EK KO KUCH KAROGE TOH DONO PE SAME EFFECT HOGA KYUNKI DONO SAME HAI 

    //IT IS USEFUL WHEN WE USE FUNCTIONS ;;; WE CREATE A VARIABLE "a" IN A FUNCTION CALLED "add" , AND WE CREATE THE SAME VARIABLE "a" IN THE MAIN FUNCTION .... NOTE: THEY ARE NOT THE SAME !!! FOR COMPILER THEY ARE TWO DIFFERENT VARIABLES,
    // one is "add.i" and another is "main.i" SO WE CANNOT MAKE CHANGES VARIABLE "a" IN ADD FUNCTION AND EXPECT IT HAPPEN IN MAIN ALSO ;;;; THAT IS WHY THE "SWAP" FUNCTION OF "cr-21" DID NOT WORK .
    // int a and b ; of swap function had different addresses than that of "main a and b"
    // SO WE USED void swap(int &a , int &b) .... which will allot the address of main (a and b) ,, SO NOW THEY ARE SAME, MAIN (a,b) AND SWAP (a,b)


    return 0;
}
