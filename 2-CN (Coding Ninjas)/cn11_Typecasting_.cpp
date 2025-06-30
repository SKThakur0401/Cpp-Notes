// GENERAL NOTE : WHEN WE MAKE A POINTER, WE HAVE TO WRITE---> (DATA-TYPE)* (VARIABLE) = (VALUE);
//                WE HAVE TO WRITE THAT WHICH DATA-TYPE THE POINTER IS POINTING TO BCOZ,,, SO THAT WHEN
//                WE DEREFERENCE THE POINTER,,, IT WILL KNOW HOW MANY "BITS" IT HAS TO READ ;
//                FOR EXAMPLE, IF WE DEREFERENCE AN INTEGER POINTER, IT WILL KNOW THAT IT HAS TO READ THE
//                "FOUR CONSECUTIVE BITS" STARTING WITH  " &(VARIABLE_NAME) " AND A CHARACTER POINTER WILL READ ONLY ONE BIT WHEN WE DEREFERENCE IT :)

//                  --- TYPECASTING ---


#include<iostream>
#include<cmath>
using namespace std;



int main(){
                            //NOTE: DEREFERENCING A "CHAR" POINTER WILL ALWAYS RETURN A "CHARACTER" ,,, SO IS THE CASE WITH ALL OTHER DATA-TYPES :)

    int i=66;
    int * p=&i;
//  char * pc= p;           //THIS IS CALLED IMPLICIT TYPECASTING,,,THIS WILL GIVE YOU ERROR, BUT THERE IS A WAY TO OVER-RULE THIS ERROR,, WE CAN TELL THE COMPILER TO "EXPLICITLY" DO THIS TASK ,, IN WHICH CASE THE COMPILER WILL SHUT-UP AND DO AS WE TELL
    char *  pc= (char*)p;    //THIS IS SYNTAX FOR EXPLICIT COMMAND   ;;;;    Now, SINCE "pc" is a character pointer, it will read only "1-bit" when we dereference "pc" using "*pc"

    cout<< p <<endl;        //WE KNOW, THIS PRINTS THE ADDRESS OF "i"
    cout<< pc <<endl;       //NOW, THIS IS A 'CHARACTER POINTER' , AND CHARACTER POINTERS GO TO THAT LOCATION, AND START PRINTING EVERYTHING, UNLESS IT FINDS THE "NULL CHARACTER" OR '\0' ....JUST LIKE WE SAW IN CASE OF TRYING TO PRINT ADDRESS OF CHARACTER POINTERS :)
                            //SO, "pc" WILL GO TO THAT ADDRESS , AND SEE THAT THE FIRST BIT IS 66 , BUT UNLIKE "NORMAL CHARACTERS", THERE IS NO '\0' AT THE END, SO IT WILL GO THE NEXT BIT AND SEE THAT IT'S EMPTY!!! SO IT WILL STOP EXECUTION,,, PRINTING ONLY "ASCII (66)  I.e. = "B""



    cout<< *pc <<endl;      
    cout<<*(pc+1)<<endl;  
    cout<< *(pc+2) <<endl;
    cout<< *(pc+3) <<endl;  //THEREFORE,, ALL THE DATA (i.e. NUMBER '66') IS STORED IN THE FIRST "BIT" OF THE FOUR BIT INTEGER VARIABLE "i" ,,, therefore dereferencing (pc+1) or (pc+2) or (pc+3) will not return any value;
                            //WE CALL IT THE "LITTLE ENDIAN SYSTEM",, WHERE THE LEAST SIGNIFICANT BIT(I.e. 66) IN OUR CASE, IS STORED IN THE FIRST ADDRESS OF THE 4-SPACE LONG INTEGER ADDRESS
                            //SOME OTHER DATA TYPES ARE STORED IN "BIG ENDIAN SYSTEM" IN WHICH THE FIRST BIT IS THE MOST SIGNIFICANT BIT #THE OPPOSITE :)




    cout<< "---------------------NEXT QUESTION-------------------" <<endl;
    cout<< "We didn't do the next question here bcoz the \'explicit\' command we gave was destructive,,,now the compiler interpretes char & int differently" <<endl;
    return 0;
}

