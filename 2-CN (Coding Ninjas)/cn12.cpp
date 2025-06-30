#include<iostream>
#include<cmath>
using namespace std;


int main(){

    char x = 'a';
    char *ptrx = &x;
    int *j = (int*)ptrx;


    cout<< *(j) <<endl;       //IF YOU GUESSED RIGHT, IT WILL NOT ONLY DEREFERENCE THE GIVEN ADDRESS,,, 
                              //BUT ALSO THE 3 FOLLOWING ADDRESSES WHICH RESULTED IN GARBAGE VALUE IN ADDITION TO THE CORRECT ANSWER
                              //SINCE, WE ARE DEREFERENCING AN INTEGER POINTER, IT WILL ALWAYS GIVE AN INTEGER :)

    cout<< &x <<endl;
    cout<<ptrx <<endl;


    char ar[]= "abcdefghijklmnop";   //SINCE, THIS IS A CHAR-ARRAY ,, ALL THESE ALPHABETS ARE STORED IN CONTINUOUS MEMORY LOCATIONS
    char * par= ar;
    int * inpar = (int*)par;

    cout<< *inpar<<endl;            //SINCE, DEREFERENCING AN "INTEGER" , READS 4 CONTINUOUS BITS ,,, IT WILL END UP READING "abcd"
    cout<< *(inpar+1) <<endl;       //DOING +1 TO INTEGER POINTER, TAKES THE POINTER 4-BITS AHEAD (SO THAT IT CAN READ THE NEXT 4 BITS) , IN THIS CASE IT WILL READ ("efgh")
    
    return 0;
}


